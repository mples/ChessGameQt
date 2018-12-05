#include "chessboard.h"
#include <algorithm>
#include "chess_const.h"
#include "king.h"

ChessBoard::ChessBoard() {
    for(int i = 0 ; i < BOARD_SIZE ; ++i) {
            for( int j = 0 ; j < BOARD_SIZE ; ++j) {
                figures_[i][j] = nullptr;
            }
    }
}

void ChessBoard::addFigure(Figure *figure, QPoint& point) {
    if(isValidBoardCoord(point)) {
        Figure* curr_fig = getFigureAt(point);
        if(curr_fig == nullptr) {
            figures_[point.x()][point.y()] = figure;
            if(figure->getSide() == FigureSide::WHITE){
                whiteFigures_.push_back(figure);
            }
            else {
                blackFigures_.push_back(figure);
            }
        }
    }
}

void ChessBoard::addFigure(Figure *figure, int x, int y)
{
    if(isValidBoardCoord(x,y)) {
        Figure* curr_fig = getFigureAt(x,y);
        if(curr_fig == nullptr) {
            figures_[x][y] = figure;
            if(figure->getSide() == FigureSide::WHITE){
                whiteFigures_.push_back(figure);
            }
            else {
                blackFigures_.push_back(figure);
            }
        }
    }
}

bool ChessBoard::isValidBoardCoord(QPoint& point) const {
    return point.x() >= 0 && point.x() < BOARD_SIZE && point.y() >=0 && point.y() < BOARD_SIZE;
}

bool ChessBoard::isValidBoardCoord(int x, int y) const {
    return x >= 0 && x < BOARD_SIZE && y >=0 && y < BOARD_SIZE;
}

Figure *ChessBoard::getFigureAt(QPoint &point) const {
    return figures_[point.x()][point.y()];
}

Figure *ChessBoard::getFigureAt(int x, int y) const {
    return figures_[x][y];
}

void ChessBoard::removeFigureAt(QPoint &point) {
    if(isValidBoardCoord(point)) {
        Figure* curr_fig = getFigureAt(point);
        if(curr_fig != nullptr) {
            removeFromFigureVector(curr_fig);
            delete curr_fig;
            figures_[point.x()][point.y()] = nullptr;

        }
    }
}

bool ChessBoard::moveFromTo(QPoint from, QPoint to) {
    if(isValidBoardCoord(from) && isValidBoardCoord(to)) {
        Figure* attacked = getFigureAt(to);
        Figure* to_move = getFigureAt(from);
        if(to_move != nullptr) {
            figures_[to.x()][to.y()] = to_move;
            figures_[from.x()][from.y()] = nullptr;
            to_move->setBoardPos(to);;
            removeFromFigureVector(attacked);
            if(isKingInCheck(to_move->getSide())){
                figures_[to.x()][to.y()] = attacked;
                figures_[from.x()][from.y()] = to_move;
                to_move->setBoardPos(from);
                addToFigureVector(attacked);
                return false;
            }
            else {
                if(attacked != nullptr) {
                    delete attacked;
                }
                return true;
            }
        }

    }
}

std::vector<QPoint> ChessBoard::getAllPosibleMoves(QPoint& at) {
    if(isValidBoardCoord(at)) {
        Figure* figure = getFigureAt(at);
        if(figure != nullptr) {
            return figure->getPossibleMoves(*this);
        }
    }
}

std::vector<QPoint> ChessBoard::getWhitePosibleMoves() {
    std::vector<QPoint> moves;
    for(Figure * figure : whiteFigures_) {
        std::vector<QPoint> figure_moves = figure->getPossibleMoves(*this);
        moves.insert(moves.end(), figure_moves.begin(), figure_moves.end());
    }
    return moves;
}

std::vector<QPoint> ChessBoard::getBlackPosibleMoves() {
    std::vector<QPoint> moves;
    for(Figure * figure : blackFigures_) {
        std::vector<QPoint> figure_moves = figure->getPossibleMoves(*this);
        moves.insert(moves.end(), figure_moves.begin(), figure_moves.end());
    }
    return moves;
}

bool ChessBoard::isKingInCheck(FigureSide side) {
    std::vector<QPoint> moves ;
    King* king;
    if(side == FigureSide::BLACK) {
        moves = getWhitePosibleMoves();
        for(Figure * figure : blackFigures_) {
            king = dynamic_cast<King*>(figure);
            if(king != nullptr ) {
                break;
            }
        }
    }
    else {
        moves = getBlackPosibleMoves();
        for(Figure * figure : whiteFigures_) {
            king = dynamic_cast<King*>(figure);
            if(king != nullptr ) {
                break;
            }
        }
    }
    for(QPoint point : moves) {
        if(point == king->getBoardPos()) {
            return true;
        }
    }
    return false;
}

std::vector<QPoint> ChessBoard::getSidePosibleMoves(FigureSide side) {
    if(side == FigureSide::WHITE) {
        return getWhitePosibleMoves();
    }
    else {
        return getBlackPosibleMoves();
    }
}

bool ChessBoard::isCheckmate(FigureSide side) {
    std::vector<Figure*>* side_list;
    if(side == FigureSide::WHITE){
        side_list = &whiteFigures_;
    }
    else {
        side_list = &blackFigures_;
    }
    for(Figure* figure : *side_list) {
        std::vector<QPoint> moves = figure->getPossibleMoves(*this);
        for(QPoint point : moves) {
            if(isMovePossible(figure->getBoardPos(), point)){
                return false;
            }
        }

    }
    return true;
}

bool ChessBoard::isMovePossible(QPoint from, QPoint to) {
    if(isValidBoardCoord(from) && isValidBoardCoord(to)) {
        Figure* attacked = getFigureAt(to);
        Figure* to_move = getFigureAt(from);
        if(to_move != nullptr) {
            figures_[to.x()][to.y()] = to_move;
            figures_[from.x()][from.y()] = nullptr;
            to_move->setBoardPos(to);;
            removeFromFigureVector(attacked);
            if(isKingInCheck(to_move->getSide())){
                figures_[to.x()][to.y()] = attacked;
                figures_[from.x()][from.y()] = to_move;
                to_move->setBoardPos(from);
                addToFigureVector(attacked);
                return false;
            }
            else {
                figures_[to.x()][to.y()] = attacked;
                figures_[from.x()][from.y()] = to_move;
                to_move->setBoardPos(from);
                addToFigureVector(attacked);
                return true;
            }
        }

    }
}

void ChessBoard::removeFromFigureVector(Figure *figure) {
    if(figure != nullptr) {
        if(figure->getSide() == FigureSide::WHITE) {
            auto found = std::find(whiteFigures_.begin(), whiteFigures_.end(), figure);
            if(found != whiteFigures_.end()) {
                whiteFigures_.erase(found);
            }
        }
        else {
            auto found = std::find(blackFigures_.begin(), blackFigures_.end(), figure);
            if(found != blackFigures_.end()) {
                blackFigures_.erase(found);
            }
        }

    }
}

void ChessBoard::addToFigureVector(Figure *figure)
{
    if(figure != nullptr) {
        if(figure->getSide() == FigureSide::WHITE) {
            whiteFigures_.push_back(figure);
        }
        else {
            blackFigures_.push_back(figure);
        }

    }
}

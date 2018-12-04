#include "chessboard.h"
#include "chess_const.h"

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
            delete curr_fig;
            figures_[point.x()][point.y()] = nullptr;
        }
    }
}

void ChessBoard::moveFromTo(QPoint from, QPoint to) {
    if(isValidBoardCoord(from) && isValidBoardCoord(to)) {
        Figure* attacked = getFigureAt(to);
        Figure* to_move = getFigureAt(from);
        if(to_move != nullptr) {
            if(attacked != nullptr) {
                removeFigureAt(to);           
            }
            figures_[to.x()][to.y()] = to_move;
            figures_[from.x()][from.y()] = nullptr;
            to_move->setBoardPos(to);
        }

    }
}

std::vector<QPoint> ChessBoard::getAllPosibleMoves(QPoint at) {
    if(isValidBoardCoord(at)) {
        Figure* figure = getFigureAt(at);
        if(figure != nullptr) {
            return figure->getPossibleMoves(*this);
        }
    }
}

#include "knight.h"
#include "chessboard.h"

Knight::Knight(FigureSide s, int x, int y, int size) : Figure(s, x, y, size)
{
    if(side_ == FigureSide::WHITE) {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/w_knight.png").scaled(size, size))  );
    }
    else {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/b_knight.png").scaled(size, size))  );
    }
}

std::vector<QPoint> Knight::getPossibleMoves(const ChessBoard& board) {
    std::vector<QPoint> moves;

    QPoint temp = QPoint(boardPos_.x() + 2, boardPos_.y() + 1);
    if(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp)  != nullptr) {
            Figure * figure = board.getFigureAt(temp) ;
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
        }
        else
            moves.push_back(temp);
    }

    temp = QPoint(boardPos_.x() - 2, boardPos_.y() + 1);
    if(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp)  != nullptr) {
            Figure * figure = board.getFigureAt(temp) ;
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
        }
        else
            moves.push_back(temp);
    }

    temp = QPoint(boardPos_.x() - 2, boardPos_.y() - 1);
    if(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp)  != nullptr) {
            Figure * figure = board.getFigureAt(temp) ;
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
        }
        else
            moves.push_back(temp);
    }

    temp = QPoint(boardPos_.x() + 2, boardPos_.y() - 1);
    if(board.isValidBoardCoord(temp) ) {
        if(board.getFigureAt(temp)  != nullptr) {
            Figure * figure = board.getFigureAt(temp) ;
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
        }
        else
            moves.push_back(temp);
    }


    temp = QPoint(boardPos_.x() + 1, boardPos_.y() + 2);
    if(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp)  != nullptr) {
            Figure * figure = board.getFigureAt(temp) ;
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
        }
        else
            moves.push_back(temp);
    }

    temp = QPoint(boardPos_.x() - 1, boardPos_.y() + 2);
    if(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp)  != nullptr) {
            Figure * figure = board.getFigureAt(temp) ;
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
        }
        else
            moves.push_back(temp);
    }

    temp = QPoint(boardPos_.x() - 1, boardPos_.y() - 2);
    if(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp)  != nullptr) {
            Figure * figure = board.getFigureAt(temp) ;
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
        }
        else
            moves.push_back(temp);
    }

    temp = QPoint(boardPos_.x() + 1, boardPos_.y() - 2);
    if(board.isValidBoardCoord(temp) ) {
        if(board.getFigureAt(temp)  != nullptr) {
            Figure * figure = board.getFigureAt(temp) ;
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
        }
        else
            moves.push_back(temp);
    }
    return moves;
}

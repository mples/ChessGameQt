#include "queen.h"
#include "chessboard.h"

Queen::Queen(FigureSide s, int x, int y, int size) : Figure(s, x, y, size)
{
    if(side_ == FigureSide::WHITE) {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/w_queen.png").scaled(size, size))  );
    }
    else {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/b_queen.png").scaled(size, size))  );
    }
}

std::vector<QPoint> Queen::getPossibleMoves(const ChessBoard& board) {
    std::vector<QPoint> moves;
    QPoint temp = QPoint(boardPos_.x() + 1, boardPos_.y() + 1 );
    while(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp) != nullptr) {
            Figure * figure = board.getFigureAt(temp);
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
            break;
        }
        moves.push_back(temp);
        temp.setX(temp.x() + 1);
        temp.setY(temp.y() + 1);
    }
    temp = QPoint(boardPos_.x() - 1, boardPos_.y() - 1 );

    while(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp) != nullptr) {
            Figure * figure = board.getFigureAt(temp);
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
            break;
        }
        moves.push_back(temp);
        temp.setX(temp.x() - 1);
        temp.setY(temp.y() - 1);
    }

    temp = QPoint(boardPos_.x() - 1, boardPos_.y() + 1 );

    while(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp) != nullptr) {
            Figure * figure = board.getFigureAt(temp);
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
            break;
        }
        moves.push_back(temp);
        temp.setX(temp.x() - 1);
        temp.setY(temp.y() + 1);
    }

    temp = QPoint(boardPos_.x() + 1, boardPos_.y() - 1 );

    while(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp) != nullptr) {
            Figure * figure = board.getFigureAt(temp);
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
            break;
        }
        moves.push_back(temp);
        temp.setX(temp.x() + 1);
        temp.setY(temp.y() - 1);
    }


    temp = QPoint(boardPos_.x() + 1, boardPos_.y()  );
    while(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp) != nullptr) {
            Figure * figure = board.getFigureAt(temp);
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
            break;
        }
        moves.push_back(temp);
        temp.setX(temp.x() + 1);
    }
    temp = QPoint(boardPos_.x() - 1, boardPos_.y()  );

    while(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp) != nullptr) {
            Figure * figure = board.getFigureAt(temp);
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
            break;
        }
        moves.push_back(temp);
        temp.setX(temp.x() - 1);
    }

    temp = QPoint(boardPos_.x(), boardPos_.y() - 1);

    while(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp) != nullptr) {
            Figure * figure = board.getFigureAt(temp);
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
            break;
        }
        moves.push_back(temp);
        temp.setY(temp.y() - 1);
    }

    temp = QPoint(boardPos_.x(), boardPos_.y() + 1);

    while(board.isValidBoardCoord(temp)) {
        if(board.getFigureAt(temp) != nullptr) {
            Figure * figure = board.getFigureAt(temp);
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
            break;
        }
        moves.push_back(temp);
        temp.setY(temp.y() + 1);
    }

    return moves;
}

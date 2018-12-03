#include "knight.h"

Knight::Knight(FigureSide s, int x, int y, int size) : Figure(s, x, y, size)
{
    if(side_ == FigureSide::WHITE) {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/w_knight.png").scaled(size, size))  );
    }
    else {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/b_knight.png").scaled(size, size))  );
    }
}

std::vector<QPoint> Knight::getPossibleMoves(const std::array<std::array<Figure*, BOARD_SIZE>, BOARD_SIZE>& figures) {
    std::vector<QPoint> moves;

    QPoint temp = QPoint(boardPos_.x() + 2, boardPos_.y() + 1);
    if(temp.x() < BOARD_SIZE && temp.y() < BOARD_SIZE) {
        moves.push_back(temp);
    }

    temp = QPoint(boardPos_.x() - 2, boardPos_.y() + 1);
    if(temp.x() >= 0 && temp.y() < BOARD_SIZE) {
        moves.push_back(temp);
    }

    temp = QPoint(boardPos_.x() - 2, boardPos_.y() - 1);
    if(temp.x() >= 0 && temp.y() >= 0) {
        moves.push_back(temp);
    }

    temp = QPoint(boardPos_.x() + 2, boardPos_.y() - 1);
    if(temp.x() < BOARD_SIZE && temp.y() >= 0 ) {
        moves.push_back(temp);
    }


    temp = QPoint(boardPos_.x() + 1, boardPos_.y() + 2);
    if(temp.x() >= 0 && temp.y() < BOARD_SIZE) {
        moves.push_back(temp);
    }

    temp = QPoint(boardPos_.x() - 1, boardPos_.y() + 2);
    if(temp.x() >= 0 && temp.y() < BOARD_SIZE) {
        moves.push_back(temp);
    }

    temp = QPoint(boardPos_.x() - 1, boardPos_.y() - 2);
    if(temp.x() >= 0 && temp.y() >= 0) {
        moves.push_back(temp);
    }

    temp = QPoint(boardPos_.x() + 1, boardPos_.y() - 2);
    if(temp.x() < BOARD_SIZE && temp.y() >= 0 ) {
        moves.push_back(temp);
    }
    return moves;
}

#include "queen.h"

Queen::Queen(FigureSide s, int x, int y, int size) : Figure(s, x, y, size)
{
    if(side_ == FigureSide::WHITE) {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/w_queen.png").scaled(size, size))  );
    }
    else {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/b_queen.png").scaled(size, size))  );
    }
}

std::vector<QPoint> Queen::getPossibleMoves(const std::array<std::array<Figure*, BOARD_SIZE>, BOARD_SIZE>& figures) {
    std::vector<QPoint> moves;
    QPoint temp = QPoint(boardPos_.x() + 1, boardPos_.y() + 1 );
    while(temp.x() < BOARD_SIZE && temp.y() < BOARD_SIZE) {
        if(figures[temp.x()][temp.y()] != nullptr) {
            Figure * figure = figures[temp.x()][temp.y()];
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

    while(temp.x() >= 0 && temp.y() >= 0) {
        if(figures[temp.x()][temp.y()] != nullptr) {
            Figure * figure = figures[temp.x()][temp.y()];
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

    while(temp.x() >= 0 && temp.y() < BOARD_SIZE) {
        if(figures[temp.x()][temp.y()] != nullptr) {
            Figure * figure = figures[temp.x()][temp.y()];
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

    while(temp.x() < BOARD_SIZE && temp.y() >= 0) {
        if(figures[temp.x()][temp.y()] != nullptr) {
            Figure * figure = figures[temp.x()][temp.y()];
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
    while(temp.x() < BOARD_SIZE ) {
        if(figures[temp.x()][temp.y()] != nullptr) {
            Figure * figure = figures[temp.x()][temp.y()];
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
            break;
        }
        moves.push_back(temp);
        temp.setX(temp.x() + 1);
    }
    temp = QPoint(boardPos_.x() - 1, boardPos_.y()  );

    while(temp.x() >= 0 ) {
        if(figures[temp.x()][temp.y()] != nullptr) {
            Figure * figure = figures[temp.x()][temp.y()];
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
            break;
        }
        moves.push_back(temp);
        temp.setX(temp.x() - 1);
    }

    temp = QPoint(boardPos_.x(), boardPos_.y() - 1);

    while(temp.y() >= 0) {
        if(figures[temp.x()][temp.y()] != nullptr) {
            Figure * figure = figures[temp.x()][temp.y()];
            if(figure->getSide() != side_) {
                moves.push_back(temp);
            }
            break;
        }
        moves.push_back(temp);
        temp.setY(temp.y() - 1);
    }

    temp = QPoint(boardPos_.x(), boardPos_.y() + 1);

    while(temp.y() < BOARD_SIZE) {
        if(figures[temp.x()][temp.y()] != nullptr) {
            Figure * figure = figures[temp.x()][temp.y()];
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

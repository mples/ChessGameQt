#include "pawn.h"
#include "chessboard.h"
#include <cmath>

Pawn::Pawn(FigureSide s, int x, int y, int size) : Figure(s, x, y, size)
{
    if(side_ == FigureSide::WHITE) {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/w_pawn.png").scaled(size, size))  );
    }
    else {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/b_pawn.png").scaled(size, size))  );
    }
    untouched_ = true;
}


Pawn::~Pawn(){

}

std::vector<QPoint> Pawn::getPossibleMoves(const ChessBoard& board) {
    std::vector<QPoint> moves;

    if(side_ == FigureSide::WHITE) {
        if(boardPos_.y() - 1 >= 0 && board.getFigureAt(boardPos_.x(), boardPos_.y() - 1) == nullptr) {
            moves.push_back(QPoint(boardPos_.x() , boardPos_.y() - 1));
            if(untouched_) {
                if(boardPos_.y() - 2 >= 0 && board.getFigureAt(boardPos_.x(), boardPos_.y() - 2) == nullptr)
                    moves.push_back(QPoint(boardPos_.x() , boardPos_.y() - 2));
            }
            if(boardPos_.x() - 1 >= 0) {
                QPoint temp = QPoint(boardPos_.x() - 1, boardPos_.y() - 1);
                Figure * figure = board.getFigureAt(temp);
                if(figure != nullptr) {
                    if(figure->getSide() != side_) {
                        moves.push_back(temp);
                    }
                }
            }
        }

        if(boardPos_.x() + 1 < BOARD_SIZE ) {
            QPoint temp = QPoint(boardPos_.x() + 1, boardPos_.y() - 1);
            Figure * figure = board.getFigureAt(temp);
            if(figure != nullptr) {
                if(figure->getSide() != side_) {
                    moves.push_back(temp);
                }
            }
        }
        if(boardPos_.x() - 1 >= 0 ) {
            QPoint temp = QPoint(boardPos_.x() - 1, boardPos_.y() - 1);
            Figure * figure = board.getFigureAt(temp);
            if(figure != nullptr) {
                if(figure->getSide() != side_) {
                    moves.push_back(temp);
                }
            }
        }
    }
    else if(side_ == FigureSide::BLACK) {
        if(boardPos_.y() + 1 < BOARD_SIZE && board.getFigureAt(boardPos_.x(), boardPos_.y() + 1) == nullptr){
            moves.push_back(QPoint(boardPos_.x() , boardPos_.y() + 1));
            if(untouched_) {
                if(boardPos_.y() + 2 < BOARD_SIZE && board.getFigureAt(boardPos_.x(), boardPos_.y() + 2) == nullptr)
                   moves.push_back(QPoint(boardPos_.x() , boardPos_.y() + 2));
            }
            if(boardPos_.x() - 1 >= 0) {
                QPoint temp = QPoint(boardPos_.x() - 1, boardPos_.y() + 1);
                Figure * figure = board.getFigureAt(temp);
                if(figure != nullptr) {
                    if(figure->getSide() != side_) {
                        moves.push_back(temp);
                    }
                }
            }
        }
        if(boardPos_.x() + 1 < BOARD_SIZE) {
            QPoint temp = QPoint(boardPos_.x() + 1, boardPos_.y() + 1);
            Figure * figure = board.getFigureAt(temp);
            if(figure != nullptr) {
                if(figure->getSide() != side_) {
                    moves.push_back(temp);
                }
            }
        }
        if(boardPos_.x() - 1 >= 0) {
            QPoint temp = QPoint(boardPos_.x() - 1, boardPos_.y() + 1);
            Figure * figure = board.getFigureAt(temp);
            if(figure != nullptr) {
                if(figure->getSide() != side_) {
                    moves.push_back(temp);
                }
            }
        }
    }


    return moves;
}

void Pawn::updateScenePos()
{
    setPos(boardPos_.x() * fieldSize_, boardPos_.y() * fieldSize_);
    untouched_ = false;
}


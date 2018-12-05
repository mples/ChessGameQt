#include "figure.h"

Figure::Figure(FigureSide side, int x, int y, int size) : QGraphicsPixmapItem (), side_(side) {
    boardPos_ = QPoint(x,y);
    fieldSize_ = size;
    updateScenePos();
}
Figure::~Figure(){}

QPoint Figure::getBoardPos() {
    return boardPos_;
}

void Figure::setBoardPos(QPoint point) {
    boardPos_ = point;
    //setPos(boardPos_.x() * fieldSize_, boardPos_.y() * fieldSize_);
}

void Figure::updateScenePos() {
    setPos(boardPos_.x() * fieldSize_, boardPos_.y() * fieldSize_);
}

void Figure::resetPos() {
    setPos(boardPos_.x() * fieldSize_, boardPos_.y() * fieldSize_);
}

FigureSide Figure::getSide() {
    return side_;
}

FigureSide Figure::getOppositeSide(FigureSide side) {
    if(side ==FigureSide::WHITE){
        return FigureSide::BLACK;
    }
    else {
        return FigureSide::WHITE;
    }
}

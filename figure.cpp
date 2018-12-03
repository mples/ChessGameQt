#include "figure.h"

Figure::Figure(FigureSide side, int x, int y, int size) : QGraphicsPixmapItem (), side_(side) {
    posX_ = x;
    posY_ = y;
    fieldSize_ = size;
    setPos(posX_ *fieldSize_, posY_ * fieldSize_);
}
Figure::~Figure(){}

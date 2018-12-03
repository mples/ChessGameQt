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

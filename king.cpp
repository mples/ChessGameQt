#include "king.h"

King::King(FigureSide s, int x, int y, int size) : Figure(s, x, y, size)
{
    if(side_ == FigureSide::WHITE) {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/w_king.png").scaled(size,size))  );
    }
    else {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/b_king.png").scaled(size,size))  );
    }
}

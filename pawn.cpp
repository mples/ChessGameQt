#include "pawn.h"


Pawn::Pawn(FigureSide s, int x, int y, int size) : Figure(s, x, y, size)
{
    if(side_ == FigureSide::WHITE) {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/w_pawn.png").scaled(size, size))  );
    }
    else {
        setPixmap(QPixmap::fromImage(QImage(":/imgs/b_pawn.png").scaled(size, size))  );
    }

}


Pawn::~Pawn(){

}

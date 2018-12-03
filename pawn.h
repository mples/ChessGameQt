#ifndef PAWN_H
#define PAWN_H
#include "figure.h"

class Pawn  : public Figure
{
public:
    Pawn(FigureSide s, int x, int y, int size);
    ~Pawn();
};

#endif // PAWN_H

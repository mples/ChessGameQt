#ifndef KNIGHT_H
#define KNIGHT_H
#include "figure.h"

class Knight : public Figure
{
public:
    Knight(FigureSide s, int x, int y, int size);
};

#endif // KNIGHT_H

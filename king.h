#ifndef KING_H
#define KING_H
#include "figure.h"

class King : public Figure
{
public:
    King(FigureSide s, int x, int y, int size);
};

#endif // KING_H

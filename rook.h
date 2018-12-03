#ifndef ROOK_H
#define ROOK_H
#include "figure.h"

class Rook : public Figure
{
public:
    Rook(FigureSide s, int x, int y, int size);
};

#endif // ROOK_H

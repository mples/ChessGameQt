#ifndef QUEEN_H
#define QUEEN_H
#include "figure.h"

class Queen : public Figure
{
public:
    Queen(FigureSide s, int x, int y, int size);
};

#endif // QUEEN_H

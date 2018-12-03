#ifndef QUEEN_H
#define QUEEN_H
#include "figure.h"

class Queen : public Figure
{
public:
    Queen(FigureSide s, int x, int y, int size);

    // Figure interface
public:
    std::vector<QPoint> getPossibleMoves(const std::array<std::array<Figure*, BOARD_SIZE>, BOARD_SIZE>& figures);
};

#endif // QUEEN_H

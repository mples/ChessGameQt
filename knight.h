#ifndef KNIGHT_H
#define KNIGHT_H
#include "figure.h"

class Knight : public Figure
{
public:
    Knight(FigureSide s, int x, int y, int size);

    // Figure interface
public:
    std::vector<QPoint> getPossibleMoves(const std::array<std::array<Figure*, BOARD_SIZE>, BOARD_SIZE>& figures);
};

#endif // KNIGHT_H

#ifndef BISHOP_H
#define BISHOP_H
#include "figure.h"

class Bishop : public Figure
{
public:
    Bishop(FigureSide s, int x, int y, int size);

    // Figure interface
public:
    std::vector<QPoint> getPossibleMoves(const std::array<std::array<Figure*, BOARD_SIZE>, BOARD_SIZE>& figures);
};

#endif // BISHOP_H

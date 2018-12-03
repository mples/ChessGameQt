#ifndef KING_H
#define KING_H
#include "figure.h"

class King : public Figure
{
public:
    King(FigureSide s, int x, int y, int size);

    // Figure interface
public:
    std::vector<QPoint> getPossibleMoves(const std::array<std::array<Figure*, BOARD_SIZE>, BOARD_SIZE>& figures);
};

#endif // KING_H

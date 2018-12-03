#ifndef ROOK_H
#define ROOK_H
#include "figure.h"

class Rook : public Figure
{
public:
    Rook(FigureSide s, int x, int y, int size);

    // Figure interface
public:
    std::vector<QPoint> getPossibleMoves(const std::array<std::array<Figure*, BOARD_SIZE>, BOARD_SIZE>& figures);
};

#endif // ROOK_H

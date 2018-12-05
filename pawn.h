#ifndef PAWN_H
#define PAWN_H
#include "figure.h"

class Pawn  : public Figure
{
public:
    Pawn(FigureSide s, int x, int y, int size);
    ~Pawn();

private:
    bool untouched_;
    // Figure interface
public:
    std::vector<QPoint> getPossibleMoves(const ChessBoard& board);

    // Figure interface
public:


    // Figure interface
public:
    void updateScenePos();
};

#endif // PAWN_H

#ifndef FIGURE_H
#define FIGURE_H

#include<vector>
#include <QGraphicsPixmapItem>
#include <QPoint>
#include "chess_const.h"

class ChessBoard;

enum class FigureSide {
    WHITE,
    BLACK
};

class Figure : public QGraphicsPixmapItem
{
public:
    Figure(FigureSide side, int x, int y, int size);
    virtual ~Figure();
    QPoint getBoardPos();
    virtual std::vector<QPoint> getPossibleMoves( const ChessBoard& board) = 0;
    virtual void setBoardPos(QPoint point);
    virtual void updateScenePos();
    void resetPos();
    FigureSide getSide();
    static FigureSide getOppositeSide(FigureSide side);
protected:
    FigureSide side_;
    QPoint boardPos_;
    int fieldSize_;
};

#endif // FIGURE_H

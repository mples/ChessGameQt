#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsPixmapItem>

enum class FigureSide {
    WHITE,
    BLACK
};

class Figure : public QGraphicsPixmapItem
{
public:
    Figure(FigureSide side, int x, int y, int size);
    virtual ~Figure();
protected:
    FigureSide side_;
    int posX_;
    int posY_;
    int fieldSize_;
};

#endif // FIGURE_H

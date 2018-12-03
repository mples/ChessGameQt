#ifndef CHESSTABLEWIDGET_H
#define CHESSTABLEWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPoint>

#include<array>
#include<vector>
#include "figure.h"

class ChessTableWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ChessTableWidget(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event) override;
private:
    static const int FIELD_SIZE = 100;
    static const int TABLE_SIZE = 8;
    QGraphicsScene* scene_;
    std::array<std::array<QGraphicsRectItem*, 8>, 8> fieldsTable_;
    std::array<std::array<Figure*, 8>, 8> figuresTable_;
    std::vector<Figure*> blackFigures_;
    std::vector<Figure*> whiteFigures_;

    void paintTable();
    void initFigures();
    QPoint pixelToBoardCoord(QPoint point);
    Figure* getWhiteFigure(QPoint point);
    Figure* getBlackFigure(QPoint point);
signals:

public slots:
};

#endif // CHESSTABLEWIDGET_H

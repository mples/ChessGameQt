#ifndef CHESSTABLEWIDGET_H
#define CHESSTABLEWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

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
    std::array<std::array<QGraphicsRectItem*, 8>, 8> table_;
    std::vector<Figure*> blackFigures_;
    std::vector<Figure*> whiteFigures_;

    void paintTable();
    void initFigures();

signals:

public slots:
};

#endif // CHESSTABLEWIDGET_H

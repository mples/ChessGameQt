#ifndef CHESSTABLE_H
#define CHESSTABLE_H
#include "figure.h"
#include <vector>
#include <array>
#include <QPoint>

class ChessBoard {
public:
    ChessBoard();
    void addFigure(Figure* figure, QPoint& point);
    void addFigure(Figure* figure, int x, int y);
    bool isValidBoardCoord(QPoint& point) const;
    bool isValidBoardCoord(int x, int y) const;
    Figure* getFigureAt(QPoint& point) const;
    Figure* getFigureAt(int x, int y) const;
    void removeFigureAt(QPoint& point);
    bool moveFromTo(QPoint from, QPoint to);
    std::vector<QPoint> getAllPosibleMoves(QPoint& at);
    bool isKingInCheck(FigureSide side);
    std::vector<QPoint> getSidePosibleMoves(FigureSide side);
    bool isCheckmate(FigureSide side);
    bool isMovePossible(QPoint from, QPoint to);
private:
    std::array<std::array<Figure*, BOARD_SIZE>, BOARD_SIZE> figures_;
    std::vector<Figure*> blackFigures_;
    std::vector<Figure*> whiteFigures_;

    void removeFromFigureVector(Figure* figure);
    void addToFigureVector(Figure* figure);
    std::vector<QPoint> getWhitePosibleMoves();
    std::vector<QPoint> getBlackPosibleMoves();
};

#endif // CHESSTABLE_H

#include "chesstablewidget.h"
#include <algorithm>
#include "QGraphicsPixmapItem"
#include <QtDebug>
#include <QMouseEvent>

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"


ChessTableWidget::ChessTableWidget(QWidget *parent) : QGraphicsView(parent)
{
    scene_ = new QGraphicsScene();
    setScene(scene_);
    paintTable();
    initFigures();
}


void ChessTableWidget::paintTable() {
    for(int i = 0 ; i < TABLE_SIZE ; ++i){
        for(int j = 0 ; j < TABLE_SIZE ; ++j){
            QGraphicsRectItem* rec = new QGraphicsRectItem(0,0,100,100);
            fieldsTable_[i][j] = rec;
            rec->setPos( i*FIELD_SIZE,j*FIELD_SIZE);
            scene_->addItem(rec);
            if((((i*TABLE_SIZE )+ j +i)% 2 ) == 0 ){
                rec->setBrush(Qt::gray);
            }
            else {
                rec->setBrush(Qt::green);
            }
        }
    }
}

void ChessTableWidget::initFigures() {
    for(int i = 0 ; i < 8 ; ++i) {
        Figure* pawn = new Pawn(FigureSide::WHITE, i, 6, FIELD_SIZE);
        scene_->addItem(pawn);
        board_.addFigure(pawn, i, 6);
    }

    Figure* w_rook_left = new Rook(FigureSide::WHITE, 0, 7, FIELD_SIZE);
    scene_->addItem(w_rook_left);
    board_.addFigure(w_rook_left, 0, 7);

    Figure* w_rook_right = new Rook(FigureSide::WHITE, 7, 7, FIELD_SIZE);
    scene_->addItem(w_rook_right);
    board_.addFigure(w_rook_right, 7, 7);

    Figure* w_knight_left = new Knight(FigureSide::WHITE, 1, 7, FIELD_SIZE);
    scene_->addItem(w_knight_left);
    board_.addFigure(w_knight_left, 1, 7);

    Figure* w_knight_right = new Knight(FigureSide::WHITE, 6, 7, FIELD_SIZE);
    scene_->addItem(w_knight_right);
    board_.addFigure(w_knight_right, 6, 7);

    Figure* w_bishop_left = new Bishop(FigureSide::WHITE, 2, 7, FIELD_SIZE);
    scene_->addItem(w_bishop_left);
    board_.addFigure(w_bishop_left, 2, 7);

    Figure* w_bishop_right = new Bishop(FigureSide::WHITE, 5, 7, FIELD_SIZE);
    scene_->addItem(w_bishop_right);
    board_.addFigure(w_bishop_right, 5, 7);

    Figure* w_king = new King(FigureSide::WHITE, 4, 7, FIELD_SIZE);
    scene_->addItem(w_king);
    board_.addFigure(w_king, 4, 7);

    Figure* w_queen = new Queen(FigureSide::WHITE, 3, 7, FIELD_SIZE);
    scene_->addItem(w_queen);
    board_.addFigure(w_queen, 3, 7);

    for(int i = 0 ; i < 8 ; ++i) {
        Figure* pawn = new Pawn(FigureSide::BLACK, i, 1, FIELD_SIZE);
        scene_->addItem(pawn);
        board_.addFigure(pawn, i, 1);
    }

    Figure* b_rook_left = new Rook(FigureSide::BLACK, 0, 0, FIELD_SIZE);
    scene_->addItem(b_rook_left);
    board_.addFigure(b_rook_left, 0, 0);

    Figure* b_rook_right = new Rook(FigureSide::BLACK, 7, 0, FIELD_SIZE);
    scene_->addItem(b_rook_right);
    board_.addFigure(b_rook_right, 7, 0);

    Figure* b_knight_left = new Knight(FigureSide::BLACK, 1, 0, FIELD_SIZE);
    scene_->addItem(b_knight_left);
    board_.addFigure(b_knight_left, 1, 0);

    Figure* b_knight_right = new Knight(FigureSide::BLACK, 6, 0, FIELD_SIZE);
    scene_->addItem(b_knight_right);
    board_.addFigure(b_knight_right, 6, 0);

    Figure* b_bishop_left = new Bishop(FigureSide::BLACK, 2, 0, FIELD_SIZE);
    scene_->addItem(b_bishop_left);
    board_.addFigure(b_bishop_left, 2, 0);

    Figure* b_bishop_right = new Bishop(FigureSide::BLACK, 5, 0, FIELD_SIZE);
    scene_->addItem(b_bishop_right);
    board_.addFigure(b_bishop_right, 5, 0);

    Figure* b_king = new King(FigureSide::BLACK, 4, 0, FIELD_SIZE);
    scene_->addItem(b_king);
    board_.addFigure(b_king, 4, 0);

    Figure* b_queen = new Queen(FigureSide::BLACK, 3, 0, FIELD_SIZE);
    scene_->addItem(b_queen);
    board_.addFigure(b_queen, 3, 0);
}

QPoint ChessTableWidget::pixelToBoardCoord(QPoint point) {
    return QPoint(point.x() / FIELD_SIZE,  point.y()/FIELD_SIZE);
}
/*
Figure *ChessTableWidget::getWhiteFigure(QPoint point) {
    for(Figure* figure : whiteFigures_) {
        if(figure->getBoardPos() == point){
            return figure;
        }
    }
    return nullptr;
}

Figure *ChessTableWidget::getBlackFigure(QPoint point) {
    for(Figure* figure : blackFigures_) {
        if(figure->getBoardPos() == point){
            return figure;
        }
    }
    return nullptr;
}*/

void ChessTableWidget::paintAvailableMoves() {
    for(QPoint point : availableMoves_) {
        fieldsTable_[point.x()][point.y()]->setBrush(Qt::yellow);
    }
}

void ChessTableWidget::clearAvailableMoves(){
    for(QPoint point : availableMoves_) {
        if((((point.x()*TABLE_SIZE )+ point.y() + point.x())% 2 ) == 0 ){
            fieldsTable_[point.x()][point.y()]->setBrush(Qt::gray);
        }
        else {
            fieldsTable_[point.x()][point.y()]->setBrush(Qt::green);
        }
    }
    availableMoves_.clear();
}

void ChessTableWidget::moveFigureToPos(Figure *figure, QPoint pos) {
    if(board_.moveFromTo(figure->getBoardPos(), pos)) {
        changeMovingSide();
    }
    figure->updateScenePos();

}

void ChessTableWidget::changeMovingSide() {
    if(movingSide_ == FigureSide::WHITE) {
        movingSide_ = FigureSide::BLACK;
    }
    else {
        movingSide_ = FigureSide::WHITE;
    }
}

void ChessTableWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Position: " << event->pos() ;
    QPoint figure_coord = pixelToBoardCoord(event->pos() );
    qDebug() << "Board: " << figure_coord;

    Figure * figure = board_.getFigureAt(figure_coord);
    if(figure != nullptr && figure->getSide() == movingSide_) {
        if(selectedFigure_ != nullptr) {
            clearAvailableMoves();
        }
        selectedFigure_ = figure;
        availableMoves_ = board_.getAllPosibleMoves(figure_coord);
        paintAvailableMoves();
    }
}

void ChessTableWidget::mouseReleaseEvent(QMouseEvent *event) {
    if(selectedFigure_) {
        QPoint point = pixelToBoardCoord(event->pos());
        auto found = std::find(availableMoves_.begin(), availableMoves_.end(), point);
        if(found != availableMoves_.end()){
            moveFigureToPos(selectedFigure_, point);
            clearAvailableMoves();
            selectedFigure_ = nullptr;

        }
        else {
            selectedFigure_->resetPos();
            selectedFigure_ = nullptr;
            clearAvailableMoves();
        }
    }
}

void ChessTableWidget::mouseMoveEvent(QMouseEvent *event) {
    if(selectedFigure_) {
        selectedFigure_->setPos(event->pos() - QPoint(FIELD_SIZE/2, FIELD_SIZE/2));
    }
}

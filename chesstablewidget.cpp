#include "chesstablewidget.h"
#include "QGraphicsPixmapItem"
#include <QtDebug>
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include <QMouseEvent>

ChessTableWidget::ChessTableWidget(QWidget *parent) : QGraphicsView(parent)
{
    scene_ = new QGraphicsScene();
    setScene(scene_);
    paintTable();
    initFigures();
}

void ChessTableWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Position: " << event->pos() ;

}

void ChessTableWidget::paintTable() {
    for(int i = 0 ; i < TABLE_SIZE ; ++i){
        for(int j = 0 ; j < TABLE_SIZE ; ++j){
            QGraphicsRectItem* rec = new QGraphicsRectItem(0,0,100,100);
            table_[i][j] = rec;
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
        whiteFigures_.push_back(pawn);
    }

    Figure* w_rook_left = new Rook(FigureSide::WHITE, 0, 7, FIELD_SIZE);
    scene_->addItem(w_rook_left);
    whiteFigures_.push_back(w_rook_left);

    Figure* w_rook_right = new Rook(FigureSide::WHITE, 7, 7, FIELD_SIZE);
    scene_->addItem(w_rook_right);
    whiteFigures_.push_back(w_rook_right);

    Figure* w_knight_left = new Knight(FigureSide::WHITE, 1, 7, FIELD_SIZE);
    scene_->addItem(w_knight_left);
    whiteFigures_.push_back(w_knight_left);

    Figure* w_knight_right = new Knight(FigureSide::WHITE, 6, 7, FIELD_SIZE);
    scene_->addItem(w_knight_right);
    whiteFigures_.push_back(w_knight_right);

    Figure* w_bishop_left = new Bishop(FigureSide::WHITE, 2, 7, FIELD_SIZE);
    scene_->addItem(w_bishop_left);
    whiteFigures_.push_back(w_bishop_left);

    Figure* w_bishop_right = new Bishop(FigureSide::WHITE, 5, 7, FIELD_SIZE);
    scene_->addItem(w_bishop_right);
    whiteFigures_.push_back(w_bishop_right);

    Figure* w_king = new King(FigureSide::WHITE, 4, 7, FIELD_SIZE);
    scene_->addItem(w_king);
    whiteFigures_.push_back(w_king);

    Figure* w_queen = new Queen(FigureSide::WHITE, 3, 7, FIELD_SIZE);
    scene_->addItem(w_queen);
    whiteFigures_.push_back(w_queen);

    for(int i = 0 ; i < 8 ; ++i) {
        Figure* pawn = new Pawn(FigureSide::BLACK, i, 1, FIELD_SIZE);
        scene_->addItem(pawn);
        blackFigures_.push_back(pawn);
    }

    Figure* b_rook_left = new Rook(FigureSide::BLACK, 0, 0, FIELD_SIZE);
    scene_->addItem(b_rook_left);
    blackFigures_.push_back(b_rook_left);

    Figure* b_rook_right = new Rook(FigureSide::BLACK, 7, 0, FIELD_SIZE);
    scene_->addItem(b_rook_right);
    blackFigures_.push_back(b_rook_right);

    Figure* b_knight_left = new Knight(FigureSide::BLACK, 1, 0, FIELD_SIZE);
    scene_->addItem(b_knight_left);
    blackFigures_.push_back(b_knight_left);

    Figure* b_knight_right = new Knight(FigureSide::BLACK, 6, 0, FIELD_SIZE);
    scene_->addItem(b_knight_right);
    blackFigures_.push_back(b_knight_right);

    Figure* b_bishop_left = new Bishop(FigureSide::BLACK, 2, 0, FIELD_SIZE);
    scene_->addItem(b_bishop_left);
    blackFigures_.push_back(b_bishop_left);

    Figure* b_bishop_right = new Bishop(FigureSide::BLACK, 5, 0, FIELD_SIZE);
    scene_->addItem(b_bishop_right);
    blackFigures_.push_back(b_bishop_right);

    Figure* b_king = new King(FigureSide::BLACK, 4, 0, FIELD_SIZE);
    scene_->addItem(b_king);
    blackFigures_.push_back(b_king);

    Figure* b_queen = new Queen(FigureSide::BLACK, 3, 0, FIELD_SIZE);
    scene_->addItem(b_queen);
    blackFigures_.push_back(b_queen);



}

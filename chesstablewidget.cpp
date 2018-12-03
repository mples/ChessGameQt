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
    for(int i = 0 ; i < BOARD_SIZE ; ++i) {
        for( int j = 0 ; j < BOARD_SIZE ; ++j) {
            figuresTable_[i][j] = nullptr;
        }
    }

    scene_ = new QGraphicsScene();
    setScene(scene_);
    paintTable();
    initFigures();
}

void ChessTableWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Position: " << event->pos() ;
    QPoint figure_coord = pixelToBoardCoord(event->pos() );
    qDebug() << "Board: " << figure_coord;

    Figure * figure = figuresTable_[figure_coord.x()][figure_coord.y()];
    if(figure != nullptr) {
        if(selectedFigure_ != nullptr) {
            clearAvailableMoves();
        }
        selectedFigure_ = figure;
        availableMoves_ = figure->getPossibleMoves(figuresTable_);
        paintAvailableMoves();
    }
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
        whiteFigures_.push_back(pawn);
        figuresTable_[i][6] = pawn;
    }

    Figure* w_rook_left = new Rook(FigureSide::WHITE, 0, 7, FIELD_SIZE);
    scene_->addItem(w_rook_left);
    whiteFigures_.push_back(w_rook_left);
    figuresTable_[0][7] = w_rook_left;

    Figure* w_rook_right = new Rook(FigureSide::WHITE, 7, 7, FIELD_SIZE);
    scene_->addItem(w_rook_right);
    whiteFigures_.push_back(w_rook_right);
    figuresTable_[7][7] = w_rook_right;

    Figure* w_knight_left = new Knight(FigureSide::WHITE, 1, 7, FIELD_SIZE);
    scene_->addItem(w_knight_left);
    whiteFigures_.push_back(w_knight_left);
    figuresTable_[1][7] = w_knight_left;

    Figure* w_knight_right = new Knight(FigureSide::WHITE, 6, 7, FIELD_SIZE);
    scene_->addItem(w_knight_right);
    whiteFigures_.push_back(w_knight_right);
    figuresTable_[6][7] = w_knight_right;

    Figure* w_bishop_left = new Bishop(FigureSide::WHITE, 2, 7, FIELD_SIZE);
    scene_->addItem(w_bishop_left);
    whiteFigures_.push_back(w_bishop_left);
    figuresTable_[2][7] = w_bishop_left;

    Figure* w_bishop_right = new Bishop(FigureSide::WHITE, 5, 7, FIELD_SIZE);
    scene_->addItem(w_bishop_right);
    whiteFigures_.push_back(w_bishop_right);
    figuresTable_[5][7] = w_bishop_right;

    Figure* w_king = new King(FigureSide::WHITE, 4, 7, FIELD_SIZE);
    scene_->addItem(w_king);
    whiteFigures_.push_back(w_king);
    figuresTable_[4][7] = w_king;

    Figure* w_queen = new Queen(FigureSide::WHITE, 3, 7, FIELD_SIZE);
    scene_->addItem(w_queen);
    whiteFigures_.push_back(w_queen);
    figuresTable_[3][7] = w_queen;

    for(int i = 0 ; i < 8 ; ++i) {
        Figure* pawn = new Pawn(FigureSide::BLACK, i, 1, FIELD_SIZE);
        scene_->addItem(pawn);
        blackFigures_.push_back(pawn);
        figuresTable_[i][1] = pawn;
    }

    Figure* b_rook_left = new Rook(FigureSide::BLACK, 0, 0, FIELD_SIZE);
    scene_->addItem(b_rook_left);
    blackFigures_.push_back(b_rook_left);
    figuresTable_[0][0] = b_rook_left;

    Figure* b_rook_right = new Rook(FigureSide::BLACK, 7, 0, FIELD_SIZE);
    scene_->addItem(b_rook_right);
    blackFigures_.push_back(b_rook_right);
    figuresTable_[7][0] = b_rook_right;

    Figure* b_knight_left = new Knight(FigureSide::BLACK, 1, 0, FIELD_SIZE);
    scene_->addItem(b_knight_left);
    blackFigures_.push_back(b_knight_left);
    figuresTable_[1][0] = b_knight_left;

    Figure* b_knight_right = new Knight(FigureSide::BLACK, 6, 0, FIELD_SIZE);
    scene_->addItem(b_knight_right);
    blackFigures_.push_back(b_knight_right);
    figuresTable_[6][0] = b_knight_right;

    Figure* b_bishop_left = new Bishop(FigureSide::BLACK, 2, 0, FIELD_SIZE);
    scene_->addItem(b_bishop_left);
    blackFigures_.push_back(b_bishop_left);
    figuresTable_[2][0] = b_bishop_left;

    Figure* b_bishop_right = new Bishop(FigureSide::BLACK, 5, 0, FIELD_SIZE);
    scene_->addItem(b_bishop_right);
    blackFigures_.push_back(b_bishop_right);
    figuresTable_[5][0] = b_bishop_right;

    Figure* b_king = new King(FigureSide::BLACK, 4, 0, FIELD_SIZE);
    scene_->addItem(b_king);
    blackFigures_.push_back(b_king);
    figuresTable_[4][0] = b_king;

    Figure* b_queen = new Queen(FigureSide::BLACK, 3, 0, FIELD_SIZE);
    scene_->addItem(b_queen);
    blackFigures_.push_back(b_queen);
    figuresTable_[3][0] = b_queen;


}

QPoint ChessTableWidget::pixelToBoardCoord(QPoint point) {
    return QPoint(point.x() / FIELD_SIZE,  point.y()/FIELD_SIZE);
}

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
}

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
}

void ChessTableWidget::moveFigureToPos(Figure *figure, QPoint pos) {
    Figure * attacked_figure = figuresTable_[pos.x()][pos.y()];
    if(attacked_figure) {
        delete attacked_figure;
    }
    QPoint old_pos = figure->getBoardPos();
    figuresTable_[old_pos.x()][old_pos.y()] = nullptr;

    figuresTable_[pos.x()][pos.y()] = figure;
    figure->setBoardPos(pos);
}

void ChessTableWidget::mouseReleaseEvent(QMouseEvent *event) {
    QPoint point = pixelToBoardCoord(event->pos());
    auto found = std::find(availableMoves_.begin(), availableMoves_.end(), point);
    if(found != availableMoves_.end()){
        moveFigureToPos(selectedFigure_, point);
        selectedFigure_->setBoardPos(point);
        clearAvailableMoves();
    }
    else {
        selectedFigure_->resetPos();
    }
}

void ChessTableWidget::mouseMoveEvent(QMouseEvent *event) {
    if(selectedFigure_) {
        selectedFigure_->setPos(event->pos() - QPoint(FIELD_SIZE/2, FIELD_SIZE/2));
    }
}

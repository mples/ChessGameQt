#include "chesstablewindow.h"
#include "ui_chesstablewindow.h"
#include "chesstablewidget.h"

ChessTableWindow::ChessTableWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChessTableWindow)
{
    ui->setupUi(this);
    ChessTableWidget* chess_table = new ChessTableWidget(this);
    ui->horizontalLayout->addWidget(chess_table);
}

ChessTableWindow::~ChessTableWindow()
{
    delete ui;
}

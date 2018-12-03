#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chesstablewindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{
    ChessTableWindow * chess_table_window = new ChessTableWindow(this);

    chess_table_window->show();
}

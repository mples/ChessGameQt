#include "menuwindow.h"
#include "ui_mainwindow.h"
#include "chesstablewindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_playButton_clicked()
{
    ChessTableWindow * chess_table_window = new ChessTableWindow(this);

    chess_table_window->show();
    this->hide();
}

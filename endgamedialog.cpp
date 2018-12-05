#include "endgamedialog.h"
#include "ui_endgamedialog.h"

EndGameDialog::EndGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndGameDialog)
{
    ui->setupUi(this);
    ui->messageLabel->setText("Player has won a match");
}

EndGameDialog::~EndGameDialog()
{
    delete ui;
}

void EndGameDialog::on_nextGameButton_clicked()
{

}

#include "endgamedialog.h"
#include "ui_endgamedialog.h"
#include "chesstablewindow.h"
#include <string>

EndGameDialog::EndGameDialog(FigureSide side,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndGameDialog)
{
    ui->setupUi(this);
    QString side_string;
    if(side == FigureSide::WHITE){
        side_string = "White";
    }
    else {
        side_string = "Black";
    }
    side_string.append(" side has won.\nDo you want to play again?");
    ui->messageLabel->setText(side_string);
}

EndGameDialog::~EndGameDialog()
{

}


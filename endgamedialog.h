#ifndef ENDGAMEDIALOG_H
#define ENDGAMEDIALOG_H

#include <QDialog>
#include "figure.h"

namespace Ui {
class EndGameDialog;
}

class EndGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EndGameDialog(FigureSide side, QWidget *parent = nullptr);
    ~EndGameDialog();


private:
    Ui::EndGameDialog *ui;

};

#endif // ENDGAMEDIALOG_H

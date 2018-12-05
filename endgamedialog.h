#ifndef ENDGAMEDIALOG_H
#define ENDGAMEDIALOG_H

#include <QDialog>

namespace Ui {
class EndGameDialog;
}

class EndGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EndGameDialog(QWidget *parent = nullptr);
    ~EndGameDialog();

private slots:
    void on_nextGameButton_clicked();

private:
    Ui::EndGameDialog *ui;
};

#endif // ENDGAMEDIALOG_H

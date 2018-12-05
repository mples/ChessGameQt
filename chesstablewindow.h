#ifndef CHESSTABLEWINDOW_H
#define CHESSTABLEWINDOW_H

#include <QMainWindow>

namespace Ui {
class ChessTableWindow;
}

class ChessTableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChessTableWindow(QWidget *parent = nullptr);
    ~ChessTableWindow();

private:
    Ui::ChessTableWindow *ui;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // CHESSTABLEWINDOW_H

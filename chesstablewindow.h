#ifndef CHESSTABLEWINDOW_H
#define CHESSTABLEWINDOW_H

#include <QMainWindow>
#include "chesstablewidget.h"
namespace Ui {
class ChessTableWindow;
}

class ChessTableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChessTableWindow(QWidget *parent = nullptr);
    ~ChessTableWindow();
    void resetGame();
signals:

public slots:
    void onGameFinished(int result);
private:
    Ui::ChessTableWindow *ui;
    ChessTableWidget* chessTable_;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // CHESSTABLEWINDOW_H

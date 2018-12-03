#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>

namespace Ui {
class settingsWindow;
}

class settingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit settingsWindow(QWidget *parent = nullptr);
    ~settingsWindow();

private:
    Ui::settingsWindow *ui;
};

#endif // SETTINGSWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settingswindow.h"

namespace Ui {
class MainWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:
    void on_playButton_clicked();

    void on_settingsButton_clicked();

    void on_colorsSelected(QColor, QColor);

private:
    Ui::MainWindow *ui;
    QColor oddColor_ = Qt::gray;
    QColor evenColor_ = Qt::green;
    SettingsWindow* settingsWindow_;
};

#endif // MAINWINDOW_H

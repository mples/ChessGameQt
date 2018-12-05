#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include <QColorDialog>

namespace Ui {
class settingsWindow;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();
signals:
    void colorsSelected(QColor, QColor);
private slots:
    void on_saveButton_clicked();

    void on_selectEvenColorButton_clicked();

    void on_selectOddColorButton_clicked();

    void on_evenColorSelected(const QColor& color);

    void on_oddColorSelected(const QColor& color);

private:
    Ui::settingsWindow *ui;
    QColor oddColor_;
    QColor evenColor_;
    QColorDialog* oddColorDialog_;
    QColorDialog* evenColorDialog_;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // SETTINGSWINDOW_H

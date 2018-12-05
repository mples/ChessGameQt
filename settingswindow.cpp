#include "settingswindow.h"
#include "ui_settingswindow.h"


SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::settingsWindow)
{
    ui->setupUi(this);

}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_saveButton_clicked()
{
    emit colorsSelected(oddColor_, evenColor_);

    parentWidget()->show();

    this->close();

}

void SettingsWindow::on_selectEvenColorButton_clicked()
{
    evenColorDialog_ = new QColorDialog(this);
    QObject::connect(evenColorDialog_, SIGNAL(colorSelected(const QColor&)), this, SLOT(on_evenColorSelected(const QColor&)));
    evenColorDialog_->exec();

}

void SettingsWindow::on_selectOddColorButton_clicked()
{
    oddColorDialog_ = new QColorDialog(this);
    QObject::connect(oddColorDialog_, SIGNAL(colorSelected(const QColor&)), this, SLOT(on_oddColorSelected(const QColor&)));
    oddColorDialog_->exec();
}

void SettingsWindow::on_evenColorSelected(const QColor &color)
{
    evenColor_ = color;
}

void SettingsWindow::on_oddColorSelected(const QColor &color)
{
    oddColor_ = color;
}

void SettingsWindow::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);

    parentWidget()->show();
}

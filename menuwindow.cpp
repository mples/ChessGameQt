#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "chesstablewindow.h"
#include "settingswindow.h"
#include "QDesktopWidget"
#include <QStyle>

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setGeometry(
                QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                size(),
                qApp->desktop()->availableGeometry()
            )
        );
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_playButton_clicked()
{
    ChessTableWindow * chess_table_window = new ChessTableWindow(this, oddColor_, evenColor_);

    chess_table_window->show();
    this->hide();
}

void MenuWindow::on_settingsButton_clicked()
{
    settingsWindow_ = new SettingsWindow(this);
    QObject::connect(settingsWindow_, SIGNAL(colorsSelected(QColor, QColor)), this, SLOT(on_colorsSelected(QColor, QColor)));
    settingsWindow_->show();
    this->hide();
}

void MenuWindow::on_colorsSelected(QColor odd, QColor even)
{
    if(odd.isValid()){
        oddColor_ = odd;
    }
    if(even.isValid()) {
        evenColor_ = even;
    }
}

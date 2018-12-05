#include "chesstablewindow.h"
#include "ui_chesstablewindow.h"
#include "chesstablewidget.h"
#include <QDialog>
#include "QDesktopWidget"
#include <QStyle>

ChessTableWindow::ChessTableWindow(QWidget *parent, QColor odd, QColor even) :
    QMainWindow(parent),
    ui(new Ui::ChessTableWindow), oddBoardColor_(odd), evenBoardColor_(even) {
    ui->setupUi(this);
    chessTable_ = new ChessTableWidget(this, odd, even);
    ui->horizontalLayout->addWidget(chessTable_);
    QObject::connect(chessTable_, SIGNAL(gameEnd(int)), this, SLOT(onGameFinished(int)));
    setGeometry(
                QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                size(),
                qApp->desktop()->availableGeometry()
            )
        );
}

ChessTableWindow::~ChessTableWindow() {
    delete ui;
}

void ChessTableWindow::resetGame() {
    delete chessTable_;
    chessTable_ = new ChessTableWidget(this,oddBoardColor_, evenBoardColor_);
    ui->horizontalLayout->addWidget(chessTable_);
}

void ChessTableWindow::onGameFinished(int result) {
    if(result == QDialog::Accepted) {
        resetGame();
    }
    else if (result == QDialog::Rejected){
        close();
    }
}

void ChessTableWindow::closeEvent(QCloseEvent *event) {
    QWidget::closeEvent(event);

    parentWidget()->show();
}

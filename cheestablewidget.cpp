#include "cheestablewidget.h"
#include "ui_cheestablewidget.h"

CheesTableWidget::CheesTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheesTableWidget)
{
    ui->setupUi(this);


}

CheesTableWidget::~CheesTableWidget()
{
    delete ui;
}

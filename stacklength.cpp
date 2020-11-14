#include "stacklength.h"
#include "ui_stacklength.h"

StackLength::StackLength(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StackLength)
{
    ui->setupUi(this);
    ui->lineEdit->setAlignment(Qt::AlignCenter);
}

StackLength::~StackLength()
{
    delete ui;
}
QString StackLength::getLength() const
{
    return ui->lineEdit->text();
}

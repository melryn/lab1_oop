#include "addobject.h"
#include "ui_addobject.h"
#include <iostream>

AddObject::AddObject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddObject)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->lin_thick->setAlignment(Qt::AlignCenter);
    ui->lin_x->setAlignment(Qt::AlignCenter);
    ui->lin_y->setAlignment(Qt::AlignCenter);
    ui->lin_wid->setAlignment(Qt::AlignCenter);
    ui->lin_hei->setAlignment(Qt::AlignCenter);
}

AddObject::~AddObject()
{
    delete ui;
}
void AddObject::setPaper()
{
    ui->label->setText("Введите данные листка бумаги:");
    ui->lb_thick->setText("Тольщина листка:");
    ui->lb_wid->setText("Длина листка:");
    ui->lb_hei->setText("Ширина листка:");
}
void AddObject::setPlate()
{
    ui->label->setText("Введите данные тарелки:");
    ui->lb_thick->setText("Тольщина тарелки:");
    ui->lb_wid->setText("Радиус тарелки:");
    ui->lb_hei->hide();
    ui->lin_hei->hide();
}
QString AddObject::getX() const
{
    return ui->lin_x->text();
}
QString AddObject::getY() const
{
    return ui->lin_y->text();
}
QString AddObject::getThickness() const
{
    return ui->lin_thick->text();
}
QString AddObject::getWidth() const
{
    return ui->lin_wid->text();
}
QString AddObject::getHeight() const
{
    return ui->lin_hei->text();
}
QString AddObject::getRadius() const
{
    return ui->lin_wid->text();
}
void AddObject::setChangePaper(Iterator it)
{
    ui->label->setText("Измените данные листка:");
    ui->lb_thick->setText("Толщина листка:");
    ui->lb_wid->setText("Длина листка:");
    ui->lb_hei->setText("Ширина листка:");
    Paper *temp = dynamic_cast<Paper*>(it.get());
    ui->lin_x->setText(QString::number(temp->getCoordinateX()));
    ui->lin_y->setText(QString::number(temp->getCoordinateY()));
    ui->lin_hei->setText(QString::number(temp->getHeight()));
    ui->lin_wid->setText(QString::number(temp->getWidth()));
    ui->lin_thick->setText(QString::number(temp->getThickness()));
}
void AddObject::setChangePlate(Iterator it)
{
    ui->label->setText("Измените данные тарелки:");
    ui->label->setText("Введите данные тарелки:");
    ui->lb_thick->setText("Толщина тарелки:");
    ui->lb_wid->setText("Радиус тарелки:");
    ui->lb_hei->hide();
    ui->lin_hei->hide();
    Plate *temp = dynamic_cast<Plate*>(it.get());
    ui->lin_x->setText(QString::number(temp->getCoordinateX()));
    ui->lin_y->setText(QString::number(temp->getCoordinateY()));
    ui->lin_thick->setText(QString::number(temp->getThickness()));
    ui->lin_wid->setText(QString::number(temp->getRadius()));
}

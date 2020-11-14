#include <iostream>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paperstack.h"
#include "plate.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btn_add_paper->hide();
    ui->btn_add_plate->hide();
    ui->btn_del_body->hide();
    ui->btn_clear->hide();
    ui->btn_open->hide();
    ui->btn_save->hide();
    ui->btn_change->hide();
    ui->lin_change->hide();
    ui->btn_report->hide();
    ui->table_widget->horizontalHeader()->setStretchLastSection(true);
}
MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::getIndexChange()
{
    return ui->lin_change->text().toInt();
}
void MainWindow::generate_table()
{
    ui->table_widget->setRowCount(0);
    Iterator it = stack->begin();
    int i = 0;
    ui->table_widget->insertRow(i);
    for (it = stack->begin(); it.get() != stack->end().get(); it.incr())
    {
        ui->table_widget->insertRow(i);
        if (it.get()->who() == "Plate")
        {
            Plate *temp= dynamic_cast<Plate*>(it.get());
            QString text= QString::fromStdString(temp->who());
            ui->table_widget->setItem(i, 0, new QTableWidgetItem(text));
            text= QString::number(temp->getCoordinateX());
            ui->table_widget->setItem(i, 1, new QTableWidgetItem(text));
            text= QString::number(temp->getCoordinateY());
            ui->table_widget->setItem(i, 2, new QTableWidgetItem(text));
            text= QString::number(temp->getThickness());
            ui->table_widget->setItem(i, 3, new QTableWidgetItem(text));
            ui->table_widget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString("-")));
            ui->table_widget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString("-")));
            text= QString::number(temp->getRadius());
            ui->table_widget->setItem(i, 6, new QTableWidgetItem(text));
        }
        if (it.get()->who() == "Paper")
        {
            Paper *temp = dynamic_cast<Paper*>(it.get());
            QString text= QString::fromStdString(temp->who());
            ui->table_widget->setItem(i, 0, new QTableWidgetItem(text));
            text= QString::number(temp->getCoordinateX());
            ui->table_widget->setItem(i, 1, new QTableWidgetItem(text));
            text= QString::number(temp->getCoordinateY());
            ui->table_widget->setItem(i, 2, new QTableWidgetItem(text));
            text= QString::number(temp->getThickness());
            ui->table_widget->setItem(i, 3, new QTableWidgetItem(text));
            text= QString::number(temp->getWidth());
            ui->table_widget->setItem(i, 4, new QTableWidgetItem(text));
            text= QString::number(temp->getHeight());
            ui->table_widget->setItem(i, 5, new QTableWidgetItem(text));
            ui->table_widget->setItem(i, 6, new QTableWidgetItem(QString::fromStdString("-")));
        }
        i++;
    }
    if (it.get()->who() == "Plate")
    {
        Plate *temp= dynamic_cast<Plate*>(it.get());
        QString text= QString::fromStdString(temp->who());
        ui->table_widget->setItem(i, 0, new QTableWidgetItem(text));
        text= QString::number(temp->getCoordinateX());
        ui->table_widget->setItem(i, 1, new QTableWidgetItem(text));
        text= QString::number(temp->getCoordinateY());
        ui->table_widget->setItem(i, 2, new QTableWidgetItem(text));
        text= QString::number(temp->getThickness());
        ui->table_widget->setItem(i, 3, new QTableWidgetItem(text));
        ui->table_widget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString("-")));
        ui->table_widget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString("-")));
        text= QString::number(temp->getRadius());
        ui->table_widget->setItem(i, 6, new QTableWidgetItem(text));
    }
    if (it.get()->who() == "Paper")
    {
        Paper *temp = dynamic_cast<Paper*>(it.get());
        QString text= QString::fromStdString(temp->who());
        ui->table_widget->setItem(i, 0, new QTableWidgetItem(text));
        text= QString::number(temp->getCoordinateX());
        ui->table_widget->setItem(i, 1, new QTableWidgetItem(text));
        text= QString::number(temp->getCoordinateY());
        ui->table_widget->setItem(i, 2, new QTableWidgetItem(text));
        text= QString::number(temp->getThickness());
        ui->table_widget->setItem(i, 3, new QTableWidgetItem(text));
        text= QString::number(temp->getWidth());
        ui->table_widget->setItem(i, 4, new QTableWidgetItem(text));
        text= QString::number(temp->getHeight());
        ui->table_widget->setItem(i, 5, new QTableWidgetItem(text));
        ui->table_widget->setItem(i, 6, new QTableWidgetItem(QString::fromStdString("-")));
    }
    if (stack->count() > 0) ui->lin_change->setText("1");

}
void MainWindow::open_table()
{
    ui->table_widget->setColumnCount(7);
    ui->table_widget->setRowCount(0);
    for (int i = 0; i < 7; i++) ui->table_widget->setColumnWidth(i, 130);
    QStringList tableHeader;
    tableHeader << "Type" << "X" << "Y" << "Thickness" << "Width" << "Height" << "Radius";
    ui->table_widget->setHorizontalHeaderLabels(tableHeader);
    ui->table_widget->setShowGrid(true);
    ui->lin_change->setText("");

}
void MainWindow::on_btn_stack_clicked()
{
        //if (length ==)
        stack = new PaperStack;
        open_table();
        ui->btn_add_paper->show();
        ui->btn_add_plate->show();
        ui->btn_del_body->show();
        ui->btn_clear->show();
        ui->btn_change->show();
        ui->btn_open->show();
        ui->btn_save->show();
        ui->btn_change->show();
        ui->lin_change->show();
        ui->btn_report->show();
        ui->lin_change->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_btn_add_paper_clicked()
{
    AddObject *window = new AddObject;
    window->setPaper();
    if (window->exec())
    {
        x = window->getX().toDouble();
        y = window->getY().toDouble();
        thicknes = window->getThickness().toDouble();
        width = window->getWidth().toDouble();
        height = window->getHeight().toDouble();
        stack->push(new Paper(width, height, thicknes, x, y));
        generate_table();
    }
}
void MainWindow::on_btn_add_plate_clicked()
{
    AddObject *window = new AddObject;
    window->setPlate();
    if (window->exec())
    {

        x = window->getX().toDouble();
        y = window->getY().toDouble();
        thicknes = window->getThickness().toDouble();
        radius = window->getRadius().toDouble();
        stack->push(new Plate(radius, thicknes, x, y));
        generate_table();
    }
}
void MainWindow::on_btn_del_body_clicked()
{
    if (stack->count() == 0)
        QMessageBox::warning(this, "Delete", "Stack is empty.");
    else if (stack->count() == 1)
    {
        stack->pop();
        open_table();
    }
    else
    {
        stack->pop();
        generate_table();
    }
}
void MainWindow::on_btn_report_clicked()
{
    bool b = stack->isStand();
    QString s;
    if (stack->count() == 0)
        s = "Stack is empty.";
    if (stack->count() > 0 && b)
        s = "Stack is stable";
    if (stack->count() > 0 && !b)
        s = "Stack is unstable";
    if (s == "Stack is empty.") QMessageBox::warning(this, "Check", s);
    else
    QMessageBox::information(this, "Check standing", s);
}
void MainWindow::on_btn_save_clicked() const
{
    QString fileName = QFileDialog::getSaveFileName(0, tr("Save list of tracks"),
                                                    QDir::currentPath(),
                                                    "TXT file (*.txt)");
    stack->output(fileName.toStdString());
}
void MainWindow::on_btn_open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open list of tracks"),
                                                    QDir::currentPath(),
                                                    "TXT file (*.txt)");
    stack->input(fileName.toStdString());
    generate_table();
}

void MainWindow::on_btn_clear_clicked()
{
    if (stack->count() == 0)
        QMessageBox::warning(this, "Delete", "Stack is empty.");
    else
    {
    stack->delAll();
    open_table();
    }
}
void MainWindow::on_btn_change_clicked()
{
    AddObject *window = new AddObject;
    Iterator it = stack->begin();
    ind = getIndexChange() - 1;
    if (stack->count() == 0) QMessageBox::warning(this, "Change", "Stack is empty.");
    else if (ind < stack->count() && ind >=0){
        for (int i = 0; i<ind; i++)
        {
            it.incr();
        }
        if (it.get()->who() == "Plate") window->setChangePlate(it);
        else if (it.get()->who() == "Paper") window->setChangePaper(it);
        if (window->exec())
        {
            if (it.get()->who() == "Plate")
            {
                Plate *temp = dynamic_cast<Plate*>(it.get());
                x = window->getX().toDouble();
                y = window->getY().toDouble();
                thicknes = window->getThickness().toDouble();
                radius = window->getRadius().toDouble();
                temp->setCoordinateX(x);
                temp->setCoordinateY(y);
                temp->setThickness(thicknes);
                temp->setRadius(radius);
                generate_table();
            }
            else if (it.get()->who() == "Paper")
            {
                Paper *temp = dynamic_cast<Paper*>(it.get());
                x = window->getX().toDouble();
                y = window->getY().toDouble();
                thicknes = window->getThickness().toDouble();
                width = window->getWidth().toDouble();
                height = window->getHeight().toDouble();
                temp->setCoordinateX(x);
                temp->setCoordinateY(y);
                temp->setThickness(thicknes);
                temp->setWidth(width);
                temp->setHeight(height);
                generate_table();
            }
        }

    }
    else QMessageBox::warning(this, "Change", "The entered length outside the stack");
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stacklength.h"
#include "addobject.h"

#include "paperstack.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int length, ind;
    double x, y, thicknes, height, width, radius;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btn_stack_clicked();

    void on_btn_add_paper_clicked();

    void on_btn_add_plate_clicked();

    void on_btn_del_body_clicked();

    void on_btn_report_clicked();

    void on_btn_save_clicked() const;

    void on_btn_open_clicked();

    void on_btn_clear_clicked();

    void on_btn_change_clicked();

private:
    void generate_table();
    void open_table();
    int getIndexChange();
    Ui::MainWindow *ui;
    PaperStack *stack;
};

#endif // MAINWINDOW_H

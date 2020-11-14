#ifndef STACKLENGTH_H
#define STACKLENGTH_H

#include <QDialog>

namespace Ui {
class StackLength;
}

class StackLength : public QDialog
{
    Q_OBJECT

public:
    QString text;
    explicit StackLength(QWidget *parent = nullptr);
    ~StackLength();
    QString getLength() const;

private:
    Ui::StackLength *ui;
};

#endif // STACKLENGTH_H

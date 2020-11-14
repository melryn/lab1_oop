#ifndef ADDOBJECT_H
#define ADDOBJECT_H
#include "paperstack.h"

#include <QDialog>

namespace Ui {
class AddObject;
}

class AddObject : public QDialog
{
    Q_OBJECT

public:
    explicit AddObject(QWidget *parent = nullptr);
    ~AddObject();
    void setPaper();
    void setPlate();
    void setChangePaper(Iterator it);
    void setChangePlate(Iterator it);
    QString getX() const;
    QString getY() const;
    QString getThickness() const;
    QString getWidth() const;
    QString getHeight() const;
    QString getRadius() const;


private:
    Ui::AddObject *ui;
};

#endif // ADDOBJECT_H

#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include"mydatabase.h"
namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::admin *ui;
};

#endif // ADMIN_H

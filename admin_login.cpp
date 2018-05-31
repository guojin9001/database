#include "admin_login.h"
#include "ui_admin_login.h"
#include<QDebug>
admin_login::admin_login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_login)
{
    ui->setupUi(this);
}

admin_login::~admin_login()
{
    delete ui;
}

void admin_login::on_pushButton_clicked()
{
    this->hide();
    emit retsig();
}

void admin_login::on_pushButton_2_clicked()
{
    int id=ui->lineEdit->text().toInt();
    QString pw=ui->lineEdit_2->text();
    mydatabase data=mydatabase();
    data.openDatabase();
    QSqlDatabase db=data.getConnection();
    QSqlQuery query=QSqlQuery(db);
    query.prepare("select adminID,password from admin");
    if(query.exec())
    {
        while (query.next()) {
            if(id==query.value(0).toInt()&&pw==query.value(1).toString())
            {
                qDebug()<<"ok";
                data.closeDatabase();
                admin *ad=new admin();
                ad->show();
                this->hide();
                return;
            }
        }
    }
    data.closeDatabase();
}

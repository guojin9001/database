#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_2_clicked()
{

    mydatabase data=mydatabase();
    data.openDatabase();
    QSqlDatabase db=data.getConnection();
    QSqlQuery query=QSqlQuery(db);
    query.prepare("insert into book(bname,author,publisher,pubtime) values(?,?,?,?)");


    QString bookname=ui->lineEdit_4->text();
    if(bookname=="") {
        QMessageBox::information(NULL,"警告","please input book name",QMessageBox::Yes,QMessageBox::No);
        return;
    }
    query.bindValue(0,bookname);

    QString author=ui->lineEdit_7->text();
    if(author=="") QMessageBox::information(NULL,"警告","请输入作者名",QMessageBox::Yes,QMessageBox::No);
    query.bindValue(1,author);


    QString publisher=ui->lineEdit_3->text();
    if(publisher=="") query.bindValue(2,NULL);
    else query.bindValue(2,publisher);

    QDate pubtime=ui->dateEdit->date();
   query.bindValue(4,QVariant());
    if(query.exec())
        QMessageBox::information(NULL,"提示","录入成功",QMessageBox::Yes,QMessageBox::No);
    data.closeDatabase();
}

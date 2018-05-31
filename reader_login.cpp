#include "reader_login.h"
#include "ui_reader_login.h"

reader_login::reader_login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reader_login)
{
    ui->setupUi(this);
}

reader_login::~reader_login()
{
    delete ui;
}

void reader_login::on_pushButton_clicked()
{
    this->hide();
    emit retsig();
}

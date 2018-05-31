#ifndef MYDATABASE_H
#define MYDATABASE_H
#include<QMessageBox>//信号箱子，用来返回数据库是否能成功打开的信息
#include <QSqlDatabase>//数据库的头文件
#include <QSqlError>//出错处理头文件
#include<QSqlQuery>
class mydatabase
{
public:
    mydatabase();
    void openDatabase();
    QSqlDatabase getConnection();
    void closeDatabase();
private:
    QSqlDatabase db;
};

#endif // MYDATABASE_H

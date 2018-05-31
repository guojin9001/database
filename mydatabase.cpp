#include "mydatabase.h"
#include<QDebug>
#include<QSqlQuery>
mydatabase::mydatabase()
{

}
void mydatabase::openDatabase()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QODBC");
        qDebug()<<"ODBC driver?"<<db.isValid();
        QString dsn = QString::fromLocal8Bit("qt");      //数据源名称
        db.setHostName("localhost");                        //选择本地主机，127.0.1.1
        db.setDatabaseName(dsn);                            //设置数据源名称
        db.setUserName("sa");                               //登录用户
        db.setPassword("sa123");

    if (!db.open())
    {
        QSqlError error=db.lastError();

        qDebug()<<error;
    }
    else
    {
        qDebug()<<"Connect to Database Success!";
    }
}
QSqlDatabase mydatabase::getConnection()
{
    return db;
}
void mydatabase::closeDatabase()
{
    db.close();
}


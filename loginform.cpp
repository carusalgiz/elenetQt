#include "loginform.h"
#include "ui_loginform.h"
#include <QSqlDatabase>
#include <QHostInfo>
#include <QSqlQuery>
#include "QSqlError"
#include <QFile>

loginForm::loginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginForm)
{
    ui->setupUi(this);
}

loginForm::~loginForm()
{
    delete ui;
}

void loginForm::setConnectionState(bool state) {
    if (state != connection) {
        connection = state;
        emit conStateChanged(state);
    }

}

void loginForm::on_BtnLogin_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL Server};Server=DATABASE;DATABASE=KHVERTRADE;");
    db.setUserName(ui->EditLogin->text());
    db.setPassword(ui->EditPass->text());
    setConnectionState(db.open());
    qDebug() << connection;
    if (connection) {
        ui->infoLabel->setText("Успешный вход");

    } else {
        ui->infoLabel->setText("Проверьте правильность написания логина и пароля");
        qDebug()<<"ERROR: "<<QSqlError(db.lastError()).text();
    }
}

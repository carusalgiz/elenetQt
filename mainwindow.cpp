#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    uiLogin = new loginForm(this);
    connect(uiLogin, SIGNAL(conStateChanged(bool)), this, SLOT(setConnectionState(bool)));
    this -> hide();
    uiLogin->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setConnectionState(bool state) {
    if (state != connection && state == true) {
        connection = state;
        uiLogin->close();
        this->show();
    }
}


void MainWindow::on_btnGetObjectsList_clicked()
{
    uiObjectsList = new ObjectsListView(this);
    uiObjectsList->show();
}

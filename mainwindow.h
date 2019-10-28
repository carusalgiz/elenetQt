#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginform.h"
#include "objectslistview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setConnectionState(bool state);

    void on_btnGetObjectsList_clicked();

private:
    Ui::MainWindow *ui;
    loginForm *uiLogin;
    ObjectsListView *uiObjectsList;
    bool connection;
};
#endif // MAINWINDOW_H

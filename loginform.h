#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>

namespace Ui {
class loginForm;
}

class loginForm : public QDialog
{
    Q_OBJECT

public:
    explicit loginForm(QWidget *parent = nullptr);
    ~loginForm();

private slots:
    void on_BtnLogin_clicked();
    void setConnectionState(bool state);

signals:
    void conStateChanged(bool state);

private:
    Ui::loginForm *ui;
    bool connection = false;
};

#endif // LOGINFORM_H

#ifndef OBJECTSLISTVIEW_H
#define OBJECTSLISTVIEW_H

#include <QMainWindow>
#include <QSqlQueryModel>

namespace Ui {
class ObjectsListView;
}

class ObjectsListView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ObjectsListView(QWidget *parent = nullptr);
    ~ObjectsListView();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ObjectsListView *ui;
    QSqlQueryModel *getObjectsQuery;
};

#endif // OBJECTSLISTVIEW_H

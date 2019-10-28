#include "objectslistview.h"
#include "ui_objectslistview.h"
#include <QSqlQueryModel>
#include <QDebug>

ObjectsListView::ObjectsListView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ObjectsListView)
{
    ui->setupUi(this);
    getObjectsQuery = new QSqlQueryModel;
    getObjectsQuery->setQuery("SELECT obj_id, obj_name, v_lstObj.con_name , obj_addressShort, tObj_name, eRegion_name, eObj_lic, obj_extId, objNetT_name, obj_creator FROM elenet.dbo.v_lstObj  LEFT JOIN elenet.dbo.lstEObj on eObj_id = obj_id  LEFT JOIN elenet.dbo.lstERegion on eObj_regionId = eRegion_id  LEFT JOIN (     SELECT       eNachSet_objId,       eTNach_name,       eNachSet_date     FROM       elenet.dbo.regENachSetup       INNER JOIN elenet.dbo.lstETypNach on eTNach_id = eNachSet_tNachId     WHERE eNachSet_dateEnd IS NULL  ) t2 on t2.eNachSet_objId = obj_id  LEFT JOIN elenet.dbo.deviationItem on obj_id = deviationItem_objId  left join elenet.dbo.lstCon on v_lstObj.con_id = lstCon.con_id left join elenet.dbo.objNetType on eObj_netTypeId = objNetT_id  WHERE obj_trashBin = 0");
    ui->tableObjectsList->setModel(getObjectsQuery);
    QString headers[] = {"Код","Наименование","Владелец","Адрес","Тип","Участок","Лицевой счет","Код обмена","Тип в сети", "Создатель"};
    for (int i = 0; i < getObjectsQuery->columnCount();i++) {
        getObjectsQuery->setHeaderData(i,Qt::Horizontal,headers[i]);
    }
    while(getObjectsQuery->canFetchMore()) getObjectsQuery->fetchMore();
}

ObjectsListView::~ObjectsListView()
{
    delete ui;
}

void ObjectsListView::on_pushButton_clicked()
{
    getObjectsQuery = new QSqlQueryModel;
    QString code = " and obj_id="+ ui->objCodeFindEdit->text();
    QString house = " and obj_house="+ ui->houseFindEdit->text();
    QString street = " and street_name like '%"+ ui->streetFindEdit->text() + "%'";
    QString korp = " and obj_korp='"+ ui->korpFindEdit->text() + "'";
    QString query = "SELECT obj_id, obj_name, v_lstObj.con_name , obj_addressShort, tObj_name, eRegion_name, eObj_lic, obj_extId, objNetT_name, obj_creator FROM elenet.dbo.v_lstObj  LEFT JOIN elenet.dbo.lstEObj on eObj_id = obj_id  LEFT JOIN elenet.dbo.lstERegion on eObj_regionId = eRegion_id  LEFT JOIN (     SELECT       eNachSet_objId,       eTNach_name,       eNachSet_date     FROM       elenet.dbo.regENachSetup       INNER JOIN elenet.dbo.lstETypNach on eTNach_id = eNachSet_tNachId     WHERE eNachSet_dateEnd IS NULL  ) t2 on t2.eNachSet_objId = obj_id  LEFT JOIN elenet.dbo.deviationItem on obj_id = deviationItem_objId  left join elenet.dbo.lstCon on v_lstObj.con_id = lstCon.con_id left join elenet.dbo.objNetType on eObj_netTypeId = objNetT_id  WHERE obj_trashBin = 0";
    if (ui->objCodeFindEdit->text() != nullptr) {
       query += code;
    }
    if (ui->streetFindEdit->text() != nullptr) {
       query += street;
    }
    if (ui->houseFindEdit->text() != nullptr) {
       query += house;
    }
    if (ui->korpFindEdit->text() != nullptr) {
       query += korp;
    }
    getObjectsQuery->setQuery(query);
    ui->tableObjectsList->setModel(getObjectsQuery);
    QString headers[] = {"Код","Наименование","Владелец","Адрес","Тип","Участок","Лицевой счет","Код обмена","Тип в сети", "Создатель"};
    for (int i = 0; i < getObjectsQuery->columnCount();i++) {
        getObjectsQuery->setHeaderData(i,Qt::Horizontal,headers[i]);
    }
    while(getObjectsQuery->canFetchMore()) getObjectsQuery->fetchMore();
}

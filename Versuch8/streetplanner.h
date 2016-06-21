#ifndef STREETPLANNER_H
#define STREETPLANNER_H

#include "city.h"
#include "map.h"
#include "street.h"
#include "dialog.h"
#include "mapionrw.h"

#include <QMainWindow>
#include <QtDebug>
#include <QGraphicsScene>

namespace Ui {
class StreetPlanner;
}

class StreetPlanner : public QMainWindow
{
    Q_OBJECT

public:
    explicit StreetPlanner(QWidget *parent = 0);
    ~StreetPlanner();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_checkBox_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::StreetPlanner *ui;
    QGraphicsScene scene;
    Map CityMap;
    MapIo *mapIO;
    bool Testing = false;
};

#endif // STREETPLANNER_H

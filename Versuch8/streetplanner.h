#ifndef STREETPLANNER_H
#define STREETPLANNER_H


#include "city.h"
#include "map.h"
#include "street.h"
#include "dialog.h"
#include "mapionrw.h"
#include "mapiofileinput.h"
#include "dijkstra.h"

#include <QMainWindow>
#include <QtDebug>
#include <QGraphicsScene>
#include <QFileDialog>

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

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::StreetPlanner *ui;
    QGraphicsScene scene;
    Map CityMap;
    MapIo *mapIO;
    bool Testing = false;

    // Einlesen der Benutzereingaben und Ausgabe auf der Konsole
    bool testSimpleUi();
    // In der GUI zeichnen
    bool testSimpleDrawing();
    // Eine Stadt anlegen und zeichnen
    bool testDrawCities();
    // Hinzufügen von Städten zu einer Karte und Zeichnen der Städte über die Karte
    bool testDrawMapWithCities();
    bool testDrawStreets();
    bool testDrawMapWithStreets();
    bool testRejectStreet(Map *map, Street *street, bool expected);
    // Einen Dialog anzeigen
    bool testShowDialog();
    // Diese Funktion testet, ob die Klasse Map das Interface "AbstractMap" korrekt implementiert.
    bool testAbstractMap();
    // Dijkstra algorithmus testen
    bool testDijkstra();
};

#endif // STREETPLANNER_H

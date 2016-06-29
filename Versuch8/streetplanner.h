#ifndef STREETPLANNER_H
#define STREETPLANNER_H


#include "city.h"
#include "map.h"
#include "street.h"
#include "dialog.h"
#include "newstreetdialog.h"
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

/**
 * @brief Main class. Inheriting from QMainWindow
 */
class StreetPlanner : public QMainWindow
{
    Q_OBJECT

public:
    explicit StreetPlanner(QWidget *parent = 0);
    ~StreetPlanner();

private slots:
    /**
     * @brief Test Slot button
     */
    void on_pushButton_clicked();

    /**
     * @brief Test Draw City button
     */
    void on_pushButton_2_clicked();

    /**
     * @brief Test Draw Map button
     */
    void on_pushButton_3_clicked();

    /**
     * @brief Test Draw Street button
     */
    void on_pushButton_4_clicked();

    /**
     * @brief Test Street in Map button
     */
    void on_pushButton_5_clicked();

    /**
     * @brief Checkbox toggling test button visibility
     */
    void on_checkBox_clicked();

    /**
     * @brief Add City button
     */
    void on_pushButton_6_clicked();

    /**
     * @brief Fill Map button
     */
    void on_pushButton_7_clicked();

    /**
     * @brief Test Abstract Map button
     */
    void on_pushButton_8_clicked();

    /**
     * @brief Test Dijkstra button
     */
    void on_pushButton_9_clicked();

    /**
     * @brief Find Path button
     */
    void on_pushButton_10_clicked();

    /**
     * @brief Add Street button
     */
    void on_pushButton_11_clicked();

private:
    Ui::StreetPlanner *ui;      //! Reference to this class
    QGraphicsScene scene;       //! Main scene to draw to
    Map CityMap;                //! Main map
    MapIo *mapIO;               //! For loading maps
    bool Testing = false;       //! Visibility of test buttons

    // -------------------------------- TEST FUNCTIONS -----------------------------------
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

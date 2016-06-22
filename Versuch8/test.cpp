/*
 * In dieser Datei finden Sie einige Beispiele für Funktions-Tests,
 * die im Versuch "GUI-Programmierung mit Qt" benötigt werden.
 */

#include "streetplanner.h"
#include "ui_streetplanner.h"

// Einlesen der Benutzereingaben und Ausgabe auf der Konsole
bool StreetPlanner::testSimpleUi()
{
    QString pattern = "The user's input: %1";
    QString s = pattern.arg(ui->lineEdit->text());
    qDebug() << s;
}

// In der GUI zeichnen
bool StreetPlanner::testSimpleDrawing()
{
    scene.addRect(50, 20, 50, 100);
}

// Eine Stadt anlegen und zeichnen
bool StreetPlanner::testDrawCities()
{
    City c1("city c1", 20,50);
    c1.draw(scene);
}

// Hinzufügen von Städten zu einer Karte und Zeichnen der Städte über die Karte
bool StreetPlanner::testDrawMapWithCities()
{
    City c1("city c1", 20,50);
    CityMap.addCity(&c1);
    CityMap.draw(scene);
}

bool StreetPlanner::testDrawStreets()
{

}

bool StreetPlanner::testDrawMapWithStreets()
{

}

bool StreetPlanner::testRejectStreet()
{

}

// Einen Dialog anzeigen
bool StreetPlanner::testShowDialog()
{
    Dialog dialog(CityMap);
    int result = dialog.exec();
    qDebug() << QString("Dialog result: %1").arg(result);

    return true;
}

// Diese Funktion testet, ob die Klasse Map das Interface "AbstractMap" korrekt implementiert.
bool StreetPlanner::testAbstractMap()
{
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);
    bool passed = true;

    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = CityMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
            passed = false;
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        CityMap.addCity(a);
        CityMap.addCity(b);
        bool t1 = CityMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
            passed = false;
        }
    }

    {
        qDebug() << "MapTest: find city";
        City* city = CityMap.find_city("a");
        if (city != a)
        {
            qDebug() << "-Error: City a could not be found.";
            passed = false;
        }

        city = CityMap.find_city("b");
        if (city != b)
        {
            qDebug() << "-Error: City b could not be found.";
            passed = false;
        }

        city = CityMap.find_city("c");
        if (city != NULL)
        {
            qDebug() << "-Error: If city could not be found 0 should be returned.";
            passed = false;
        }
    }

    CityMap.addCity(c);
    CityMap.addStreet(s2);

    {
        qDebug() << "MapTest: get_opposite_city";
        const City *city = CityMap.get_opposite_city(s, a);
        if (city != b)
        {
            qDebug() << "-Error: Opposite city should be b.";
            passed = false;
        }

        city = CityMap.get_opposite_city(s, c);
        if (city != 0)
        {
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
            passed = false;
        }
    }

    {
        qDebug() << "MapTest: street_length";
        double l = CityMap.get_length(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
        {
            qDebug() << "-Error: Street Length is not equal to the expected.";
            passed = false;
        }

    }

    {
        qDebug() << "MapTest: get_street_list";
        AbstractMap::StreetList streetList1 = CityMap.get_street_list(a);
        AbstractMap::StreetList streetList2 = CityMap.get_street_list(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
            passed = false;
        }
        else if (*streetList1.begin() != s) {
                qDebug() << "-Error: The wrong street has been found for city a.";
                passed = false;
        }

        if (streetList2.size() != 2)
        {
            qDebug() << "-Error: Two streets should be found for city b.";
            passed = false;
        }
    }

    qDebug() << "MapTest: End Test of the Map.";

    return passed;
}

bool StreetPlanner::testDijkstra()
{
    // Fill map with dummy
    mapIO->fillMap(CityMap);
    CityMap.draw(scene);

    // Search
    Map::StreetList path = Dijkstra::search(CityMap, "Bonn", "Düsseldorf");

    // Draw path in red
    for (Street* i: path)
        i->drawRed(scene);
}

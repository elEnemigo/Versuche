#include "streetplanner.h"
#include "ui_streetplanner.h"

StreetPlanner::StreetPlanner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StreetPlanner)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);

    // Hide testing panel initially
    ui->pushButton->setVisible(Testing);
    ui->pushButton_2->setVisible(Testing);
    ui->pushButton_3->setVisible(Testing);
    ui->pushButton_4->setVisible(Testing);
    ui->pushButton_5->setVisible(Testing);
    ui->pushButton_8->setVisible(Testing);
    ui->pushButton_9->setVisible(Testing);

    // MapIO
    mapIO = new MapIoNrw;
}

StreetPlanner::~StreetPlanner()
{
    delete ui;
}

// Checkbox: Toggle Test Buttons
void StreetPlanner::on_checkBox_clicked()
{
    ui->checkBox->isChecked() ? Testing = true : Testing = false;   // Toggle visibility

    ui->pushButton->setVisible(Testing);
    ui->pushButton_2->setVisible(Testing);
    ui->pushButton_3->setVisible(Testing);
    ui->pushButton_4->setVisible(Testing);
    ui->pushButton_5->setVisible(Testing);
    ui->pushButton_8->setVisible(Testing);
    ui->pushButton_9->setVisible(Testing);
}

// Button: Add City
void StreetPlanner::on_pushButton_6_clicked()
{
    Dialog Input(CityMap);
    int RetVal;
    City *newCity = nullptr;

    // Dialog returns 1 for "OK" and 0 for "Cancel"
    RetVal = Input.exec();
    qDebug() << QString("Dialog return value is %1").arg(RetVal);

    if (RetVal)
    {
        newCity = Input.ProcessInput();

        if (newCity)
        {
            CityMap.addCity(newCity);
            CityMap.draw(scene);

            qDebug() << QString("%1 created @ (%2:%3)").arg(newCity->getName()).arg(newCity->getX()).arg(newCity->getY());

            // Update combo box
            ui->comboBox->addItem(newCity->getName());
            ui->comboBox_2->addItem(newCity->getName());
        }
        else
        {
            qDebug() << "No new city added! Try again";
            on_pushButton_6_clicked();
        }
    }
}

// Button: Fill Map
void StreetPlanner::on_pushButton_7_clicked()
{
    // Let user choose map to import
    QString cityFile, streetFile;
    QFileDialog selectCity;
    selectCity.setWindowTitle("Select cities file");
    if (selectCity.exec())
    {
        cityFile = selectCity.selectedFiles().at(0);
        selectCity.setWindowTitle("Select streets file");
        if (selectCity.exec())
        {
            streetFile = selectCity.selectedFiles().at(0);
            mapIO = new MapIoFileinput(cityFile, streetFile);
            qDebug() << cityFile << "\n" << streetFile;
        }
    }

    // Fill map
    mapIO->fillMap(CityMap);

    // Draw map
    CityMap.draw(scene);

    // Update combo box
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    for (City * i: CityMap.get_city_list())
    {
        ui->comboBox->addItem(i->getName());
        ui->comboBox_2->addItem(i->getName());
    }
}

// Button: Find Path
void StreetPlanner::on_pushButton_10_clicked()
{
    QString cityA = ui->lineEdit->text();
    QString cityB = ui->lineEdit_2->text();

    // If lineEdits empty -> get value from combobox
    if (ui->lineEdit->text().isEmpty())
        cityA = ui->comboBox->currentText();
    if (ui->lineEdit_2->text().isEmpty())
        cityB = ui->comboBox_2->currentText();

    // Redraw map
    CityMap.draw(scene);

    // Search
    Map::StreetList path = Dijkstra::search(CityMap, cityA, cityB);

    // Draw path in red
    for (Street* i: path)
        i->drawRed(scene);
}


/* --------------------------------------- TEST BUTTONS ------------------------------------------ */

// Button: Test Slot
void StreetPlanner::on_pushButton_clicked()
{
    // Parse lineEdit text
    testSimpleUi();

    // Draw random rectangle
    testSimpleDrawing();
}

// Button: Test Draw City
void StreetPlanner::on_pushButton_2_clicked()
{
    testDrawCities();
}

// Button: Test Draw Map
void StreetPlanner::on_pushButton_3_clicked()
{
    testDrawMapWithCities();
}

// Button: Test Draw Street
void StreetPlanner::on_pushButton_4_clicked()
{
    testDrawStreets();
}

// Button: Test Street in Map
void StreetPlanner::on_pushButton_5_clicked()
{
    testDrawMapWithStreets();
}

// Button: Test Abstract Map
void StreetPlanner::on_pushButton_8_clicked()
{
    if (testAbstractMap())
        qDebug() << "Passed abstract map test!";
    else
        qDebug() << "Failed abstract map test!";
}

// Button: Test Dijkstra
void StreetPlanner::on_pushButton_9_clicked()
{
    testDijkstra();
}

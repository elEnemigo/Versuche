#include "streetplanner.h"
#include "ui_streetplanner.h"

StreetPlanner::StreetPlanner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StreetPlanner)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
}

StreetPlanner::~StreetPlanner()
{
    delete ui;
}

void StreetPlanner::on_pushButton_clicked()
{
    // Parse lineEdit text
    QString strLineEdit(ui->lineEdit->text());
    int num = strLineEdit.toInt();
    if (num == 0)
        qDebug() << QString("Button pressed! Text: %1").arg(strLineEdit);
    else
        qDebug() << QString("Button pressed! Number: %1").arg(num + 4);

    // Draw random rectangle
    int xpos, ypos;
    xpos = qrand() * ui->graphicsView->sceneRect().width() / RAND_MAX;
    ypos = qrand() * ui->graphicsView->sceneRect().height() / RAND_MAX;
    scene.addRect(xpos, ypos, 10, 10);
}

void StreetPlanner::on_pushButton_2_clicked()
{
    City A(QString("City A"), -50, 13);
    City B(QString("City B"), 20, -18);

    A.draw(scene);
    B.draw(scene);
}

void StreetPlanner::on_pushButton_3_clicked()
{
    Map TestMap;

    City C(QString("City C"), 50, 13);
    City D(QString("City D"), -20, -18);

    TestMap.addCity(&C);
    TestMap.addCity(&D);

    TestMap.draw(scene);
}

void StreetPlanner::on_pushButton_4_clicked()
{
    City A(QString("City A"), -50, 13);
    City B(QString("City B"), 20, -18);

    Street TestStreet(&A, &B);

    TestStreet.draw(scene);
}

void StreetPlanner::on_pushButton_5_clicked()
{
    Map TestMap;

    City A(QString("City A"), -50, 13);
    City B(QString("City B"), 20, -18);
    City C(QString("City C"), 50, 13);
    City D(QString("City D"), -20, -18);

    TestMap.addCity(&C);
    TestMap.addCity(&D);

    Street TestStreet1(&A, &B);
    Street TestStreet2(&C, &D);

    if (TestMap.addStreet(&TestStreet1))
        qDebug() << "ERROR: TestStreet1 was wrongly added to the Map";
    else
        qDebug() << "TestStreet1 was handled correctly";

    if (!TestMap.addStreet(&TestStreet2))
        qDebug() << "ERROR: TestStreet2 was not added to the Map";
    else
        qDebug() << "TestStreet2 was handled correctly";
}

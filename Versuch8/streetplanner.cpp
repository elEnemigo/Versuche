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

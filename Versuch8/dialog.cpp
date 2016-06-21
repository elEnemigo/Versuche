#include "dialog.h"
#include "ui_dialog.h"
#include "streetplanner.h"

Dialog::Dialog(Map &CityMap, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    City_Map(CityMap)
{
    ui->setupUi(this);

    // Draw map
    scene.setUI(ui);
    ui->graphicsView->setScene(&scene);
    CityMap.draw(scene);
}

Dialog::~Dialog()
{
    delete ui;
}

City* Dialog::ProcessInput() const
{
    City* newCity = nullptr;

    if (scene.CitySet)
    {
        if (!ui->lineEdit->text().isEmpty())
            newCity = new City(ui->lineEdit->text(), scene.origPoint.x(), scene.origPoint.y());
        else
            qDebug() << "No city name entered!";
    }

    return newCity;
}

CustomScene::CustomScene(QObject* parent) :
    CitySet(false)
{
    //this->parent = parent;
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    qDebug() << "HIT IT!";

    if (mouseEvent->button() == Qt::LeftButton)
    {
        // Handle button press
        origPoint = mouseEvent->scenePos();
        mouseEvent->accept();
        CitySet = true;

        // Feedback for user
        refUi->label_2->setText(QString("X: %1 | Y: %2").arg(origPoint.x()).arg(origPoint.y()));

        return;
    }

    mouseEvent->ignore();
}

void CustomScene::setUI(Ui::Dialog* UI)
{
    refUi = UI;
}

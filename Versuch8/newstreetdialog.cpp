#include "newstreetdialog.h"
#include "ui_newstreetdialog.h"

NewStreetDialog::NewStreetDialog(Map *CityMap, QWidget *parent) :
    map(CityMap), QDialog(parent),
    ui(new Ui::NewStreetDialog)
{
    ui->setupUi(this);

    // Update combo box
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    for (City * i: CityMap->get_city_list())
    {
        ui->comboBox->addItem(i->getName());
        ui->comboBox_2->addItem(i->getName());
    }
}

NewStreetDialog::~NewStreetDialog()
{
    delete ui;
}

void NewStreetDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if (ui->comboBox->currentText() != ui->comboBox_2->currentText())
    {
        City* A = map->find_city(ui->comboBox->currentText());
        City* B = map->find_city(ui->comboBox_2->currentText());

        if (A && B)
        {
            qDebug() << QString("Connecting %1 and %2").arg(A->getName()).arg(B->getName());
            Street* newStreet = new Street(A, B);
            //qDebug() << QString("Connected %1 and %2").arg(newStreet.getA()->getName()).arg(newStreet.getB()->getName());
            map->addStreet(newStreet);
        }
        else
            qDebug() << "Cities don't exist";
    }
    else
        qDebug() << "Select two DIFFERENT cities";
}

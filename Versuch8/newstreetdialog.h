#ifndef NEWSTREETDIALOG_H
#define NEWSTREETDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include "map.h"

namespace Ui {
class NewStreetDialog;
}

class NewStreetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewStreetDialog(Map *CityMap, QWidget *parent = 0);
    ~NewStreetDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::NewStreetDialog *ui;
    Map* map;
};

#endif // NEWSTREETDIALOG_H

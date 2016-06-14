#ifndef STREETPLANNER_H
#define STREETPLANNER_H

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

private:
    Ui::StreetPlanner *ui;
    QGraphicsScene scene;
};

#endif // STREETPLANNER_H

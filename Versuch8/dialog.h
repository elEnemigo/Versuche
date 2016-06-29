#ifndef DIALOG_H
#define DIALOG_H

#include "city.h"
#include "map.h"
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

namespace Ui {
class Dialog;
}

/**
 * @brief Implementing a custom scene. Inherited from QGraphicsScene
 */
class CustomScene : public QGraphicsScene
{
public:
    CustomScene(QObject* parent = 0);
    void setUI(Ui::Dialog *UI);

    friend class Dialog;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    QPointF origPoint;
    Ui::Dialog *refUi;
    bool CitySet;
};

/**
 * @brief Dialog. Inherited from QDialog
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(Map &CityMap, QWidget *parent = 0);
    ~Dialog();

    /**
     * @brief Processes user input.
     * @return  Returns newly created city if input valid. Otherwise nullptr
     */
    City* ProcessInput() const;

private:
    Ui::Dialog *ui;
    CustomScene scene;
    Map City_Map;
};



#endif // DIALOG_H

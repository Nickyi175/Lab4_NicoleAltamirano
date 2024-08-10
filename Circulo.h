#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura.h"
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QGraphicsScene>

class Circulo : public Figura {
public:
    Circulo(qreal x, qreal y, qreal diameter) {
        item = new QGraphicsEllipseItem(x, y, diameter, diameter);
        item->setBrush(QBrush(QColor(255, 0, 127)));
    }

    QGraphicsItem* getItem() const override {
        return item;
    }

    void draw(QGraphicsScene *scene) const override {
        scene->addItem(item);
    }

private:
    QGraphicsEllipseItem *item;
};

#endif // CIRCULO_H

#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura.h"
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsScene>

class Rectangulo : public Figura {
public:
    Rectangulo(qreal x, qreal y, qreal width, qreal height) {
        item = new QGraphicsRectItem(x, y, width, height);
        item->setBrush(QBrush(QColor(128, 0, 128)));  // Color de relleno
    }

    QGraphicsItem* getItem() const override {
        return item;
    }

    void draw(QGraphicsScene *scene) const override {
        scene->addItem(item);
    }

private:
    QGraphicsRectItem *item;
};

#endif // RECTANGULO_H

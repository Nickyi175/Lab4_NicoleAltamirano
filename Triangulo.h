#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"
#include <QGraphicsPolygonItem>
#include <QBrush>
#include <QPolygonF>

class Triangulo : public Figura {
public:
    Triangulo(qreal x, qreal y) {
        QPolygonF triangle;
        triangle << QPointF(0, 0) << QPointF(100, 0) << QPointF(50, 86.6);  // Vertices del triángulo
        item = new QGraphicsPolygonItem(triangle);
        item->setBrush(QBrush(Qt::blue));  // Color de relleno
        item->setPos(x, y);  // Posicionarlo
    }

    QGraphicsItem* getItem() const override {
        return item;
    }

    void draw(QGraphicsScene *scene) const override {
        scene->addItem(item);
    }

private:
    QGraphicsPolygonItem *item;
};

#endif // TRIANGULO_H

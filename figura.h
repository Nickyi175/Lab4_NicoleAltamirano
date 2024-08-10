#ifndef FIGURA_H
#define FIGURA_H
#include <QGraphicsItem>
#include <QGraphicsScene>
class Figura
{
public:
    virtual ~Figura() {}
    virtual QGraphicsItem* getItem() const = 0;  // Pure virtual method to get the QGraphicsItem
    virtual void draw(QGraphicsScene *scene) const = 0;
};

#endif // FIGURA_H

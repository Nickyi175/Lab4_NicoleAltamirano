#ifndef ROPA_H
#define ROPA_H
#include "Producto.h"

class Ropa : public Producto
{
private:
    int talla;
    QString color;

public:
    Ropa(QString nombreProd, double precioProd, int cantidadProd, int talla, QString color)
        : Producto(nombreProd, precioProd, cantidadProd), talla(talla), color(color) {}

    QString getInfo() const override {
        return Producto::getInfo() + QString(", Talla: %1, Color: %2").arg(QString::number(talla)).arg(color);
    }

};

#endif // ROPA_H

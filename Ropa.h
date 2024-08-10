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
        return Producto::getInfo() + QString("Talla: "+QString::number(talla)+"\nColor: "+ color );
    }

    int getTalla() const { return talla; }
    QString getColor() const { return color; }

    void setTalla(int t) { talla = t; }
    void setColor(const QString &col) { color = col; }

};

#endif // ROPA_H

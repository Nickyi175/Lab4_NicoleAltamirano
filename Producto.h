#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <QString>
#include "iostream"

class Producto
{
public:
    Producto(QString nombreProd, double precioProd, int cantidadProd)
        : nombreProd(nombreProd), precioProd(precioProd), cantidadProd(cantidadProd) {}

    virtual ~Producto() {}

    virtual QString getInfo() const {
        return QString("Nombre: "+nombreProd+"\nPrecio: "+ QString::number(precioProd)+"\nCantidad: "+QString::number(cantidadProd)+"\n");
    }

private:
    int cantidadProd;
    double precioProd;
    QString nombreProd;

};

#endif // PRODUCTO_H

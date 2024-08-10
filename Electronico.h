#ifndef ELECTRONICO_H
#define ELECTRONICO_H
#include "Producto.h"

class Electronico : public Producto
{
public:
    Electronico(QString nombreProd, double precioProd, int cantidadProd, QString marca, QString modelo)
        : Producto(nombreProd, precioProd, cantidadProd), marca(marca), modelo(modelo) {}

    QString getInfo() const override {
        return Producto::getInfo() + QString("Marca: "+marca+"\nTipo de electrónico: "+ modelo);
    }
private:
    QString marca;
    QString modelo;
};

#endif // ELECTRONICO_H

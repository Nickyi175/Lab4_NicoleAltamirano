#ifndef ELECTRONICO_H
#define ELECTRONICO_H
#include "Producto.h"

class Electronico : public Producto
{
private:
    QString marca;
    QString modelo;
public:
    Electronico(QString nombreProd, double precioProd, int cantidadProd, QString marca, QString modelo)
        : Producto(nombreProd, precioProd, cantidadProd), marca(marca), modelo(modelo) {}

    QString getInfo() const override {
        return Producto::getInfo() + QString("Marca: "+marca+"\nTipo de electrónico: "+ modelo);
    }

    QString getMarca() const { return marca; }
    QString getModelo() const { return modelo; }

    void setMarca(const QString &m) { marca = m; }
    void setModelo(const QString &mod) { modelo = mod; }


};

#endif // ELECTRONICO_H

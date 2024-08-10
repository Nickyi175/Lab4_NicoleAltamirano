#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <QString>
#include "iostream"

class Producto
{
private:
    int cantidadProd;
    double precioProd;
    QString nombreProd;
public:
    Producto(QString nombreProd, double precioProd, int cantidadProd)
        : nombreProd(nombreProd), precioProd(precioProd), cantidadProd(cantidadProd) {}

    virtual ~Producto() {}

    virtual QString getInfo() const {
        return QString("Nombre: "+nombreProd+"\nPrecio: "+ QString::number(precioProd)+"\nCantidad: "+QString::number(cantidadProd)+"\n");
    }

    QString getNombre() const { return nombreProd; }
    double getPrecio() const { return precioProd; }
    int getCantidad() const { return cantidadProd; }

    void setNombre(const QString &nom) { nombreProd = nom; }
    void setPrecio(double prec) { precioProd = prec; }
    void setCantidad(int cant) { cantidadProd = cant; }


};

#endif // PRODUCTO_H

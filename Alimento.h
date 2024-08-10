#ifndef ALIMENTO_H
#define ALIMENTO_H
#include "Producto.h"
#include <QDate>

class Alimento : public Producto {
private:
    QDate expiracion;
    QString tipoAlimento;

public:
    Alimento(QString nombreProd, double precioProd, int cantidadProd, QDate expiracion, QString tipoAlimento)
        : Producto(nombreProd, precioProd, cantidadProd), expiracion(expiracion), tipoAlimento(tipoAlimento) {}

    QString getInfo() const override {
        return Producto::getInfo() + QString("Fecha de Caducidad: " + expiracion.toString("dd/MM/yyyy") +"\nTipo de Alimento: "+tipoAlimento);
    }
};

#endif // ALIMENTO_H

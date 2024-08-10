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

    QDate getExpiracion() const { return expiracion; }
    QString getTipoAlimento() const { return tipoAlimento; }

    void setExpiracion(const QDate &exp) { expiracion = exp; }
    void setTipoAlimento(const QString &tipo) { tipoAlimento = tipo; }

};

#endif // ALIMENTO_H

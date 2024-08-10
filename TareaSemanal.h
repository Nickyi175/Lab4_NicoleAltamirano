#ifndef TAREASEMANAL_H
#define TAREASEMANAL_H
#include "Tarea.h"
#include <QString>

class TareaSemanal : public Tarea
{
public:
    TareaSemanal(const QString &nomTarea, const QDate &fecha, const QString &descripcion)
        : Tarea(nomTarea, fecha, descripcion) {}

    QString getTipo() const override {
        return "Semanal";
    }

    QString getInfo() const override {
        return QString("Tipo de tarea: Semanal\n") + Tarea::getInfo();
    }
};

#endif // TAREASEMANAL_H

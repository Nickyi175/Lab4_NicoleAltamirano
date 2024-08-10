#ifndef TAREADIARIA_H
#define TAREADIARIA_H
#include "Tarea.h"
#include <QString>

class TareaDiaria : public Tarea
{
public:
    TareaDiaria(const QString &nomTarea, const QDate &fecha, const QString &descripcion)
        : Tarea(nomTarea, fecha, descripcion) {}

    QString getTipo() const override {
        return "Diaria";
    }

    QString getInfo() const override {
        return QString("Tipo de tarea: Diaria\n") + Tarea::getInfo();
    }
};

#endif // TAREADIARIA_H

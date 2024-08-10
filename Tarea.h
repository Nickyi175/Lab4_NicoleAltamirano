#ifndef TAREA_H
#define TAREA_H
#include <QString>
#include <QDate>

class Tarea
{
private:
    QString nomTarea;
    QString descripcion;
    QDate fecha;

public:
    Tarea(const QString &nomTarea, const QDate &fecha, const QString &descripcion)
        : nomTarea(nomTarea), fecha(fecha), descripcion(descripcion) {}

    virtual ~Tarea() {}

    virtual QString getInfo() const {
        return QString("Tarea: "+ nomTarea + "\nFecha de inicio: "+ fecha.toString("dd/MM/yyyy")+"\nDescripción: "+descripcion+"\n");
    }

    virtual QString getTipo() const = 0;

};

#endif // TAREA_H

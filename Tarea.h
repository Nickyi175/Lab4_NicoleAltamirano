#ifndef TAREA_H
#define TAREA_H
#include <QString>
#include <QDate>

class Tarea
{
public:
    Tarea(const QString &nomTarea, const QDate &fecha, const QString &descripcion)
        : nomTarea(nomTarea), fecha(fecha), descripcion(descripcion) {}

    virtual ~Tarea() {}

    virtual QString getInfo() const {
        return QString("Tarea: "+ nomTarea + "\nFecha: "+ fecha.toString("dd/MM/yyyy")+"\nDescripción: "+descripcion+"\n")
            .arg(nomTarea)
            .arg(fecha.toString("dd/MM/yyyy"))
            .arg(descripcion);
    }

    virtual QString getTipo() const = 0;

private:
    QString nomTarea;
    QString descripcion;
    QDate fecha;

};

#endif // TAREA_H

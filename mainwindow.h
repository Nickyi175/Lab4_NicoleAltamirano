#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Tarea.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>
#include "Figura.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"
#include <QMainWindow>
#include <QList>
#include "Producto.h"
#include "Electronico.h"
#include "Ropa.h"
#include "Alimento.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_btn_agregarProd_clicked();

    void on_btn_aceptarTarea_clicked();

    void on_btn_circulo_clicked();

    void on_btn_rectangulo_clicked();

    void on_btn_triangulo_clicked();

    void on_btn_agregarM_clicked();
    void actualizarComboBoxProductos();

    void on_comboBox_TipoProd_activated(int index);

    void on_btn_eliminar_clicked();

private:
    Ui::MainWindow *ui;
    QList<Tarea*> tareas;
    QGraphicsScene *scene;
    std::vector<Figura*> figuras;
    std::vector<Producto*> productos;
};
#endif // MAINWINDOW_H

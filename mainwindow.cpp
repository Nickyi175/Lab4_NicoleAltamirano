#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <vector>
#include "Tarea.h"
#include "TareaDiaria.h"
#include "TareaSemanal.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->lbl_new->setVisible(false);
    ui->lbl_new2->setVisible(false);
    ui->spinBox_talla->setVisible(false);
    ui->lE_new->setVisible(false);
    ui->lE_new2->setVisible(false);
    ui->dateEdit->setVisible(false);

}

MainWindow::~MainWindow()
{
    qDeleteAll(productos);
    for (Figura* figura : figuras) {
        delete figura;
    }
    delete ui;
}

void MainWindow::on_comboBox_TipoProd_activated(int index)
{
    switch (index){
    case 0:
        ui->lbl_new->setVisible(true);
        ui->lbl_new2->setVisible(true);
        ui->lE_new->setVisible(true);
        ui->lE_new2->setVisible(true);
        ui->dateEdit->setVisible(false);
        ui->spinBox_talla->setVisible(false);
        ui->lbl_new->setText("Marca:");
        ui->lbl_new2->setText("Modelo:");
        break;
    case 1:
        ui->lbl_new->setVisible(true);
        ui->lbl_new2->setVisible(true);
        ui->spinBox_talla->setVisible(true);
        ui->lE_new2->setVisible(true);
        ui->dateEdit->setVisible(false);
        ui->lE_new->setVisible(false);
        ui->lbl_new->setText("Talla:");
        ui->lbl_new2->setText("Color:");
        break;

    case 2:
        ui->lbl_new->setVisible(true);
        ui->lbl_new2->setVisible(true);
        ui->lbl_new->setText("Fecha de expiración:");
        ui->lbl_new2->setText("Tipo de Alimento:");
        ui->lE_new2->setVisible(true);
        ui->dateEdit->setVisible(true);
        ui->lE_new->setVisible(false);
        break;
    default:
        break;
    }

}

void MainWindow::on_btn_agregarProd_clicked()
{
    QString nomProd = ui->lE_nombreProd1->text();
    double price = ui->dSpinBox_precioProd->value();
    int cant = ui->spinBox_cantProd->value();
    QString type = ui->comboBox_TipoProd->currentText();

    Producto *producto = nullptr;

    if (type == "Electronico") {
        QString marca = ui->lE_new->text();
        QString modelo = ui->lE_new2->text();
        producto = new Electronico(nomProd, price, cant, marca,modelo);
    } else if (type == "Ropa") {
        QString color = ui->lE_new2->text();
        int talla = ui->spinBox_talla->value()  ;
        producto = new Ropa(nomProd, price, cant, talla, color);
    } else if (type == "Alimento") {

        QString tipoAli = ui->lE_new2->text();
        QDate expiracion = QDate::fromString(ui->dateEdit->text(), "dd/MM/yyyy");
        producto = new Alimento(nomProd, price, cant, expiracion,tipoAli);
    }

    if (producto) {
        productos.push_back(producto);
        actualizarComboBoxProductos();
        QMessageBox::information(this, "Producto Agregado", producto->getInfo());
    }

}

void MainWindow::actualizarComboBoxProductos() {
    ui->comboBox_eliminar->clear();
    for (const auto &producto : productos) {
        ui->comboBox_eliminar->addItem(producto->getInfo());
    }
}
void MainWindow::on_btn_aceptarTarea_clicked()
{
    QString nombreTarea = ui->lE_tarea->text();
    QString tipoTarea = ui->comboBox_tipoTarea->currentText();
    QString infoTarea = ui->lE_infoTarea->text();
    QDate fechaTarea = ui->fecha_tarea->date();

    Tarea* tarea = nullptr;
    if (tipoTarea == "Diaria") {
        tarea = new TareaDiaria(nombreTarea, fechaTarea, infoTarea);
    } else if (tipoTarea == "Semanal") {
        tarea = new TareaSemanal(nombreTarea, fechaTarea, infoTarea);
    }

    if (tarea) {
        tareas.push_back(tarea);
        ui->tE_reporte->append(tarea->getInfo() + "\n");
        QMessageBox::information(this, "Tarea Guardada Exitosamente", "¡La tarea ha sido guardada correctamente!");

    }
}



void MainWindow::on_btn_circulo_clicked()
{
    scene->clear();
    Circulo* circulo = new Circulo(50, 50, 100);
    circulo->draw(scene);
    figuras.push_back(circulo);
}


void MainWindow::on_btn_rectangulo_clicked()
{
    scene->clear();
    Rectangulo* rectangulo = new Rectangulo(200, 0, 200, 100);
    rectangulo->draw(scene);
    figuras.push_back(rectangulo);
}


void MainWindow::on_btn_triangulo_clicked()
{
    scene->clear();
    Triangulo* triangulo = new Triangulo(370, 0);
    triangulo->draw(scene);
    figuras.push_back(triangulo);
}


void MainWindow::on_btn_agregarM_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}





void MainWindow::on_btn_eliminar_clicked()
{
    int index = ui->comboBox_eliminar->currentIndex();
    delete productos[index];  // Liberar memoria
    productos.erase(productos.begin() + index);  // Eliminar del vector

    actualizarComboBoxProductos();  // Actualiza el combo box
    QMessageBox::information(this, "Producto Eliminado", "El producto ha sido eliminado correctamente.");
}


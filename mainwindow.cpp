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
    ui->lbl_new_2->setVisible(false);
    ui->lbl_new2_2->setVisible(false);
    ui->spinBox_talla_2->setVisible(false);
    ui->lE_new_2->setVisible(false);
    ui->lE_new2_2->setVisible(false);
    ui->dateEdit_2->setVisible(false);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
    ui->fecha_tarea->setDate(QDate::currentDate());

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
    activated = true;
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
        ui->lbl_new2->setText("Tipo de Alimento (lácteo, pan, fruta, carne...):");
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
    if(activated == false){
        QMessageBox::information(this, "Error", "Debe elegir un tipo de producto");
        return;
    }

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
        QDate expiracion = ui->dateEdit->date();
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

    ui->comboBox_modificar->clear();
    for (const auto &producto : productos) {
        ui->comboBox_modificar->addItem(producto->getInfo());
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
        QMessageBox::information(this, "Tarea Guardada Exitosamente", "¡La tarea ha sido guardada exitosamente!");

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
    delete productos[index];
    productos.erase(productos.begin() + index);

    actualizarComboBoxProductos();
    QMessageBox::information(this, "Producto Eliminado", "¡El producto ha sido eliminado exitosamente!");
}


void MainWindow::on_btn_modificar_clicked()
{
    int index = ui->comboBox_modificar->currentIndex();
    if (index >= 0 && index < productos.size()) {
        Producto* producto = productos.at(index);

        QString nomProd = ui->lE_nombreProd1_2->text();
        double price = ui->dSpinBox_precioProd_2->value();
        int cant = ui->spinBox_cantProd_2->value();
        QString type = ui->comboBox_TipoProd_2->currentText();

        producto->setNombre(nomProd);
        producto->setPrecio(price);
        producto->setCantidad(cant);

        if (type == "Electronico") {
            QString marca = ui->lE_new_2->text();
            QString modelo = ui->lE_new2_2->text();
            dynamic_cast<Electronico*>(producto)->setMarca(marca);
            dynamic_cast<Electronico*>(producto)->setModelo(modelo);
        } else if (type == "Ropa") {
            int talla = ui->spinBox_talla_2->value();
            QString color = ui->lE_new2_2->text();
            dynamic_cast<Ropa*>(producto)->setTalla(talla);
            dynamic_cast<Ropa*>(producto)->setColor(color);
        } else if (type == "Alimento") {
            QDate expiracion = ui->dateEdit_2->date();
            QString tipoAli = ui->lE_new2_2->text();
            dynamic_cast<Alimento*>(producto)->setExpiracion(expiracion);
            dynamic_cast<Alimento*>(producto)->setTipoAlimento(tipoAli);
        }

        QMessageBox::information(this, "Producto Modificado", producto->getInfo());
    }

    actualizarComboBoxProductos();

}

void MainWindow::on_comboBox_modificar_activated(int index){
    int inde;


    if (index >= 0 && index < productos.size()) {
        Producto* producto = productos.at(index);

        ui->lE_nombreProd1_2->setText(producto->getNombre());
        ui->dSpinBox_precioProd_2->setValue(producto->getPrecio());
        ui->spinBox_cantProd_2->setValue(producto->getCantidad());

        if (dynamic_cast<Electronico*>(producto)) {
            Electronico* elec = static_cast<Electronico*>(producto);
            ui->comboBox_TipoProd_2->setCurrentIndex(0);
            ui->lE_new_2->setText(elec->getMarca());
            ui->lE_new2_2->setText(elec->getModelo());
        } else if (dynamic_cast<Ropa*>(producto)) {
            Ropa* ropa = static_cast<Ropa*>(producto);
            ui->comboBox_TipoProd_2->setCurrentIndex(1);
            ui->spinBox_talla_2->setValue(ropa->getTalla());
            ui->lE_new2_2->setText(ropa->getColor());
        } else if (dynamic_cast<Alimento*>(producto)) {
            Alimento* alimento = static_cast<Alimento*>(producto);
            ui->comboBox_TipoProd_2->setCurrentIndex(2);
            ui->dateEdit_2->setDate(alimento->getExpiracion());
            ui->lE_new2_2->setText(alimento->getTipoAlimento());
        }
    }

    QString type = ui->comboBox_TipoProd_2->currentText();
    if (type == "Electronico") {
        inde = 0;
    } else if (type == "Ropa") {
        inde = 1;
    } else if (type == "Alimento") {
        inde = 2;
    }
    switch (inde){
    case 0:
        ui->lbl_new_2->setVisible(true);
        ui->lbl_new2_2->setVisible(true);
        ui->lE_new_2->setVisible(true);
        ui->lE_new2_2->setVisible(true);
        ui->dateEdit_2->setVisible(false);
        ui->spinBox_talla_2->setVisible(false);
        ui->lbl_new_2->setText("Marca:");
        ui->lbl_new2_2->setText("Modelo:");
        break;
    case 1:
        ui->lbl_new_2->setVisible(true);
        ui->lbl_new2_2->setVisible(true);
        ui->spinBox_talla_2->setVisible(true);
        ui->lE_new2_2->setVisible(true);
        ui->dateEdit_2->setVisible(false);
        ui->lE_new_2->setVisible(false);
        ui->lbl_new_2->setText("Talla:");
        ui->lbl_new2_2->setText("Color:");
        break;

    case 2:
        ui->lbl_new_2->setVisible(true);
        ui->lbl_new2_2->setVisible(true);
        ui->spinBox_talla_2->setValue(false);
        ui->lE_new_2->setVisible(false);
        ui->lE_new2_2->setVisible(true);
        ui->dateEdit_2->setVisible(true);
        ui->lbl_new_2->setText("Fecha de expiración:");
        ui->lbl_new2_2->setText("Tipo de Alimento (lácteo, pan, fruta, carne...):");

        break;
    default:
        break;
    }

}



void MainWindow::on_comboBox_TipoProd_2_activated(int index)
{

}


void MainWindow::on_btn_bold_clicked()
{
    if (bold == false ){
        ui->tE_editor->setFontWeight(QFont::Bold);
        bold = true;
    } else{
        ui->tE_editor->setFontWeight(QFont::Normal);
        bold = false;
    }

}


void MainWindow::on_btn_underline_clicked()
{
    if (under == false ){
        ui->tE_editor->setFontUnderline(true);
        under = true;
    } else{
        ui->tE_editor->setFontUnderline(false);
        under = false;
    }

}


void MainWindow::on_btn_cursive_clicked()
{
    if (italic == false ){
        ui->tE_editor->setFontItalic(true);
        italic = true;
    } else{
        ui->tE_editor->setFontItalic(false);
        italic = false;
    }
}


void MainWindow::on_btn_eliminarM_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
}


void MainWindow::on_btn_modificarM_clicked()
{
    ui->tabWidget->setCurrentIndex(6);
}


void MainWindow::on_btn_regresar1_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}


void MainWindow::on_btn_regresar1_2_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}


void MainWindow::on_btn_regresar1_3_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}


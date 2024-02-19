#include "mainwindow.h"

#include <math.h>

#include <QDir>
#include <QFileDialog>

#include "ui_mainwindow.h"

extern "C" {
#include "../backend/object.h"
#include "../backend/parse.h"
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  linkSliderSpinbox(ui->offset_slider_x, ui->offset_x, -1, 1);
  linkSliderSpinbox(ui->offset_slider_y, ui->offset_y, -1, 1);
  linkSliderSpinbox(ui->offset_slider_z, ui->offset_z, -1, 1);
  linkSliderSpinbox(ui->scale_slider, ui->scale, 0, 10);

  linkSliderSpinbox(ui->rotate_slider_x, ui->rotate_x, 0, 360);
  linkSliderSpinbox(ui->rotate_slider_y, ui->rotate_y, 0, 360);
  linkSliderSpinbox(ui->rotate_slider_z, ui->rotate_z, 0, 360);
  setDefault();

  getModelFromFile("../object/Among_US.obj");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::linkSliderSpinbox(QSlider* slider, QDoubleSpinBox* spin_box,
                                   double min, double max) {
  slider->setRange(min * 100, max * 100);
  spin_box->setRange(min, max);
  connect(
      spin_box, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
      [=](double value) { slider->setValue(static_cast<int>(value * 100)); });
  connect(slider, &QSlider::valueChanged, spin_box,
          [=](double value) { spin_box->setValue(value / 100); });
}

void MainWindow::setDefault() {
  ui->scale->setValue(1);
  ui->offset_x->setValue(0);
  ui->offset_y->setValue(0);
  ui->offset_z->setValue(0);
  ui->rotate_x->setValue(0);
  ui->rotate_y->setValue(0);
  ui->rotate_z->setValue(0);
}

void MainWindow::getModelFromFile(std::string path) {
  ;
  object* obj = new object;
  if (parse(&path[0], obj) != 1) {
    setDefault();
    ui->viewer->setData(obj);
    ui->file_full_path->setText(
        QDir().absoluteFilePath(QString::fromStdString(path)));

    long polygon_count = 0;
    for (int i = 0; i < obj->polygons_amount; i++) {
      polygon_count += obj->polygons[i].polygons_count;
    }
    ui->vertex_lable->setText(QString::number(polygon_count));
    ui->polygons_lable->setText(QString::number(obj->vertexes_amount));
  }
}

void MainWindow::on_btn_setFile_clicked() {
  QString path = QFileDialog::getOpenFileName(this, tr("Открыть файл"),
                                              QDir::currentPath(),
                                              tr("Файлы *.obj (*.obj);"));
  getModelFromFile(path.toStdString());
}

void MainWindow::on_offset_x_valueChanged(double arg1) {
  ui->viewer->setOffset(0, arg1);
}

void MainWindow::on_offset_z_valueChanged(double arg1) {
  ui->viewer->setOffset(2, arg1);
}

void MainWindow::on_offset_y_valueChanged(double arg1) {
  ui->viewer->setOffset(1, arg1);
}

void MainWindow::on_scale_valueChanged(double arg1) {
  ui->viewer->setScale(arg1);
}

void MainWindow::on_rotate_x_valueChanged(double arg1) {
  ui->viewer->setRotate(0, arg1 * M_PI / 180);
}

void MainWindow::on_rotate_y_valueChanged(double arg1) {
  ui->viewer->setRotate(1, arg1 * M_PI / 180);
}

void MainWindow::on_rotate_z_valueChanged(double arg1) {
  ui->viewer->setRotate(2, arg1 * M_PI / 180);
}

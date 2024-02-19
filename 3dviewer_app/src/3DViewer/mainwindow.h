#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDoubleSpinBox>
#include <QMainWindow>
#include <QObject>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  void on_btn_setFile_clicked();

  void on_offset_x_valueChanged(double arg1);

  void on_offset_z_valueChanged(double arg1);

  void on_offset_y_valueChanged(double arg1);

  void on_scale_valueChanged(double arg1);

  void on_rotate_x_valueChanged(double arg1);

  void on_rotate_y_valueChanged(double arg1);

  void on_rotate_z_valueChanged(double arg1);

 private:
  Ui::MainWindow* ui;

 private:
  void linkSliderSpinbox(QSlider* slider, QDoubleSpinBox* spin_box, double min,
                         double max);
  void getModelFromFile(std::string path);
  void setDefault();
};
#endif  // MAINWINDOW_H

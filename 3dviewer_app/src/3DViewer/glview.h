#ifndef GLVIEW_H
#define GLVIEW_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
extern "C" {
#include "../backend/action_with_obgect.h"
#include "../backend/object.h"
#include "../backend/parse.h"
}

class GLView : public QOpenGLWidget, protected QOpenGLFunctions {
 private:
  object *data = nullptr;
  double offset_x = 0;
  double offset_y = 0;
  double offset_z = 0;
  double rotate_x = 0;
  double rotate_y = 0;
  double rotate_z = 0;
  double scale = 1;

 public:
  explicit GLView(QWidget *parent = 0);

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

 public:
  void setData(object *obj);
  void setOffset(int axis, double x);
  void setScale(double x);
  void setRotate(int axis, double x);
};

#endif  // GLVIEW_H

#include "glview.h"

GLView::GLView(QWidget *parent) : QOpenGLWidget(parent) {}
object createSquare();

void GLView::initializeGL() {
  initializeOpenGLFunctions();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
}

void GLView::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  float aspectRatio = static_cast<float>(w) / static_cast<float>(h);
  glOrtho(-1.0 * aspectRatio, 1.0 * aspectRatio, -1.0, 1.0, -1.5, 1.5);
  glMatrixMode(GL_MODELVIEW);
}

void GLView::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);

  if (data != nullptr) {
    glEnable(GL_BLEND);
    glPointSize(1);

    glBegin(GL_POINTS);
    for (int i = 0; i < data->vertexes_amount; i++) {
      glColor3f(1, 0, 0);
      glVertex3f(data->vertexes[i].x, data->vertexes[i].y, data->vertexes[i].z);
    }
    glEnd();

    for (int i = 0; i < data->polygons_amount; i++) {
      glBegin(GL_LINE_LOOP);
      for (int j = 0; j < data->polygons[i].polygons_count; j++) {
        int index = data->polygons[i].polygons[j];
        float x, y, z;
        x = data->vertexes[index].x;
        y = data->vertexes[index].y;
        z = data->vertexes[index].z;
        glVertex3f(x, y, z);
      }
      glEnd();
    }
  }
}

void GLView::setData(object *obj) {
  if (obj != nullptr) {
    if (data != nullptr) {
      remove_object(data);
      data = nullptr;
    }
    offset_x = 0;
    offset_y = 0;
    offset_z = 0;
    rotate_x = 0;
    rotate_y = 0;
    rotate_z = 0;
    scale = 1;

    normalize(obj);
    data = obj;
  }
  update();
}

void GLView::setOffset(int axis, double x) {
  if (data == nullptr || x == 0) return;
  if (axis == 0) {
    move_object(data, x - offset_x, axis);
    offset_x = x;
  } else if (axis == 1) {
    move_object(data, x - offset_y, axis);
    offset_y = x;
  } else if (axis == 2) {
    move_object(data, x - offset_z, axis);
    offset_z = x;
  }
  update();
}

void GLView::setScale(double x) {
  if (data == nullptr || x == 0) return;
  skale_object(data, x / scale);
  scale = x;
  update();
}

void GLView::setRotate(int axis, double x) {
  if (data == nullptr || x == 0) return;
  if (axis == 0) {
    rotation_by_ox(data, x - rotate_x);
    rotate_x = x;
  } else if (axis == 1) {
    rotation_by_oy(data, x - rotate_y);
    rotate_y = x;
  } else if (axis == 2) {
    rotation_by_oz(data, x - rotate_z);
    rotate_z = x;
  }
  update();
}

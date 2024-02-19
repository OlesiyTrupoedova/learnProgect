/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "glview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_7;
    GLView *viewer;
    QFrame *controlFrame;
    QFrame *translationFrame;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSlider *offset_slider_y;
    QSlider *offset_slider_x;
    QSlider *offset_slider_z;
    QLabel *label_3;
    QDoubleSpinBox *offset_z;
    QLabel *label_2;
    QDoubleSpinBox *offset_y;
    QDoubleSpinBox *offset_x;
    QLabel *label_10;
    QFrame *rotationFrame;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QLabel *label_11;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QSlider *rotate_slider_x;
    QSlider *rotate_slider_y;
    QSlider *rotate_slider_z;
    QDoubleSpinBox *rotate_x;
    QDoubleSpinBox *rotate_y;
    QDoubleSpinBox *rotate_z;
    QFrame *scaleFrame;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout;
    QDoubleSpinBox *scale;
    QSlider *scale_slider;
    QLabel *label_5;
    QFrame *openFileFrame;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QPushButton *btn_setFile;
    QFrame *frame_info;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QLabel *polygons_lable;
    QLabel *vertex_lable;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *file_full_path;
    QLabel *label_12;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1032, 693);
        MainWindow->setMinimumSize(QSize(1032, 693));
        MainWindow->setMaximumSize(QSize(1032, 693));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 0, 1028, 651));
        gridLayout_7 = new QGridLayout(layoutWidget);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        viewer = new GLView(layoutWidget);
        viewer->setObjectName("viewer");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(viewer->sizePolicy().hasHeightForWidth());
        viewer->setSizePolicy(sizePolicy);
        viewer->setMinimumSize(QSize(780, 580));
        viewer->setMaximumSize(QSize(780, 580));

        gridLayout_7->addWidget(viewer, 1, 0, 1, 1);

        controlFrame = new QFrame(layoutWidget);
        controlFrame->setObjectName("controlFrame");
        controlFrame->setMinimumSize(QSize(240, 321));
        controlFrame->setMaximumSize(QSize(240, 50000));
        controlFrame->setFrameShape(QFrame::StyledPanel);
        controlFrame->setFrameShadow(QFrame::Raised);
        translationFrame = new QFrame(controlFrame);
        translationFrame->setObjectName("translationFrame");
        translationFrame->setGeometry(QRect(0, 60, 241, 121));
        translationFrame->setFrameShape(QFrame::StyledPanel);
        translationFrame->setFrameShadow(QFrame::Raised);
        gridLayoutWidget = new QWidget(translationFrame);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 0, 221, 121));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(64, 27));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        offset_slider_y = new QSlider(gridLayoutWidget);
        offset_slider_y->setObjectName("offset_slider_y");
        offset_slider_y->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(offset_slider_y, 2, 1, 1, 1);

        offset_slider_x = new QSlider(gridLayoutWidget);
        offset_slider_x->setObjectName("offset_slider_x");
        offset_slider_x->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(offset_slider_x, 1, 1, 1, 1);

        offset_slider_z = new QSlider(gridLayoutWidget);
        offset_slider_z->setObjectName("offset_slider_z");
        offset_slider_z->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(offset_slider_z, 3, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(64, 27));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        offset_z = new QDoubleSpinBox(gridLayoutWidget);
        offset_z->setObjectName("offset_z");
        offset_z->setMaximumSize(QSize(81, 27));
        offset_z->setFont(font);
        offset_z->setMinimum(-100.000000000000000);
        offset_z->setMaximum(100.000000000000000);
        offset_z->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(offset_z, 3, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(64, 27));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        offset_y = new QDoubleSpinBox(gridLayoutWidget);
        offset_y->setObjectName("offset_y");
        offset_y->setMaximumSize(QSize(81, 27));
        offset_y->setFont(font);
        offset_y->setMinimum(-100.000000000000000);
        offset_y->setMaximum(100.000000000000000);
        offset_y->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(offset_y, 2, 2, 1, 1);

        offset_x = new QDoubleSpinBox(gridLayoutWidget);
        offset_x->setObjectName("offset_x");
        offset_x->setMaximumSize(QSize(81, 27));
        offset_x->setFont(font);
        offset_x->setMinimum(-100.000000000000000);
        offset_x->setMaximum(100.000000000000000);
        offset_x->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(offset_x, 1, 2, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName("label_10");
        label_10->setMaximumSize(QSize(16777215, 27));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_10, 0, 0, 1, 2);

        rotationFrame = new QFrame(controlFrame);
        rotationFrame->setObjectName("rotationFrame");
        rotationFrame->setGeometry(QRect(0, 180, 241, 121));
        rotationFrame->setFrameShape(QFrame::StyledPanel);
        rotationFrame->setFrameShadow(QFrame::Raised);
        gridLayoutWidget_3 = new QWidget(rotationFrame);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(10, 0, 221, 121));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(gridLayoutWidget_3);
        label_11->setObjectName("label_11");
        label_11->setMaximumSize(QSize(64, 27));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget_3);
        label_18->setObjectName("label_18");
        label_18->setMaximumSize(QSize(64, 27));
        label_18->setFont(font);
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_18, 3, 0, 1, 1);

        label_19 = new QLabel(gridLayoutWidget_3);
        label_19->setObjectName("label_19");
        label_19->setMaximumSize(QSize(64, 27));
        label_19->setFont(font);
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_19, 2, 0, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_3);
        label_20->setObjectName("label_20");
        label_20->setMaximumSize(QSize(16777215, 27));
        label_20->setFont(font);
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_20, 0, 0, 1, 2);

        rotate_slider_x = new QSlider(gridLayoutWidget_3);
        rotate_slider_x->setObjectName("rotate_slider_x");
        rotate_slider_x->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(rotate_slider_x, 1, 1, 1, 1);

        rotate_slider_y = new QSlider(gridLayoutWidget_3);
        rotate_slider_y->setObjectName("rotate_slider_y");
        rotate_slider_y->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(rotate_slider_y, 2, 1, 1, 1);

        rotate_slider_z = new QSlider(gridLayoutWidget_3);
        rotate_slider_z->setObjectName("rotate_slider_z");
        rotate_slider_z->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(rotate_slider_z, 3, 1, 1, 1);

        rotate_x = new QDoubleSpinBox(gridLayoutWidget_3);
        rotate_x->setObjectName("rotate_x");
        rotate_x->setMaximumSize(QSize(81, 27));
        rotate_x->setFont(font);
        rotate_x->setMinimum(-100.000000000000000);
        rotate_x->setMaximum(100.000000000000000);
        rotate_x->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(rotate_x, 1, 2, 1, 1);

        rotate_y = new QDoubleSpinBox(gridLayoutWidget_3);
        rotate_y->setObjectName("rotate_y");
        rotate_y->setMaximumSize(QSize(81, 27));
        rotate_y->setFont(font);
        rotate_y->setMinimum(-100.000000000000000);
        rotate_y->setMaximum(100.000000000000000);
        rotate_y->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(rotate_y, 2, 2, 1, 1);

        rotate_z = new QDoubleSpinBox(gridLayoutWidget_3);
        rotate_z->setObjectName("rotate_z");
        rotate_z->setMaximumSize(QSize(81, 27));
        rotate_z->setFont(font);
        rotate_z->setMinimum(-100.000000000000000);
        rotate_z->setMaximum(100.000000000000000);
        rotate_z->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(rotate_z, 3, 2, 1, 1);

        scaleFrame = new QFrame(controlFrame);
        scaleFrame->setObjectName("scaleFrame");
        scaleFrame->setGeometry(QRect(1, 300, 241, 31));
        scaleFrame->setFrameShape(QFrame::StyledPanel);
        scaleFrame->setFrameShadow(QFrame::Raised);
        gridLayoutWidget_4 = new QWidget(scaleFrame);
        gridLayoutWidget_4->setObjectName("gridLayoutWidget_4");
        gridLayoutWidget_4->setGeometry(QRect(9, 0, 221, 31));
        gridLayout = new QGridLayout(gridLayoutWidget_4);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scale = new QDoubleSpinBox(gridLayoutWidget_4);
        scale->setObjectName("scale");
        scale->setMaximumSize(QSize(81, 27));
        scale->setFont(font);
        scale->setMinimum(0.000000000000000);
        scale->setMaximum(100.000000000000000);
        scale->setSingleStep(0.010000000000000);
        scale->setValue(1.000000000000000);

        gridLayout->addWidget(scale, 1, 2, 1, 1);

        scale_slider = new QSlider(gridLayoutWidget_4);
        scale_slider->setObjectName("scale_slider");
        scale_slider->setMaximum(1000);
        scale_slider->setValue(100);
        scale_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(scale_slider, 1, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_4);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(64, 27));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        openFileFrame = new QFrame(controlFrame);
        openFileFrame->setObjectName("openFileFrame");
        openFileFrame->setGeometry(QRect(0, 10, 231, 41));
        openFileFrame->setFrameShape(QFrame::StyledPanel);
        openFileFrame->setFrameShadow(QFrame::Raised);
        gridLayoutWidget_6 = new QWidget(openFileFrame);
        gridLayoutWidget_6->setObjectName("gridLayoutWidget_6");
        gridLayoutWidget_6->setGeometry(QRect(10, 0, 221, 41));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        btn_setFile = new QPushButton(gridLayoutWidget_6);
        btn_setFile->setObjectName("btn_setFile");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_setFile->sizePolicy().hasHeightForWidth());
        btn_setFile->setSizePolicy(sizePolicy1);
        btn_setFile->setFont(font);

        gridLayout_6->addWidget(btn_setFile, 0, 0, 1, 1);


        gridLayout_7->addWidget(controlFrame, 0, 1, 2, 1);

        frame_info = new QFrame(layoutWidget);
        frame_info->setObjectName("frame_info");
        frame_info->setFrameShape(QFrame::StyledPanel);
        frame_info->setFrameShadow(QFrame::Raised);
        layoutWidget1 = new QWidget(frame_info);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 0, 761, 61));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        polygons_lable = new QLabel(layoutWidget1);
        polygons_lable->setObjectName("polygons_lable");
        polygons_lable->setMaximumSize(QSize(16777215, 27));
        polygons_lable->setFont(font);
        polygons_lable->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(polygons_lable, 1, 1, 1, 2);

        vertex_lable = new QLabel(layoutWidget1);
        vertex_lable->setObjectName("vertex_lable");
        vertex_lable->setMaximumSize(QSize(16777215, 27));
        vertex_lable->setFont(font);
        vertex_lable->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(vertex_lable, 1, 4, 1, 1);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName("label_13");
        label_13->setMaximumSize(QSize(80, 27));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_13, 1, 0, 1, 1);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName("label_14");
        label_14->setMaximumSize(QSize(60, 27));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_14, 1, 3, 1, 1);

        file_full_path = new QLabel(layoutWidget1);
        file_full_path->setObjectName("file_full_path");
        file_full_path->setMinimumSize(QSize(0, 30));
        file_full_path->setMaximumSize(QSize(16777215, 27));
        file_full_path->setFont(font);
        file_full_path->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        file_full_path->setWordWrap(true);

        gridLayout_3->addWidget(file_full_path, 0, 1, 1, 4);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName("label_12");
        label_12->setMaximumSize(QSize(16777215, 27));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_12, 0, 0, 1, 1);


        gridLayout_7->addWidget(frame_info, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1032, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Translation:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        btn_setFile->setText(QCoreApplication::translate("MainWindow", "Set Object File", nullptr));
        polygons_lable->setText(QString());
        vertex_lable->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Vertexes", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Edges", nullptr));
        file_full_path->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "Filename:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

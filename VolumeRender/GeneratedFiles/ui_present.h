/********************************************************************************
** Form generated from reading UI file 'present.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESENT_H
#define UI_PRESENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "VolumeRenderPanel.h"

QT_BEGIN_NAMESPACE

class Ui_PresentClass
{
public:
    QWidget *centralWidget;
    VolumeRenderPanel *openGLWidget;
    QSlider *minSlider;
    QLabel *minLabel;
    QLabel *maxLabel;
    QSlider *maxSlider;
    QPushButton *resetButton;
    QLabel *zBLabel;
    QLabel *zALabel;
    QSlider *zASlider;
    QSlider *zBSlider;
    QPushButton *saveButton;
    QSlider *ambient_r;
    QSlider *ambient_g;
    QSlider *ambient_b;
    QSlider *diffuse_r;
    QSlider *diffuse_g;
    QSlider *diffuse_b;
    QSlider *specular_g;
    QSlider *specular_r;
    QSlider *specular_b;
    QLabel *tfPanel;
    QPushButton *applyTFButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *button_foreground;
    QPushButton *button_background;
    QCheckBox *checkBox_foreground;
    QCheckBox *checkBox_background;
    QPushButton *button_cleargraphcut;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PresentClass)
    {
        if (PresentClass->objectName().isEmpty())
            PresentClass->setObjectName(QStringLiteral("PresentClass"));
        PresentClass->resize(1201, 1025);
        centralWidget = new QWidget(PresentClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new VolumeRenderPanel(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(0, 0, 960, 960));
        minSlider = new QSlider(centralWidget);
        minSlider->setObjectName(QStringLiteral("minSlider"));
        minSlider->setGeometry(QRect(980, 40, 101, 20));
        minSlider->setMaximum(1000);
        minSlider->setValue(100);
        minSlider->setOrientation(Qt::Horizontal);
        minLabel = new QLabel(centralWidget);
        minLabel->setObjectName(QStringLiteral("minLabel"));
        minLabel->setGeometry(QRect(980, 10, 54, 12));
        maxLabel = new QLabel(centralWidget);
        maxLabel->setObjectName(QStringLiteral("maxLabel"));
        maxLabel->setGeometry(QRect(980, 70, 54, 12));
        maxSlider = new QSlider(centralWidget);
        maxSlider->setObjectName(QStringLiteral("maxSlider"));
        maxSlider->setGeometry(QRect(980, 90, 101, 20));
        maxSlider->setMinimum(0);
        maxSlider->setMaximum(1000);
        maxSlider->setValue(850);
        maxSlider->setOrientation(Qt::Horizontal);
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setGeometry(QRect(1150, 20, 75, 23));
        zBLabel = new QLabel(centralWidget);
        zBLabel->setObjectName(QStringLiteral("zBLabel"));
        zBLabel->setGeometry(QRect(1140, 110, 54, 12));
        zALabel = new QLabel(centralWidget);
        zALabel->setObjectName(QStringLiteral("zALabel"));
        zALabel->setGeometry(QRect(1140, 50, 54, 12));
        zASlider = new QSlider(centralWidget);
        zASlider->setObjectName(QStringLiteral("zASlider"));
        zASlider->setGeometry(QRect(1140, 140, 101, 20));
        zASlider->setMaximum(174);
        zASlider->setValue(0);
        zASlider->setOrientation(Qt::Horizontal);
        zBSlider = new QSlider(centralWidget);
        zBSlider->setObjectName(QStringLiteral("zBSlider"));
        zBSlider->setGeometry(QRect(1140, 90, 101, 20));
        zBSlider->setMinimum(0);
        zBSlider->setMaximum(161);
        zBSlider->setValue(1);
        zBSlider->setOrientation(Qt::Horizontal);
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(1160, 180, 75, 23));
        ambient_r = new QSlider(centralWidget);
        ambient_r->setObjectName(QStringLiteral("ambient_r"));
        ambient_r->setGeometry(QRect(970, 160, 131, 22));
        ambient_r->setMaximum(100);
        ambient_r->setValue(70);
        ambient_r->setOrientation(Qt::Horizontal);
        ambient_g = new QSlider(centralWidget);
        ambient_g->setObjectName(QStringLiteral("ambient_g"));
        ambient_g->setGeometry(QRect(970, 190, 131, 22));
        ambient_g->setMaximum(100);
        ambient_g->setValue(70);
        ambient_g->setOrientation(Qt::Horizontal);
        ambient_b = new QSlider(centralWidget);
        ambient_b->setObjectName(QStringLiteral("ambient_b"));
        ambient_b->setGeometry(QRect(970, 220, 131, 22));
        ambient_b->setMaximum(100);
        ambient_b->setValue(70);
        ambient_b->setOrientation(Qt::Horizontal);
        diffuse_r = new QSlider(centralWidget);
        diffuse_r->setObjectName(QStringLiteral("diffuse_r"));
        diffuse_r->setGeometry(QRect(970, 260, 131, 22));
        diffuse_r->setMaximum(100);
        diffuse_r->setValue(20);
        diffuse_r->setOrientation(Qt::Horizontal);
        diffuse_g = new QSlider(centralWidget);
        diffuse_g->setObjectName(QStringLiteral("diffuse_g"));
        diffuse_g->setGeometry(QRect(970, 290, 131, 22));
        diffuse_g->setMaximum(100);
        diffuse_g->setValue(20);
        diffuse_g->setOrientation(Qt::Horizontal);
        diffuse_b = new QSlider(centralWidget);
        diffuse_b->setObjectName(QStringLiteral("diffuse_b"));
        diffuse_b->setGeometry(QRect(970, 320, 131, 22));
        diffuse_b->setMaximum(100);
        diffuse_b->setValue(20);
        diffuse_b->setOrientation(Qt::Horizontal);
        specular_g = new QSlider(centralWidget);
        specular_g->setObjectName(QStringLiteral("specular_g"));
        specular_g->setGeometry(QRect(970, 390, 131, 22));
        specular_g->setMaximum(100);
        specular_g->setValue(40);
        specular_g->setOrientation(Qt::Horizontal);
        specular_r = new QSlider(centralWidget);
        specular_r->setObjectName(QStringLiteral("specular_r"));
        specular_r->setGeometry(QRect(970, 360, 131, 22));
        specular_r->setMaximum(100);
        specular_r->setValue(40);
        specular_r->setOrientation(Qt::Horizontal);
        specular_b = new QSlider(centralWidget);
        specular_b->setObjectName(QStringLiteral("specular_b"));
        specular_b->setGeometry(QRect(970, 420, 131, 22));
        specular_b->setMaximum(100);
        specular_b->setValue(40);
        specular_b->setOrientation(Qt::Horizontal);
        tfPanel = new QLabel(centralWidget);
        tfPanel->setObjectName(QStringLiteral("tfPanel"));
        tfPanel->setGeometry(QRect(970, 740, 256, 150));
        applyTFButton = new QPushButton(centralWidget);
        applyTFButton->setObjectName(QStringLiteral("applyTFButton"));
        applyTFButton->setGeometry(QRect(1000, 470, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(980, 530, 71, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(980, 570, 61, 16));
        button_foreground = new QPushButton(centralWidget);
        button_foreground->setObjectName(QStringLiteral("button_foreground"));
        button_foreground->setGeometry(QRect(1050, 530, 41, 25));
        button_foreground->setStyleSheet(QStringLiteral("background:rgb(0,255,0);"));
        button_background = new QPushButton(centralWidget);
        button_background->setObjectName(QStringLiteral("button_background"));
        button_background->setGeometry(QRect(1050, 565, 41, 25));
        button_background->setStyleSheet(QStringLiteral("background:rgb(0,0,255);"));
        checkBox_foreground = new QCheckBox(centralWidget);
        checkBox_foreground->setObjectName(QStringLiteral("checkBox_foreground"));
        checkBox_foreground->setGeometry(QRect(1100, 530, 16, 16));
        checkBox_background = new QCheckBox(centralWidget);
        checkBox_background->setObjectName(QStringLiteral("checkBox_background"));
        checkBox_background->setGeometry(QRect(1100, 570, 21, 16));
        button_cleargraphcut = new QPushButton(centralWidget);
        button_cleargraphcut->setObjectName(QStringLiteral("button_cleargraphcut"));
        button_cleargraphcut->setGeometry(QRect(980, 620, 75, 23));
        PresentClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PresentClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1201, 23));
        PresentClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PresentClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PresentClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PresentClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PresentClass->setStatusBar(statusBar);

        retranslateUi(PresentClass);

        QMetaObject::connectSlotsByName(PresentClass);
    } // setupUi

    void retranslateUi(QMainWindow *PresentClass)
    {
        PresentClass->setWindowTitle(QApplication::translate("PresentClass", "Present", 0));
        minLabel->setText(QApplication::translate("PresentClass", "0", 0));
        maxLabel->setText(QApplication::translate("PresentClass", "1", 0));
        resetButton->setText(QApplication::translate("PresentClass", "reset", 0));
        zBLabel->setText(QApplication::translate("PresentClass", "1", 0));
        zALabel->setText(QApplication::translate("PresentClass", "0", 0));
        saveButton->setText(QApplication::translate("PresentClass", "saveGradient", 0));
        tfPanel->setText(QString());
        applyTFButton->setText(QApplication::translate("PresentClass", "apply", 0));
        label->setText(QApplication::translate("PresentClass", "foreground", 0));
        label_2->setText(QApplication::translate("PresentClass", "background", 0));
        button_foreground->setText(QString());
        button_background->setText(QString());
        checkBox_foreground->setText(QString());
        checkBox_background->setText(QString());
        button_cleargraphcut->setText(QApplication::translate("PresentClass", "clear", 0));
    } // retranslateUi

};

namespace Ui {
    class PresentClass: public Ui_PresentClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESENT_H

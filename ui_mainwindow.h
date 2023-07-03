/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionslider_r;
    QWidget *centralwidget;
    QSlider *slider_r;
    QSlider *slider_g;
    QSlider *slider_b;
    QLabel *label_status_r;
    QLabel *label_status_g;
    QLabel *label_status_b;
    QLabel *label_r;
    QLabel *label_g;
    QLabel *label_b;
    QCheckBox *checkBox_auto;
    QLabel *label_error;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(449, 298);
        actionslider_r = new QAction(MainWindow);
        actionslider_r->setObjectName(QString::fromUtf8("actionslider_r"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        slider_r = new QSlider(centralwidget);
        slider_r->setObjectName(QString::fromUtf8("slider_r"));
        slider_r->setGeometry(QRect(120, 30, 160, 16));
        slider_r->setMaximum(3);
        slider_r->setPageStep(1);
        slider_r->setOrientation(Qt::Horizontal);
        slider_g = new QSlider(centralwidget);
        slider_g->setObjectName(QString::fromUtf8("slider_g"));
        slider_g->setGeometry(QRect(120, 80, 160, 16));
        slider_g->setMaximum(3);
        slider_g->setPageStep(1);
        slider_g->setOrientation(Qt::Horizontal);
        slider_b = new QSlider(centralwidget);
        slider_b->setObjectName(QString::fromUtf8("slider_b"));
        slider_b->setGeometry(QRect(120, 130, 160, 16));
        slider_b->setMaximum(3);
        slider_b->setPageStep(1);
        slider_b->setOrientation(Qt::Horizontal);
        label_status_r = new QLabel(centralwidget);
        label_status_r->setObjectName(QString::fromUtf8("label_status_r"));
        label_status_r->setGeometry(QRect(310, 30, 60, 23));
        label_status_g = new QLabel(centralwidget);
        label_status_g->setObjectName(QString::fromUtf8("label_status_g"));
        label_status_g->setGeometry(QRect(310, 80, 60, 23));
        label_status_b = new QLabel(centralwidget);
        label_status_b->setObjectName(QString::fromUtf8("label_status_b"));
        label_status_b->setGeometry(QRect(310, 130, 60, 23));
        label_r = new QLabel(centralwidget);
        label_r->setObjectName(QString::fromUtf8("label_r"));
        label_r->setGeometry(QRect(40, 30, 71, 23));
        label_g = new QLabel(centralwidget);
        label_g->setObjectName(QString::fromUtf8("label_g"));
        label_g->setGeometry(QRect(40, 80, 71, 23));
        label_b = new QLabel(centralwidget);
        label_b->setObjectName(QString::fromUtf8("label_b"));
        label_b->setGeometry(QRect(40, 130, 71, 23));
        checkBox_auto = new QCheckBox(centralwidget);
        checkBox_auto->setObjectName(QString::fromUtf8("checkBox_auto"));
        checkBox_auto->setGeometry(QRect(40, 170, 141, 29));
        label_error = new QLabel(centralwidget);
        label_error->setObjectName(QString::fromUtf8("label_error"));
        label_error->setGeometry(QRect(40, 200, 401, 23));
        QPalette palette;
        QBrush brush(QColor(224, 27, 36, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 112, 118, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush2(QColor(239, 69, 77, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(112, 13, 18, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(149, 18, 24, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush5(QColor(255, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        QBrush brush7(QColor(239, 141, 145, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush9(QColor(224, 27, 36, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        QBrush brush10(QColor(0, 0, 0, 128));
        brush10.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        label_error->setPalette(palette);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 230, 84, 31));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QT LED demo", nullptr));
        actionslider_r->setText(QCoreApplication::translate("MainWindow", "slider_r", nullptr));
        label_status_r->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_status_g->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_status_b->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_r->setText(QCoreApplication::translate("MainWindow", "LED Red", nullptr));
        label_g->setText(QCoreApplication::translate("MainWindow", "LED Green", nullptr));
        label_b->setText(QCoreApplication::translate("MainWindow", "LED Blue", nullptr));
        checkBox_auto->setText(QCoreApplication::translate("MainWindow", "LED - auto mode", nullptr));
        label_error->setText(QCoreApplication::translate("MainWindow", "LED Blue", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "E&xit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

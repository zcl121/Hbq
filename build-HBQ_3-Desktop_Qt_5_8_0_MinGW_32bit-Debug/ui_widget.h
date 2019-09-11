/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        Widget->setStyleSheet(QStringLiteral(""));
        Widget->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 210, 75, 23));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 210, 75, 23));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(190, 100, 113, 20));
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 150, 113, 20));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 110, 54, 12));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 150, 54, 12));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "\347\231\273\351\231\206", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", " \345\257\206 \347\240\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

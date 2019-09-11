/********************************************************************************
** Form generated from reading UI file 'zhuce.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHUCE_H
#define UI_ZHUCE_H

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

class Ui_zhuce
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *zhuce)
    {
        if (zhuce->objectName().isEmpty())
            zhuce->setObjectName(QStringLiteral("zhuce"));
        zhuce->resize(447, 338);
        lineEdit = new QLineEdit(zhuce);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(210, 90, 113, 20));
        lineEdit_2 = new QLineEdit(zhuce);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 140, 113, 20));
        lineEdit_3 = new QLineEdit(zhuce);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(210, 190, 113, 20));
        label = new QLabel(zhuce);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 90, 91, 20));
        label_2 = new QLabel(zhuce);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 140, 81, 20));
        label_3 = new QLabel(zhuce);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 190, 91, 20));
        pushButton = new QPushButton(zhuce);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 260, 75, 23));

        retranslateUi(zhuce);

        QMetaObject::connectSlotsByName(zhuce);
    } // setupUi

    void retranslateUi(QWidget *zhuce)
    {
        zhuce->setWindowTitle(QApplication::translate("zhuce", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("zhuce", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("zhuce", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("zhuce", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("zhuce", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class zhuce: public Ui_zhuce {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUCE_H

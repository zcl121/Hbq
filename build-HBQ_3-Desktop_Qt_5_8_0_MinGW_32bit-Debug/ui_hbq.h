/********************************************************************************
** Form generated from reading UI file 'hbq.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HBQ_H
#define UI_HBQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HBQ
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_p1;
    QLabel *label_p2;

    void setupUi(QWidget *HBQ)
    {
        if (HBQ->objectName().isEmpty())
            HBQ->setObjectName(QStringLiteral("HBQ"));
        HBQ->resize(800, 600);
        tableWidget = new QTableWidget(HBQ);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 20, 402, 402));
        tableWidget->setStyleSheet(QStringLiteral("background-image: url(:/image/bg1.jpg);"));
        tableWidget->setRowCount(8);
        tableWidget->setColumnCount(8);
        tableWidget->horizontalHeader()->setDefaultSectionSize(50);
        tableWidget->verticalHeader()->setDefaultSectionSize(50);
        tableWidget->verticalHeader()->setMinimumSectionSize(50);
        label = new QLabel(HBQ);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 500, 500));
        label->setMargin(5);
        label_2 = new QLabel(HBQ);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(500, 90, 70, 70));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setStyleSheet(QLatin1String("font: 75 28pt \"Agency FB\";\n"
"color: rgb(0, 255, 255);"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setMargin(0);
        label_4 = new QLabel(HBQ);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(500, 310, 70, 70));
        label_4->setStyleSheet(QLatin1String("font: 75 28pt \"Agency FB\";\n"
"color: rgb(0, 255, 255);"));
        label_4->setFrameShape(QFrame::Box);
        label_4->setMargin(0);
        label_p1 = new QLabel(HBQ);
        label_p1->setObjectName(QStringLiteral("label_p1"));
        label_p1->setGeometry(QRect(600, 100, 50, 50));
        label_p2 = new QLabel(HBQ);
        label_p2->setObjectName(QStringLiteral("label_p2"));
        label_p2->setGeometry(QRect(600, 320, 50, 50));

        retranslateUi(HBQ);

        QMetaObject::connectSlotsByName(HBQ);
    } // setupUi

    void retranslateUi(QWidget *HBQ)
    {
        HBQ->setWindowTitle(QApplication::translate("HBQ", "Form", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
        label_p1->setText(QString());
        label_p2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HBQ: public Ui_HBQ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HBQ_H

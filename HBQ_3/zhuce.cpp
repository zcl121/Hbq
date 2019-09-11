#include "zhuce.h"
#include "ui_zhuce.h"
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <stdio.h>
#include <QApplication>
#include <QMessageBox>



zhuce::zhuce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zhuce)
{
    ui->setupUi(this);

    int i=0;

    connect(ui->pushButton,&QPushButton::clicked,[&]()
    {
        QString yonghu;
        QString mima;

        yonghu=ui->lineEdit->text();
        mima=ui->lineEdit_2->text();


           qDebug() << yonghu;
           qDebug() << mima;
    });




}

zhuce::~zhuce()
{
    delete ui;
}

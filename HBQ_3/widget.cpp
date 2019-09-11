#include "widget.h"
#include "ui_widget.h"
#include "hbq.h"
#include "zhuce.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QPalette>
#include <QPixmap>
#include <QString>
#include <QDebug>


QString yonghu;
QString mima;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);



    QPalette palette;
    QPixmap pixmap(":/image/bg2.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);


    connect(ui->pushButton,&QPushButton::clicked,[&](){

        yonghu=ui->lineEdit->text();
        mima=ui->lineEdit_2->text();

        if(yonghu == "a" && mima =="1")
        {

            HBQ *h = new HBQ;
            this->hide();
            h->show();

        }
        else
        {
            QMessageBox::critical(this, "登录失败", "请输入的用户名或者密码错误");
        }

    });

    connect(ui->pushButton_2,&QPushButton::clicked,[&]()
    {
            zhuce *z =new zhuce;
            this->hide();
            z->show();

    });




}






Widget::~Widget()
{
    delete ui;
}

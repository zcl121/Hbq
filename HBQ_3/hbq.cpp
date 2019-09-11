#include "hbq.h"
#include "ui_hbq.h"
#include "widget.h"
#include <QPainter>
#include <QHeaderView>
#include <QLabel>
#include <QPixmap>
#include <QLineEdit>
#include <QDebug>
#include <QMouseEvent>
#include <QTableWidgetItem>
#include <QPalette>
#include <stdio.h>
#include <unistd.h>
#include <QString>
#include <QMessageBox>
QLabel *label[8][8];  //当鼠标获取点，在这个坐标位置创建一个label
int state[8][8]; //黑棋为1,白棋为2
int flag=0;    //标志位，判断黑白棋先下后下

int get[16];
int hei=2;    //获取棋盘上的黑棋数量
int bai=2;
int a[9]={0}; //判断黑棋的8个方向是否可惜啊
int b[9]={0};


int c[10];  //翻为黑棋
int d[10];  //翻为白棋
HBQ::HBQ(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HBQ)
{
    ui->setupUi(this);

    QPixmap pixp1;
    pixp1.load(":/image/black.png");
    ui->label_p1->setScaledContents(true);
    ui->label_p1->setPixmap(pixp1);
    QPixmap pixp2;
    pixp2.load(":/image/white.png");
    ui->label_p2->setScaledContents(true);
    ui->label_p2->setPixmap(pixp2);


    ui->label_2->setText(QString::number(hei));
    ui->label_2->setAlignment(Qt::AlignCenter);  //让label内容居中
    ui->label_4->setText(QString::number(bai));
    ui->label_4->setAlignment(Qt::AlignCenter);  //让label内容居中



    QPalette palette;
    QPixmap pixmap(":/image/bg2.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    HBQ::setPalette(palette);


    this->resize(700, 500);
    ui->tableWidget->horizontalHeader()->setVisible(false); //去掉表格的行首
    ui->tableWidget->verticalHeader()->setVisible(false);  //去掉列首

    QPixmap pix;
    pix.load(":/image/black.png");
    QPixmap pix1;
    pix1.load(":/image/white.png");
    label[3][3]=new QLabel;
    label[3][3]->setPixmap(pix);
    label[3][3]->setScaledContents(true);
    label[3][4]=new QLabel;
    label[3][4]->setPixmap(pix1);
    label[3][4]->setScaledContents(true);
    label[4][3]=new QLabel;
    label[4][3]->setPixmap(pix1);
    label[4][3]->setScaledContents(true);
    label[4][4]=new QLabel;
    label[4][4]->setPixmap(pix);
    label[4][4]->setScaledContents(true);
    ui->tableWidget->setCellWidget(3, 3, label[3][3]);
    ui->tableWidget->setCellWidget(3, 4, label[3][4]);
    ui->tableWidget->setCellWidget(4, 3, label[4][3]);
    ui->tableWidget->setCellWidget(4, 4, label[4][4]);

    state[3][3]=1;
    state[3][4]=2;
    state[4][3]=2;
    state[4][4]=1;





}

void HBQ::mousePressEvent(QMouseEvent *ev)
{

    int i=(ev->y()-20)/50;
    int j=(ev->x()-20)/50;
    int x,y;
    int zt,st;
    qDebug() << "i="<< i <<"j="<<j;

     hei=0;
     bai=0;


     if(flag==0 && state[i][j]==0)
     {
         a[1]=0,a[2]=0,a[3]=0,a[4]=0,a[5]=0,a[6]=0,a[7]=0,a[8]=0;
         c[0]=0,c[1]=0,c[2]=0,c[3]=0,c[4]=0,c[5]=0,c[6]=0,c[7]=0;
         //黑
        HBQ::zuoshang(i,j);
        HBQ::shang(i,j);
        HBQ::youshang(i,j);
        HBQ::you(i,j);
        HBQ::youxia(i,j);
        HBQ::xia(i,j);
        HBQ::zuoxia(i,j);
        HBQ::zuo(i,j);        //判断8个方向 1.第一个是否是不相同的子
                                        //2.for循环查找
                                        //3.如果在每个方向发现NULL立即退出
                                        //4.如果遍历到和落得棋子相同的棋子，就给数组a[]对应的值


        if(a[1]==1 || a[2]==2 || a[3]==3 || a[4]==4  ||
           a[5]==5  || a[6]==6  || a[7]==7  || a[8]==8 )    //判断8个方向是否有一个发现有对应的值
        {
            QPixmap pix;
            pix.load(":/image/black.png");
            label[i][j]=new QLabel;
            label[i][j]->setPixmap(pix);                    //有则下子
            label[i][j]->setScaledContents(true);
            ui->tableWidget->setCellWidget(i, j, label[i][j]);
            state[i][j]=1;

            for(int dd=1;dd<=8;dd++)
            {
                switch (a[dd])
                {
                case 1:
                    for(int k=1;k<c[0];k++)
                    {

                            QPixmap pix1;
                            pix1.load(":/image/black.png");
                            label[i+k][j]=new QLabel;
                            label[i+k][j]->setPixmap(pix1);
                            label[i+k][j]->setScaledContents(true);
                            ui->tableWidget->setCellWidget(i+k, j, label[i+k][j]);
                            state[i+k][j]=1;

                    }
                    continue;
                case 2:                                             //将搜索到可以下棋子的方向的其他棋子翻转
                    for(int k=1;k<c[1];k++)
                    {

                            QPixmap pix1;
                            pix1.load(":/image/black.png");
                            label[i][j-k]=new QLabel;
                            label[i][j-k]->setPixmap(pix1);
                            label[i][j-k]->setScaledContents(true);
                            ui->tableWidget->setCellWidget(i, j-k, label[i][j-k]);
                            state[i][j-k]=1;
                      }
                    continue;
                case 3:
                    for(int k=1;k<c[2];k++)
                    {

                            QPixmap pix1;
                            pix1.load(":/image/black.png");
                            label[i][j+k]=new QLabel;
                            label[i][j+k]->setPixmap(pix1);
                            label[i][j+k]->setScaledContents(true);
                            ui->tableWidget->setCellWidget(i, j+k, label[i][j+k]);
                            state[i][j+k]=1;
                      }
                    continue;
                case 4:
                    for(int k=1; k<c[3];k++)
                    {

                            QPixmap pix1;
                            pix1.load(":/image/black.png");
                            label[i-k][j-k]=new QLabel;
                            label[i-k][j-k]->setPixmap(pix1);
                            label[i-k][j-k]->setScaledContents(true);
                            ui->tableWidget->setCellWidget(i-k, j-k, label[i-k][j-k]);
                            state[i-k][j-k]=1;
                      }
                    continue;
                case 5:
                    for(int k=1;k<c[4];k++)
                    {

                            QPixmap pix1;
                            pix1.load(":/image/black.png");
                            label[i+k][j-k]=new QLabel;
                            label[i+k][j-k]->setPixmap(pix1);
                            label[i+k][j-k]->setScaledContents(true);
                            ui->tableWidget->setCellWidget(i+k, j-k, label[i+k][j-k]);
                            state[i+k][j-k]=1;
                      }
                    continue;
                case 6:
                    for(int k=1; k<c[5]; k++)
                    {

                            QPixmap pix1;
                            pix1.load(":/image/black.png");
                            label[i-k][j+k]=new QLabel;
                            label[i-k][j+k]->setPixmap(pix1);
                            label[i-k][j+k]->setScaledContents(true);
                            ui->tableWidget->setCellWidget(i-k, j+k, label[i-k][j+k]);
                            state[i-k][j+k]=1;
                      }
                    continue;
                case 7:
                    for(int k=1; k<c[6]; k++)
                    {

                            QPixmap pix1;
                            pix1.load(":/image/black.png");
                            label[i+k][j+k]=new QLabel;
                            label[i+k][j+k]->setPixmap(pix1);
                            label[i+k][j+k]->setScaledContents(true);
                            ui->tableWidget->setCellWidget(i+k, j+k, label[i+k][j+k]);
                            state[i+k][j+k]=1;
                      }
                    continue;
                case 8:
                    for(int k=1;k<c[7];k++)
                    {

                            QPixmap pix1;
                            pix1.load(":/image/black.png");
                            label[i-k][j]=new QLabel;
                            label[i-k][j]->setPixmap(pix1);
                            label[i-k][j]->setScaledContents(true);
                            ui->tableWidget->setCellWidget(i-k, j, label[i-k][j]);
                           state[i-k][j]=1;
                    }
                    continue;
                default:
                    break;
                }
            }

            flag=1;
        }else
            flag=0;


        zt=0;
        for(int n=0;n<8;n++)
        {
            for(int m=0;m<8;m++)
            {
                if(a[1]==1 || a[2]==2 || a[3]==3 || a[4]==4  ||a[5]==5  ||
                        a[6]==6  || a[7]==7  || a[8]==8)
                {

                    zt=1;
                }
            }
        }

        if(zt!=1)
        {
           flag=1;
        }



     }
     else if(flag==1 && state[i][j]==0)
     {
         b[1]=0,b[2]=0,b[3]=0,b[4]=0,b[5]=0,b[6]=0,b[7]=0,b[8]=0;
         d[0]=0,d[1]=0,d[2]=0,d[3]=0,d[4]=0,d[5]=0,d[6]=0,d[7]=0;
         //白
         HBQ::bzuoshang(i,j);
         HBQ::bshang(i,j);
         HBQ::byoushang(i,j);
         HBQ::byou(i,j);
         HBQ::byouxia(i,j);
         HBQ::bxia(i,j);
         HBQ::bzuoxia(i,j);
         HBQ::bzuo(i,j);

         if(b[1]==1 || b[2]==2 || b[3]==3 || b[4]==4  ||
                 b[5]==5  || b[6]==6  || b[7]==7  || b[8]==8)

         {
             QPixmap pix;
             pix.load(":/image/white.png");
             label[i][j]=new QLabel;
             label[i][j]->setPixmap(pix);
             label[i][j]->setScaledContents(true);
             ui->tableWidget->setCellWidget(i, j, label[i][j]);
             state[i][j]=2;
             for(int tt=1;tt<=8;tt++)
             {
                 switch (b[tt])
                 {
                 case 1:
                     for(int k=1;k<d[0];k++)
                     {

                             QPixmap pix1;
                             pix1.load(":/image/white.png");
                             label[i-k][j]=new QLabel;
                             label[i-k][j]->setPixmap(pix1);
                             label[i-k][j]->setScaledContents(true);
                             ui->tableWidget->setCellWidget(i-k, j, label[i-k][j]);
                             state[i-k][j]=2;
                       }
                     continue;
                 case 2:
                     for(int k=1;k<d[1];k++)
                     {

                             QPixmap pix1;
                             pix1.load(":/image/white.png");
                             label[i+k][j]=new QLabel;
                             label[i+k][j]->setPixmap(pix1);
                             label[i+k][j]->setScaledContents(true);
                             ui->tableWidget->setCellWidget(i+k, j, label[i+k][j]);
                             state[i+k][j]=2;
                      }
                     continue;
                 case 3:
                     for(int k=1;k<d[2];k++)
                     {

                             QPixmap pix1;
                             pix1.load(":/image/white.png");
                             label[i][j-k]=new QLabel;
                             label[i][j-k]->setPixmap(pix1);
                             label[i][j-k]->setScaledContents(true);
                             ui->tableWidget->setCellWidget(i, j-k, label[i][j-k]);
                             state[i][j-k]=2;
                       }
                     continue;
                 case 4:
                     for(int k=1;k<d[3];k++)
                     {

                             QPixmap pix1;
                             pix1.load(":/image/white.png");
                             label[i][j+k]=new QLabel;
                             label[i][j+k]->setPixmap(pix1);
                             label[i][j+k]->setScaledContents(true);
                             ui->tableWidget->setCellWidget(i, j+k, label[i][j+k]);
                             state[i][j+k]=2;
                       }
                     continue;
                 case 5:
                     for(int k=1;k<d[4];k++)
                     {

                             QPixmap pix1;
                             pix1.load(":/image/white.png");
                             label[i-k][j-k]=new QLabel;
                             label[i-k][j-k]->setPixmap(pix1);
                             label[i-k][j-k]->setScaledContents(true);
                             ui->tableWidget->setCellWidget(i-k, j-k, label[i-k][j-k]);
                             state[i-k][j-k]=2;
                       }
                     continue;
                 case 6:
                     for(int k=1;k<d[5];k++)
                     {

                             QPixmap pix1;
                             pix1.load(":/image/white.png");
                             label[i+k][j-k]=new QLabel;
                             label[i+k][j-k]->setPixmap(pix1);
                             label[i+k][j-k]->setScaledContents(true);
                             ui->tableWidget->setCellWidget(i+k, j-k, label[i+k][j-k]);
                             state[i+k][j-k]=2;
                       }
                     continue;
                 case 7:
                     for(int k=1; k<d[6];k++)
                     {

                             QPixmap pix1;
                             pix1.load(":/image/white.png");
                             label[i-k][j+k]=new QLabel;
                             label[i-k][j+k]->setPixmap(pix1);
                             label[i-k][j+k]->setScaledContents(true);
                             ui->tableWidget->setCellWidget(i-k, j+k, label[i-k][j+k]);
                             state[i-k][j+k]=2;
                       }
                     continue;
                 case 8:
                     for(int k=1;k<d[7];k++)
                     {

                             QPixmap pix1;
                             pix1.load(":/image/white.png");
                             label[i+k][j+k]=new QLabel;
                             label[i+k][j+k]->setPixmap(pix1);
                             label[i+k][j+k]->setScaledContents(true);
                             ui->tableWidget->setCellWidget(i+k, j+k, label[i+k][j+k]);
                             state[i+k][j+k]=2;
                       }
                     continue;
                 default:
                     break;
                 }
             }

             flag=0;
         }
         else
             flag=1;





         st=0;
         for(int n=0;n<8;n++)
         {
             for(int m=0;m<8;m++)
             {
                 if(b[1]==1 || b[2]==2 || b[3]==3 || b[4]==4  ||b[5]==5  ||
                         b[6]==6  || b[7]==7  || b[8]==8)
                 {
                     st=1;
                 }
             }
         }
         if(st!=1)
         {
            flag=0;
         }


     }


     for(x=0;x<8;x++)
     {
         for(y=0;y<8;y++)
         {
             if(state[x][y]==1)
             {

                 hei=hei+1;
                 ui->label_2->setText(QString::number(hei));
                 ui->label_2->setAlignment(Qt::AlignCenter);

             }
             if(state[x][y]==2)
             {
                 bai=bai+1;
                 ui->label_4->setText(QString::number(bai));
                 ui->label_4->setAlignment(Qt::AlignCenter);

             }
             if(hei+bai==64)
             {
                 if(hei>bai)
                 {

                     QMessageBox::information(this, "结果", "黑棋胜利");
                 }
                 else if(bai>hei)
                 {
                     QMessageBox::information(this, "结果", "白棋胜利");
                 }
                 else if(bai==hei)
                 {
                     QMessageBox::information(this, "结果", "平局");
                 }


             }

         }
     }
     if(hei==0 && bai!=0)
              QMessageBox::information(this, "结果", "白棋d胜利");
      if(bai==0 && hei!=0)
              QMessageBox::information(this, "结果", "黑棋d胜利");




}


void HBQ::xia(int &i, int &j)
{

    if(state[i+1][j]==2)
    {
          for(int upx=i+1;upx<=7;upx++)
          {
              if(state[upx][j]==0)
                  break;
              if(state[upx][j]==1)
              {
                    a[1]=1;
                    c[0]=upx-i;
                    break;
              }

          }


    }

}
void HBQ::zuo(int &i, int &j)
{
    if(state[i][j-1]==2)
    {

          for(int upx=j-1;upx>=0;upx--)
          {

              if(state[i][upx]==0)
                  break;
              if(state[i][upx]==1)
              {
                a[2]=2;
                c[1]=j-upx;

                  break;

              }
          }
      }

}
void HBQ::you(int &i, int &j)
{
    if(state[i][j+1]==2)
    {

          for(int upx=j+1;upx<=7;upx++)
          {

              if(state[i][upx]==0)
                  break;
              if(state[i][upx]==1)
              {

                a[3]=3;
                c[2]=upx-j;

                break;
              }
          }
    }


}
void HBQ::zuoshang(int &i, int &j)
{
    if(state[i-1][j-1]==2)
    {

          for(int upx=i-1,upy=j-1;upx>=0 && upy>=0;upx--,upy--)
          {

              if(state[upx][upy]==0)
                  break;
              if(state[upx][upy]==1)
              {

            a[4]=4;
            c[3]=i-upx;

                  break;

              }
          }
      }

}
void HBQ::zuoxia(int &i, int &j)
{
    if(state[i+1][j-1]==2)
    {

          for(int upx=i+1,upy=j-1;upx<=7&&upy>=0;upx++,upy--)
          {

              if(state[upx][upy]==0)
                  break;
              if(state[upx][upy]==1)
              {
                a[5]=5;
                c[4]=upx-i;

                 break;
              }
          }
      }



}
void HBQ::youshang(int &i, int &j)
{
    if(state[i-1][j+1]==2)
    {

          for(int upx=i-1,upy=j+1;upx>=0 && upy<=7;upx--,upy++)
          {

              if(state[upx][upy]==0)
                  break;
              if(state[upx][upy]==1)
              {

                a[6]=6;
                c[5]=i-upx;

                 break;
              }
          }
      }

}
void HBQ::youxia(int &i, int &j)
{
    if(state[i+1][j+1]==2)
    {

          for(int upx=i+1,upy=j+1;upx<=7 &&upy<=7;upx++,upy++)
          {

              if(state[upx][upy]==0)
                  break;
              if(state[upx][upy]==1)
              {

                a[7]=7;
                c[6]=upx-i;
                 break;
              }
          }
      }

}
void HBQ::bshang(int &i, int &j)
{

    if(state[i-1][j]==1)
    {


          for(int upx=i-1;upx>=0;upx--)
          {

              if(state[upx][j]==0)
                  break;
              if(state[upx][j]==2)
              {

               b[1]=1;
               d[0]=i-upx;


             break;
              }


          }
      }
}
void HBQ::bxia(int &i, int &j)
{
    if(state[i+1][j]==1)
    {

          for(int upx=i+1;upx<=7;upx++)
          {

              if(state[upx][j]==0)
              {

                  break;
              }
              if(state[upx][j]==2)
              {
                qDebug() << "D";
                b[2]=2;
                d[1]=upx-i;

                 break;
              }


          }


    }

}
void HBQ::bzuo(int &i, int &j)
{
    if(state[i][j-1]==1)
    {

          for(int upx=j-1;upx>=0;upx--)
          {

              if(state[i][upx]==0)
                  break;
              if(state[i][upx]==2)
              {

                    b[3]=3;
                    d[2]=j-upx;
                 break;
              }
          }
      }

}
void HBQ::byou(int &i, int &j)
{
    if(state[i][j+1]==1)
    {

          for(int upx=j+1;upx<=7;upx++)
          {

              if(state[i][upx]==0)
                  break;
              if(state[i][upx]==2)
              {

                b[4]=4;
                d[3]=upx-j;

                     break;
              }
          }
    }



}
void HBQ::bzuoshang(int &i, int &j)
{
    if(state[i-1][j-1]==1)
    {

          for(int upx=i-1,upy=j-1;upx>=0&&upy>=0;upx--,upy--)
          {

              if(state[upx][upy]==0)
                  break;
              if(state[upx][upy]==2)
              {
                    b[5]=5;
                    d[4]=i-upx;

                 break;
              }
          }
      }


}
void HBQ::bzuoxia(int &i, int &j)
{
    if(state[i+1][j-1]==1)
    {

          for(int upx=i+1,upy=j-1;upx<=7 && upy>=0;upx++,upy--)
          {

              if(state[upx][upy]==0)
                  break;
              if(state[upx][upy]==2)
              {

                    b[6]=6;
                    d[5]=upx-i;

                 break;
              }
          }
      }


}
void HBQ::byoushang(int &i, int &j)
{
    if(state[i-1][j+1]==1)
    {

          for(int upx=i-1,upy=j+1;upx>=0 && upy<=7;upx--,upy++)
          {

              if(state[upx][upy]==0)
                  break;
              if(state[upx][upy]==2)
              {

                b[7]=7;
                d[6]=i-upx;

                 break;
              }
          }
      }


}
void HBQ::byouxia(int &i, int &j)
{
    if(state[i+1][j+1]==1)
    {


          for(int upx=i+1,upy=j+1;upx<=7 && upy<=7;upx++,upy++)
          {

              if(state[upx][upy]==0)
                  break;
              if(state[upx][upy]==2)
              {

               b[8]=8;
               d[7]=upx-i;

                 break;
              }
          }
      }

}
void HBQ::shang(int &i, int &j)
{
    if(state[i-1][j]==2)
    {

          for(int upx=i-1;upx>=0;upx--)
          {

              if(state[upx][j]==0)
                  break;
              if(state[upx][j]==1)
              {

                a[8]=8;
                c[7]=i-upx;

                 break;
              }

          }
      }



}


HBQ::~HBQ()
{
    delete ui;
}

#ifndef HBQ_H
#define HBQ_H

#include <QWidget>

namespace Ui {
class HBQ;
}

class HBQ : public QWidget
{
    Q_OBJECT

public:
    explicit HBQ(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
//    void mouseReleaseEvent(QMouseEvent *ev);
    //黑棋
    void shang(int &i,int &j);
    void xia(int &i,int &j);
    void zuo(int &i,int &j);
    void you(int &i,int &j);
    void zuoshang(int &i,int &j);
    void zuoxia(int &i,int &j);
    void youshang(int &i,int &j);
    void youxia(int &i,int &j);
    //白棋
    void bshang(int &i,int &j);
    void bxia(int &i,int &j);
    void bzuo(int &i,int &j);
    void byou(int &i,int &j);
    void bzuoshang(int &i,int &j);
    void bzuoxia(int &i,int &j);
    void byoushang(int &i,int &j);
    void byouxia(int &i,int &j);



    ~HBQ();

private:
    Ui::HBQ *ui;
};

#endif // HBQ_H

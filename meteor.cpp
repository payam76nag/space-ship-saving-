#include "meteor.h"
#include <QGraphicsScene>
#include <QTime>
#include <QDebug>
extern int score;
void Srockymeteor::death()
{
    timer=new QTimer;
    timer->setInterval(4000);
    connect(timer,SIGNAL(timeout()),SLOT(destroy()));
    timer->start();

}

Srockymeteor::Srockymeteor(int a)
{
    setPixmap(QPixmap(":/image/meteor.png"));

    lifetime=a;
    health=1000;
    setScale(0.1);


}

void Srockymeteor::destroy(){

    delete this;

}


void mGenerator::generaterock()
{
    qDebug()<<score;
    if(score<100 && score>=0)
    {
    QTime time = QTime::currentTime();
     qsrand((uint)time.msec());
    Srockymeteor * rock=new Srockymeteor(2000);
   scene->addItem(rock);
   rock->setScale(0.3);
    rock->setPos(qrand()%700,qrand()%200);

   rock->death();
    Srockymeteor* rock2=new  Srockymeteor(2000);
   scene->addItem(rock2);
   rock2->setScale(0.3);
   rock2->setPos(qrand()%700,qrand()%700);
   rock2->death();



    Srockymeteor * rock3=new  Srockymeteor(2000);
   scene->addItem(rock3);
   rock3->setScale(0.3);
   rock3->setPos(qrand()%700,qrand()%200+200);
   rock3->death();

   Srockymeteor * rock4=new  Srockymeteor(2000);
  scene->addItem(rock4);
  rock4->setScale(0.3);
  rock4->setPos(qrand()%700,qrand()%200+500);
  rock4->death();

  Srockymeteor * rock5=new  Srockymeteor(2000);
 scene->addItem(rock5);
 rock5->setScale(0.3);
 rock5->setPos(qrand()%700,qrand()%200+300);
 rock5->death();
    }
    if(score<150 && score>=100)
    {
    QTime time= QTime::currentTime();
     qsrand((uint)time.msec());
    rockymeteor * rock=new rockymeteor;
   scene->addItem(rock);
   rock->setScale(0.1);
    rock->setPos(qrand()%700,qrand()%200);

   rock->death();
    Srockymeteor* rock2=new  Srockymeteor(2000);
   scene->addItem(rock2);
   rock2->setScale(0.3);
   rock2->setPos(qrand()%700,qrand()%700);
   rock2->death();



    Srockymeteor * rock3=new  Srockymeteor(2000);
   scene->addItem(rock3);
   rock3->setScale(0.3);
   rock3->setPos(qrand()%700,qrand()%200);
   rock3->death();

   Srockymeteor * rock4=new  Srockymeteor(2000);
  scene->addItem(rock4);
  rock4->setScale(0.3);
  rock4->setPos(qrand()%700,qrand()%200+500);
  rock4->death();


    }

    if(score<200 && score>=150)
    {
    QTime time= QTime::currentTime();
     qsrand((uint)time.msec());
    metalmeteor * rock=new metalmeteor(10);
   scene->addItem(rock);
   rock->setScale(0.1);
    rock->setPos(qrand()%700,qrand()%200);

   rock->death();
    Srockymeteor* rock2=new  Srockymeteor(2000);
   scene->addItem(rock2);
   rock2->setScale(0.3);
   rock2->setPos(qrand()%700,qrand()%700);
   rock2->death();



    Srockymeteor * rock3=new  Srockymeteor(2000);
   scene->addItem(rock3);
   rock3->setScale(0.3);
   rock3->setPos(qrand()%700,qrand()%200);
   rock3->death();

   Srockymeteor * rock4=new  Srockymeteor(2000);
  scene->addItem(rock4);
  rock4->setScale(0.3);
  rock4->setPos(qrand()%700,qrand()%200+500);
  rock4->death();


    }


}

void metalmeteor::death()
{
    if(x()<10 || x()>800|| y()<10 || y()>800)
        delete this;
}

metalmeteor::metalmeteor(int a)
{
    setPixmap(QPixmap(":/image/metalmet.png"));
    speed=a;

    QTime time = QTime::currentTime();
     qsrand((uint)time.msec());
    dir=qrand()%2;
    movetimer=new QTimer;
    movetimer->setInterval(a);
    movetimer->start();
    connect(movetimer,SIGNAL(timeout()),this,SLOT(move()));
}

void metalmeteor::move()
{
    QTime time1 = QTime::currentTime();
     qsrand((uint)time1.msec());
    if(dir)
    {
       if(qrand()%2)
       {
           setX(x()+1);
       }
       else
       {
           setY(y()+1);
       }
    }
    else{
        if(qrand()%2)
        {
            setX(x()-1);
        }
        else
        {
            setY(y()-1);
        }
    }
    death();
}

rockymeteor::rockymeteor()
{
    setPixmap(QPixmap(":/image/srock.png"));

    QTime time = QTime::currentTime();
     qsrand((uint)time.msec());
    dir1=qrand()%2;

    QTime time1 = QTime::currentTime();
     qsrand((uint)time1.msec());
    dir1=qrand()%2;

    lifetime=new QTimer;
    lifetime->setInterval(20);
    lifetime->start();
    connect(lifetime,SIGNAL(timeout()),this,SLOT(move()));

    movetimer=new QTimer;
    movetimer->setInterval(20);
    movetimer->start();
    connect(movetimer,SIGNAL(timeout()),this,SLOT(move()));
}

void rockymeteor::death()
{
    if(x()<10 || x()>800|| y()<10 || y()>800)
        delete this;
}

void rockymeteor::move()
{
    if(dir1)
    {
       if(dir2)
       {
           setX(x()+1);
       }
       else
       {
           setY(y()+1);
       }
    }
    else{
        if(qrand()%2)
        {
            setX(x()-1);
        }
        else
        {
            setY(y()-1);
        }
    }
    death();
}

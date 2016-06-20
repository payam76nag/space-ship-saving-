#ifndef METEOR_H
#define METEOR_H
#include <QGraphicsPixmapItem>
#include <QTimer>
class meteor :public QGraphicsPixmapItem
{
public:
    virtual void damage()=0;
    virtual void death()=0;
    meteor();

protected:
    int health;
    int damage;

};
class metalmeteor:public meteor
{
public:
    void move();
    virtual void damage();
    virtual void death();
    metalmeteor(int);
private:
    int speed;
    QTimer * movetimer;
};
class Srockymeteor:public meteor
{
public:
    virtual void damage();
    virtual void death();
    Srockymeteor(int);
private:
    int decHstep;
    QTimer * Htime;


};
class rockymeteor:public meteor
{
public :
    void move();
    virtual void damage();
    virtual void death();
private:
   QTimer * movetimer;
};

#endif // METEOR_H

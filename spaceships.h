#ifndef SPACESHIPS_H
#define SPACESHIPS_H
#include <QGraphicsPixmapItem>
class spaceship:public QGraphicsPixmapItem
{
public:
    virtual void moveH(bool)=0;
    virtual void moveV(bool)=0;
    virtual void damage()=0;
    virtual void death();
protected:
    QTimer * HmoveTimer;
    QTimer * VmoveTimer;
};
class Nship:public spaceship
{
public:
    virtual void moveH(bool);
    virtual void moveV(bool);
    virtual void damage();
private:
    int health;
};
class Negship:public spaceship
{
public:
    virtual void moveH(bool);
    virtual void moveV(bool);
    virtual void damage();
private:
    int health;
    bool direction;


};
class randship:public spaceship
{
public:
    virtual void moveH(bool);
    virtual void moveV(bool);
    virtual void damage();
private:
    int health;
    bool direction;
    void chdirectoin();
};
class lifeTNship: public Nship
{
public:
    virtual void damage();
private:
    QTimer * lifeTime;
};
class lifeTnegship:public Nship
{
public:
    virtual void damage();
private:
    QTimer * lifeTime;
};

#endif // SPACESHIPS_H

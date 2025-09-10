#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class WalkableRobot{
    public:
        virtual void walk() = 0;
        virtual ~WalkableRobot(){}
};
class NormalWalk:public  WalkableRobot
{
    void walk()override{
        cout << "walking normally...." << endl;
    }
};
class NoWalk : public WalkableRobot
{
    void walk() override
    {
        cout << "cannot walk...." << endl;
    }
};

class TalkableRobot
{
    public:
    virtual void talk() = 0;
    virtual ~TalkableRobot(){}
};
class NormalTalk : public TalkableRobot
{
    void talk()override{
        cout << "talking normally...." << endl;
    }
};
class NoTalk : public TalkableRobot
{
    void talk() override
    {
        cout << "cannor talk...." << endl;
    }
};

class FlyableRobot
{
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};
class NormalFly : public FlyableRobot
{
    void fly() override
    {
        cout << "flying normally...." << endl;
    }
};
class NoFly : public FlyableRobot
{
    void fly() override
    {
        cout << "cannot fly...." << endl;
    }
};

//--------------Robot Base Class-------
class Robot{
    protected:
    WalkableRobot *walkBehavior;
    TalkableRobot *talkBehavior;
    FlyableRobot *flyBehavior;

public:
    Robot(WalkableRobot *w, TalkableRobot *t, FlyableRobot*f){
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
    }

    void walk(){
        walkBehavior->walk();
    }
    void talk()
    {
        talkBehavior->talk();
    }
    void fly()
    {
        flyBehavior->fly();
    }

    virtual void projection() = 0;  //abstract method for subclasses
};

//Concrete Robot Types--------

class CompanionRobot:public Robot{
    public:
    CompanionRobot(WalkableRobot*w,TalkableRobot*t,FlyableRobot*f):Robot(w,t,f){}

    void projection()override{
        cout << "displaying friendly companion features..." << endl;
    };
};

class WorkerRobot : public Robot
{
public:
    WorkerRobot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f) : Robot(w, t, f) {}

    void projection() override
    {
        cout << "displaying worker companion features..." << endl;
    };
};

int main()
{
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout << "--------------------" << endl;

    Robot *robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();
    return 0;

}

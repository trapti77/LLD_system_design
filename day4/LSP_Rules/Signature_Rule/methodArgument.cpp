// Signature Rule --
//(1) Method Override rule
//(2) Return Type Rule
//(3) Exception Rule

#include <iostream>
using namespace std;

class Parent
{
public:
    virtual void print(string s)
    {
        cout << "Parent : " << s << endl;
    }
};
class Child : public Parent
{
public:
    void print(string s) override  //Here Parent Argument Should Be Same As Parent Class
    {
        cout << "Child : " << s << endl;
    }
};
class Client
{
private:
    Parent *p;

public:
    Client(Parent *p)
    {
        this->p = p;
    }
    void printmsg()
    {
        p->print("hello");
    }
};

int main()
{
    Parent *p = new Parent();
    Parent *c = new Child();

    Client *client = new Client(c);
    client->printmsg();
    return 0;
}
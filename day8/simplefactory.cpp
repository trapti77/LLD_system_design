#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};
class SimpleBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "simple burger prepared" << endl;
    }
};
class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "standard burger prepared" << endl;
    }
};
class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "premium burger prepared" << endl;
    }
};
class BurgerFactoy
{
public:
    Burger *createBurger(string &type)
    {
        if (type == "basic")
        {
            return new SimpleBurger();
        }
        else if (type == "standard")
        {
            return new StandardBurger();
        }
        else if (type == "premium")
        {
            return new PremiumBurger();
        }
    }
};
int main()
{
    string type;
    cin >> type;
    BurgerFactoy *burgerFactory = new BurgerFactoy();

    Burger *burger = burgerFactory->createBurger(type);

    burger->prepare();

    return 0;
}
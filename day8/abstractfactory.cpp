#include <iostream>

using namespace std;

// Product 1
class Burger
{
public:
    virtual void prepare() = 0; // Pure virtual function
    virtual ~Burger() {}        // Virtual destructor
};

class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};

class BasicWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Wheat Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Wheat Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Wheat Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};



//Product 2
class GarlicBread
{
public:
    virtual void prepare() = 0; // Pure virtual function
    virtual ~GarlicBread() {}   // Virtual destructor
};

class BasicGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Basic GarlicBread with bun, patty, and ketchup!" << endl;
    }
};

class StandardGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Standard GarlicBread with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Premium GarlicBread with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};

class BasicWheatGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Wheat GarlicBread with bun, patty, and ketchup!" << endl;
    }
};

class StandardWheatGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Wheat GarlicBread with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumWheatGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Wheat GarlicBread with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};



// Factory
class Factory
{
public:
    virtual Burger *createBurger(string &type) = 0;
    virtual GarlicBread *createGarlicBread(string &type) = 0;
};

//Type1 Factory
class Sing : public Factory
{
public:
    Burger *createBurger(string &type) override
    {
        if (type == "basic")
        {
            return new BasicBurger();
        }
        else if (type == "standard")
        {
            return new StandardBurger();
        }
        else if (type == "premium")
        {
            return new PremiumBurger();
        }
        else
        {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
    GarlicBread *createGarlicBread(string &type) override
    {
        if (type == "basic")
        {
            return new BasicGarlicBread();
        }
        else if (type == "standard")
        {
            return new StandardGarlicBread();
        }
        else if (type == "premium")
        {
            return new PremiumGarlicBread();
        }
        else
        {
            cout << "Invalid GarlicBread type! " << endl;
            return nullptr;
        }
    }
};


//Type2 Factory
class King : public Factory
{
public:
    Burger *createBurger(string &type) override
    {
        if (type == "basic")
        {
            return new BasicWheatBurger();
        }
        else if (type == "standard")
        {
            return new StandardWheatBurger();
        }
        else if (type == "premium")
        {
            return new PremiumWheatBurger();
        }
        else
        {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
    GarlicBread *createGarlicBread(string &type) override
    {
        if (type == "basic")
        {
            return new BasicWheatGarlicBread();
        }
        else if (type == "standard")
        {
            return new StandardWheatGarlicBread();
        }
        else if (type == "premium")
        {
            return new PremiumWheatGarlicBread();
        }
        else
        {
            cout << "Invalid GarlicBread type! " << endl;
            return nullptr;
        }
    }
};

int main()
{
    string type = "basic";

    Factory *singFactory = new Sing();

    Burger *burger = singFactory->createBurger(type);
    GarlicBread *bread = singFactory->createGarlicBread(type);

    burger->prepare();
    bread->prepare();

    // Factory *kingFactory = new King();

    // Burger *burger = kingFactory->createBurger(type);
    // GarlicBread *bread = kingFactory->createGarlicBread(type);

    // burger->prepare();
    // bread->prepare();

    return 0;
}

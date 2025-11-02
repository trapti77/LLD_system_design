// SingleTon Design Pattern

#include <iostream>
#include<mutex>


using namespace std;

class Singleton
{
private:
    static Singleton *instance;
    static mutex mtx;
    Singleton()
    {
        cout << "constructor called" << endl;
    }

public:
    // Double check locking..
    static Singleton *getInstance()
    {
        if (instance == nullptr) // First check (no locking)
        {                            
            lock_guard<mutex> lock(mtx); // Lock only if needed
            if (instance == nullptr)
            { // Second check (after acquiring lock)
                instance = new Singleton();
            }
        }
        return instance;
    }
};

Singleton *Singleton::instance = nullptr;
mutex Singleton::mtx;

int main()
{
    Singleton *s1 = Singleton::Getinstance();
    Singleton *s2 = Singleton::Getinstance();

    cout << (s1 == s2) << endl;
    return 0;
}
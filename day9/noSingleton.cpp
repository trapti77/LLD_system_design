// SingleTon Design Pattern

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Singleton
{

public:
    Singleton()
    {
        cout << "constructor called" << endl;
    }
};

int main()
{
    Singleton *s1 = new Singleton();
    Singleton *s2 =new  Singleton();

    cout << (s1 == s2) << endl;
    return 0;
}
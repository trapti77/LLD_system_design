//SingleTon Design Pattern

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Singleton{
 private:
 static Singleton*instance;

 Singleton(){
     cout << "constructor called" << endl;
 }

 public:
 static Singleton*Getinstance(){
    if(instance==nullptr){
        instance = new Singleton();
    }
    return instance;
 }
    
};

Singleton*Singleton::instance = nullptr;

int main(){
    Singleton *s1 = Singleton::Getinstance();
    Singleton *s2 =Singleton::Getinstance();

        cout << (s1 == s2) << endl;
    return 0;
}
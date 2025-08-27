#include<iostream>
using namespace std;
// Class Invariant of a parent class Object should not be broken by child class Object.
// Hence child class can either maintain or strengthen the invariant but never narrows it down.

// Invariant : Balance cannot be negative
class BankAccount{
    protected:
    double balance;
 public:
  BankAccount(double b){
    if(b<0)
        throw invalid_argument("Invalid Balance ");
    balance = b;
  }
     virtual void withDraw(double amount){
       if(balance-amount<0)
           throw runtime_error("Insufficient Balance");
       balance -= amount;
       cout << "Amount Withdrawn . Remaining Amount " << balance << endl;
     }
};


//Breakes Invarient : Should Not Be Allowed
class CheatAccount:public BankAccount{
    public:
        CheatAccount(double b) : BankAccount(b) {}

        void withDraw(double amount) override{
            balance -= amount; // LSP break! Negative balance allowed
            cout << "Amount Withdrawn . Remaining Amount " << balance << endl;
        }

};

int main(){

    BankAccount *bank = new BankAccount(100);
    bank->withDraw(50);

    CheatAccount *cheat = new CheatAccount(300);
    cheat->withDraw(100);
    return 0;
}
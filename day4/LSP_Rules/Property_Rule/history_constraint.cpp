#include <iostream>
using namespace std;

// Sub class methods should not be allowed state changes What
// Base class never allowed.

class BankAccount
{
protected:
    double balance;

public:
    BankAccount(double b)
    {
        if (b < 0)
            throw invalid_argument("Invalid Balance ");
        balance = b;
    }

    // History Constraint : Withdraw should be allowed
    virtual void withDraw(double amount)
    {
        balance -= amount;
        cout << "Amount Withdrawn . Remaining Amount " << balance << endl;
    }
};

class FixedDeposit : public BankAccount
{
public:
    FixedDeposit(double b) : BankAccount(b) {}

    // LSP break! History constraint broke!
    // Parent class behaviour change : Now withdraw is not allowed.
    // This class will brake client code that relies on withdraw.
    void withDraw(double amount) override
    {
        throw runtime_error("wihtdraw not allowed in FixedDeposit");
    }
};

int main()
{

    BankAccount *bank = new BankAccount(100);
    bank->withDraw(50);

    FixedDeposit *fixeddeposit= new FixedDeposit(300);
    // fixeddeposit->withDraw(100);//throw error
    return 0;
}
#include<iostream>
#include<stdexcept>
using namespace std;
// Exception Rule:
// A subclass should throw fewer or narrower exceptions
// (but not additional or broader exceptions) than the parent.
// C++ does not enforces this. Hence no compilation error.

/*
├── std::logic_error        <-- For logical errors detected before runtime
│   ├── std::invalid_argument   <-- Invalid function argument
│   ├── std::domain_error       <-- Function argument domain error
│   ├── std::length_error       <-- Exceeding valid length limits
│   ├── std::out_of_range       <-- Array or container index out of bounds
│
├── std::runtime_error      <-- For errors that occur at runtime
│   ├── std::range_error        <-- Numeric result out of range
│   ├── std::overflow_error     <-- Arithmetic overflow
│   ├── std::underflow_error
*/
class Parent{
public:
virtual void getData() noexcept(false){
    throw logic_error("parent Error");
}
};
class Child:public Parent{
    void getData() noexcept(false) override
    {
        throw out_of_range("Child Error");//yaha pe subclass logic error ke varience ko to throw kr
        //skta hai but runtime error throw nh kr skta yah exception rule ko follow nhi krega
    }
};
class Client{
    private:
        Parent *p;
    public:
    Client(Parent*p){
        this->p = p;
    }
    void takeData(){
        try
        {
            p->getData();
            cout << "No Exception Occure" << endl;
        }
        catch(const logic_error& e)
        {
            cout <<"Logical Exception Error Occure : "<<e.what()<< endl;
        }
        
    }
};
int main(){
    Parent *p = new Parent();
    Child *c = new Child();
    Client *client = new Client(p);
    client->takeData();
    return 0;
}
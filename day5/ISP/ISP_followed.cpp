#include<iostream>
using namespace std;

class Shape{
    public:
        virtual double area() = 0;
        virtual double volume() = 0;
};

class Square:public Shape{
    private:
    double side;

public:
    Square(double s){
        this->side = s;
    }
    double area() override{
        return side * side;
    }
    double volume() override{
        throw logic_error("volume method not applicable in this class");
    }
};
class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override
    {
        return length * width;
    }

    double volume() override
    {
        throw logic_error("Volume not applicable for Rectangle"); // Unnecessary method
    }
};
class Cube : public Shape
{
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double area() override
    {
        return 6 * side * side;
    }

    double volume() override
    {
        return side * side * side;
    }
};

int main(){
    Shape *square = new Square(5);
    Shape *rectangle = new Rectangle(4, 6);
    Shape *cube = new Cube(3);

    cout << "Square Area: " << square->area() << endl;
    cout << "Rectangle Area: " << rectangle->area() << endl;
    cout << "Cube Area: " << cube->area() << endl;
    cout << "Cube Volume: " << cube->volume() << endl;

    try
    {
        cout << "Square Volume: " << square->volume() << endl; // Will throw an exception
    }
    catch (logic_error &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;

}
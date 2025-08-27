#include <iostream>
#include <vector>

using namespace std;

class Product
{
    string name;
    int price;

public:
    Product(int n, int p)
    {
        this->name = n;
        this->price = p;
    }
};

class Shoppingcart
{
    vector<Product *> products;

public:
    void addProduct(Product *p)
    {
        products.push_back(p);
    }
    const vector<Product *> getProduct()
    {
        return products;
    }

    void calculateTotalPrice()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        cout << "Total Price Of Products : " << total << endl;
    }
};
class ShoppingcartPrinter
{
    Shoppingcart *cart;

public:
    ShoppingcartPrinter(Shoppingcart *cart)
    {
        this->cart = cart;
    }
    void printInvoice()
    {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : cart->getProduct())
        {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << cart->calculateTotal() << endl;
    }
};
class SavetoDB
{
    Shoppingcart *cart;

public:
    SavetoDB(Shoppingcart *cart)
    {
        this->cart = cart;
    }
    void saveToDatabase()
    {
        cout << "Saving shopping cart to database..." << endl;
    }
};
int main()
{
    Shoppingcart *cart = new Shoppingcart();
    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));
    ShoppingcartPrinter *printer = new ShoppingcartPrinter(cart);
    printer->printInvoice();

    SavetoDB *db = new SavetoDB(cart);
    db->saveToDatabase();
    return 0;
}
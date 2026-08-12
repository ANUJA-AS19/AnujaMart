#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class User
{
private:
    string name;
    string email;
    string password;
    string role;

public:
    User() {}

    User(string n, string e, string p, string r)
    {
        name = n;
        email = e;
        password = p;
        role = r;
    }

    string getName()
    {
        return name;
    }

    string getEmail()
    {
        return email;
    }

    string getPassword()
    {
        return password;
    }

    string getRole()
    {
        return role;
    }
};

class Product
{
private:
    int id;
    string name;
    string description;
    double price;
    int stock;
    string category;

public:
    Product() {}

    Product(int i, string n, string d, double p, int s, string c)
    {
        id = i;
        name = n;
        description = d;
        price = p;
        stock = s;
        category = c;
    }

    int getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    string getDescription()
    {
        return description;
    }

    double getPrice()
    {
        return price;
    }

    int getStock()
    {
        return stock;
    }

    string getCategory()
    {
        return category;
    }

    void reduceStock(int quantity)
    {
        stock = stock - quantity;
    }

    void display()
    {
        cout << "\nProduct ID  : " << id;
        cout << "\nName        : " << name;
        cout << "\nDescription : " << description;
        cout << "\nPrice       : Rs." << fixed << setprecision(2) << price;
        cout << "\nStock       : " << stock;
        cout << "\nCategory    : " << category;
        cout << "\n--------------------------------------------\n";

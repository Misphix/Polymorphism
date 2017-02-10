#include <iostream>
#include <iomanip>

#include "magazine.h"

Magazine::Magazine(const string name, int price)
{
    this->name = name;
    this->price = price;
}

void Magazine::print_info() const
{
    Book::print_info();
    cout << "Magazine" << endl;
}

void Magazine::print_price() const
{
    cout.precision(2);
    cout << "Name: " << name << ", Sell: " << fixed << price * 0.7 << endl;
}
#include <iostream>
#include <iomanip>

#include "comic.h"

Comic::Comic(const string name, int price)
{
    this->name = name;
    this->price = price;
}

void Comic::print_info() const
{
    Book::print_info();
    cout << "Comic" << endl;
}

void Comic::print_price() const
{
    cout.precision(2);
    cout << "Name: " << name << ", Sell: " << fixed << price * 0.9 << endl;
}
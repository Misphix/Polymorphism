#include <iostream>
#include <iomanip>

#include "novel.h"

Novel::Novel(const string name, int price)
{
    this->name = name;
    this->price = price;
}

void Novel::print_info() const
{
    Book::print_info();
    cout << "Novel" << endl;
}

void Novel::print_price() const
{
    cout.precision(2);
    cout << "Name: " << name << ", Sell: " << fixed << price * 0.8 << endl;
}
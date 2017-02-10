#include <iostream>
#include <iomanip>

#include "book.h"

string Book::get_name() const
{
    return name;
}

void Book::print_info() const
{
    cout << "Name: " << setw(20) << left << name << ", Original Price: " << setw(5) << left << price << ", Type: ";
}
#include "book.h"

#ifndef MAGAZINE_H
#define MAGAZINE_H

class Magazine : public Book
{
    public:
        Magazine(const string, int);
        void print_info() const;
        void print_price() const;
};

#endif
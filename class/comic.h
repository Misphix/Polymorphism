#include "book.h"

#ifndef COMIC_H
#define COMIC_H

class Comic : public Book
{
    public:
        Comic(const string, int);
        void print_info() const;
        void print_price() const;
};

#endif
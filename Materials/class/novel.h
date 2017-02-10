#include "book.h"

#ifndef NOVEL_H
#define NOVEL_H

class Novel : public Book
{
    public:
        Novel(const string, int);
        void print_info() const;
        void print_price() const;
};

#endif
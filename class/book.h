using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book
{
    public:
        string get_name() const;
        virtual void print_info() const;
        virtual void print_price() const = 0;
    protected:
        string name;
        int price;
};

#endif
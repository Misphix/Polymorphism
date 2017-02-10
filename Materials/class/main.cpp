#include <iostream>
#include <locale>
#include <sstream>
#include <vector>

#include "comic.h"
#include "novel.h"
#include "magazine.h"

#define BOOK_TYPES 3

using namespace std;

vector<Book*> initialize_book();
int transfer_input(string);
void print_all_books_info(vector<Book*>);
void price_finder(vector<Book*>);

int main()
{
    vector<Book*> books = initialize_book();
    string input;

    while (1)
    {
        cout << "Book manage system: 1) List 2)Price 3)Exit" << endl;
        getline(cin, input);

        int option = transfer_input(input);

        switch (option)
        {
            case 1:
                print_all_books_info(books);
                break;
            case 2:
                price_finder(books);
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid input" << endl;
        }
    }

    return 0;
}

vector<Book*> initialize_book()
{
    vector<Book*> books;

    Book* comic = new Comic("Happy Tree Friends", 100);
    Book* novel = new Novel("Harry Potter", 200);
    Book* magazine = new Magazine("Times", 300);

    books.push_back(comic);
    books.push_back(novel);
    books.push_back(magazine);

    return books;
}

int transfer_input(string input)
{
    int result = -1;
    locale loc;

    if (isdigit(input[0], loc))
    {
        stringstream(input) >> result;
    }

    return result;
}

void print_all_books_info(vector<Book*> books)
{
    for (int i = 0; i < books.size(); ++i)
    {
        books[i]->print_info();
    }
}

void price_finder(vector<Book*> books)
{
    string input;
    cout << "Enter the book's name(100 character limited): ";
    getline(cin, input);

    for (int i = 0; i < books.size(); ++i)
    {
        string name = books[i]->get_name();

        if (name.compare(input) == 0)
        {
            books[i]->print_price();
            return;
        }
    }

    cout << "Book \"" << input << "\" not found" << endl;
}
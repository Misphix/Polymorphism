#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOK_TYPES 3

typedef enum
{
    Comic,
    Novel,
    Magazine
} book_type;

typedef struct Book
{
    char* name;
    int price;
    book_type type;
} Book;

Book* initialize_book();
int transfer_input(char*);
void print_all_books_info(Book*);
void print_comic_info(Book*);
void print_novel_info(Book*);
void print_magazine_info(Book*);
void price_finder(Book*);
void print_comic_price(Book*);
void print_novel_price(Book*);
void print_magazine_price(Book*);

void main()
{
    Book* books = initialize_book();
    char input[25];
    int option;

    while (1)
    {
        printf("Book manage system: 1) List 2)Price 3)Exit\n");
        scanf("%s", &input);
        fseek(stdin,0,SEEK_END);

        option = transfer_input(input);

        switch (option)
        {
            case 1:
                print_all_books_info(books);
                break;
            case 2:
                price_finder(books);
                break;
            case 3:
                return;
            default:
                printf("Invalid input\n");
        }
    }

    free(books);
}

Book* initialize_book()
{
    Book *books = malloc(BOOK_TYPES * sizeof(Book));
    books->name = "Happy Tree Friends";
    books->price = 100;
    books->type = Comic;

    (books + 1)->name = "Harry Potter";
    (books + 1)->price = 200;
    (books + 1)->type = Novel;

    (books + 2)->name = "Times";
    (books + 2)->price = 300;
    (books + 2)->type = Magazine;

    return books;
}

int transfer_input(char* target)
{
    int result = -1;

    if (isdigit(*target))
    {
        result = atoi(target);
    }

    return result;
}

void print_all_books_info(Book* books)
{
    for (int i = 0; i < BOOK_TYPES; ++i)
    {
        Book* current_book = books + i;
        switch ((books + i)->type)
        {
            case Comic:
                print_comic_info(current_book);
                break;
            case Novel:
                print_novel_info(current_book);
                break;
            case Magazine:
                print_magazine_info(current_book);
                break;
        }
    }
}

void print_comic_info(Book* comic)
{
    printf("Name: %-20s, Original Price: %-5d Type: Comic\n", comic->name, comic->price);
}

void print_novel_info(Book* novel)
{
    printf("Name: %-20s, Original Price: %-5d Type: Novel\n", novel->name, novel->price);
}

void print_magazine_info(Book* magazine)
{
    printf("Name: %-20s, Original Price: %-5d Type: Magazine\n", magazine->name, magazine->price);
}

void price_finder(Book* books)
{
    char name[100];
    printf("Enter the book's name(100 character limited): ");
    // in buffer overflow attack danger
    scanf("%s", &name);
    fseek(stdin,0,SEEK_END);

    for (int i = 0; i < BOOK_TYPES; ++i)
    {
        Book* current_book = books + i;
        int compare = strncmp(current_book->name, name, strlen(name));
        if (compare == 0)
        {
            switch (current_book->type)
            {
                case Comic:
                    print_comic_price(current_book);
                    break;
                case Novel:
                    print_novel_price(current_book);
                    break;
                case Magazine:
                    print_magazine_price(current_book);
                    break;
            }
            return;
        }
    }
    printf("Book \"%s\" not found\n", name);
}

void print_comic_price(Book* comic)
{
    printf("Name: %s, Sell: %.2lf\n", comic->name, comic->price * 0.9);
}

void print_novel_price(Book* novel)
{
     printf("Name: %s, Sell: %.2lf\n", novel->name, novel->price * 0.8);
}

void print_magazine_price(Book* magazine)
{
    printf("Name: %s, Sell: %.2lf\n", magazine->name, magazine->price * 0.7);
}
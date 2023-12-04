#ifndef PROYECTOFINAL_BOOKSLIST_H
#define PROYECTOFINAL_BOOKSLIST_H

#include <string>
#include "Book.h"

class BooksList {
private:
    Book *first;
    Book *last;

public:
    BooksList();

    void addBook(const Book &book);

    void displayBooks() const;

    Book *findBookByISBN(const std::string &isbn) const;

    bool removeBook(const std::string &isbn);
};


#endif

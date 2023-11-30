//
// Created by ldieg on 11/29/2023.
//

#include "BooksList.h"
#include "Book.h"

BooksList::BooksList() : first(nullptr), last(nullptr) {}

void BooksList::addBook(const Book &book) {
    Book *newBook = new Book(book);
    if (!first) {
        first = newBook;
        last = newBook;
    } else {
        last->setNext(newBook);
        newBook->setPrev(last);
        last = newBook;
        newBook->setNext(nullptr);
    }
}

void BooksList::displayBooks() const {
    Book *current = first;
    while (current != nullptr) {
        current->displayBookInfo();
        current = current->getNext();
    }
}

Book *BooksList::findBookByISBN(const std::string &isbn) const {
    Book *current = first;
    while (current != nullptr) {
        if (current->getISBN() == isbn) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

bool BooksList::removeBook(const std::string &isbn) {
    Book *current = first;
    Book *previous = nullptr;

    while (current != nullptr) {
        if (current->getISBN() == isbn) {
            if (previous == nullptr) {
                first = current->getNext();
                if (first) {
                    first->setPrev(nullptr);
                }
            } else {
                previous->setNext(current->getNext());
                if (current->getNext() != nullptr) {
                    current->getNext()->setPrev(previous);
                }
            }
            if (current == last) {
                last = previous;
            }
            delete current;
            return true;
        }
        previous = current;
        current = current->getNext();
    }
    return false;
}
#include <iostream>
#include "Book.h"

Book::Book(const std::string &title, int publicationYear, const std::string &editorial, const std::string &author,
           const std::string &ISBN, const std::string &category, const std::string &language, bool available)
        : title(title), publicationYear(publicationYear), editorial(editorial), author(author),
          ISBN(ISBN), category(category), language(language), available(available), next(nullptr), prev(nullptr) {}

std::string Book::getTitle() const {
    return title;
}

int Book::getPublicationYear() const {
    return publicationYear;
}

std::string Book::getEditorial() const {
    return editorial;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return ISBN;
}

std::string Book::getCategory() const {
    return category;
}

std::string Book::getLanguage() const {
    return language;
}

bool Book::isAvailable() const {
    return available;
}

void Book::setTitle(const std::string &newTitle) {
    title = newTitle;
}

void Book::setPublicationYear(int year) {
    publicationYear = year;
}

void Book::setEditorial(const std::string &newEditorial) {
    editorial = newEditorial;
}

void Book::setAuthor(const std::string &newAuthor) {
    author = newAuthor;
}

void Book::setISBN(const std::string &newISBN) {
    ISBN = newISBN;
}

void Book::setCategory(const std::string &newCategory) {
    category = newCategory;
}

void Book::setLoaned(bool loaned) {
    available = !loaned;
}

// Método para verificar si el libro está prestado
bool Book::isLoaned() const {
    return !available;
}

Book *Book::getNext() const {
    return next;
}

Book *Book::getPrev() const {
    return prev;
}

void Book::setNext(Book *book) {
    next = book;
}

void Book::setPrev(Book *book) {
    prev = book;
}

void Book::displayBookInfo() const {
    std::cout << "Información del libro:\n";
    std::cout << "Título: " << title << "\n";
    std::cout << "Año de publicación: " << publicationYear << "\n";
    std::cout << "Editorial: " << editorial << "\n";
    std::cout << "Autor: " << author << "\n";
    std::cout << "ISBN: " << ISBN << "\n";
    std::cout << "Categoría: " << category << "\n";
    std::cout << "Lenguaje: " << language << "\n";
    std::cout << "Disponible: " << (available ? "Yes" : "No") << "\n";
}
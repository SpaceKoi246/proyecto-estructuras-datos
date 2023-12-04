#ifndef PROYECTOFINAL_BOOK_H
#define PROYECTOFINAL_BOOK_H

#include <string>

class Book {
private:
    std::string title;
    int publicationYear{};
    std::string editorial;
    std::string author;
    std::string ISBN;
    std::string category;
    std::string language;
    bool available{};

    Book *next{};
    Book *prev{};

public:
    Book() = default;

    Book(const std::string &title, int publicationYear, const std::string &editorial, const std::string &author,
         const std::string &ISBN, const std::string &category, const std::string &language, bool available);

    // Getters
    std::string getTitle() const;

    int getPublicationYear() const;

    std::string getEditorial() const;

    std::string getAuthor() const;

    std::string getISBN() const;

    std::string getCategory() const;

    std::string getLanguage() const;

    bool isAvailable() const;

    // Setters
    void setTitle(const std::string &title);

    void setPublicationYear(int year);

    void setEditorial(const std::string &editorial);

    void setAuthor(const std::string &author);

    void setISBN(const std::string &ISBN);

    void setCategory(const std::string &category);

    void setLoaned(bool loaned);

    bool isLoaned() const;

    // Implementación de lista doble enlazada

    Book *getNext() const;

    Book *getPrev() const;

    void setNext(Book *book);

    void setPrev(Book *book);

    // Método para mostrar la información del libro
    void displayBookInfo() const;
};

#endif

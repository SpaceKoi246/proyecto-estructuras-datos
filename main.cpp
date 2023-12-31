#include <iostream>

using namespace std;

#include "User/User.h"
#include "User/UsersList.h"
#include "Book/Book.h"
#include "Book/BooksList.h"
#include "Loan/Loan.h"
#include "Loan/LoanTree.h"

UsersList userList;
BooksList bookList;
LoanTree loanTree;

void menu();

void showMenu();

void processOption(int option);

void addUser();

void findUserById();

void removeUserById();

void addBook();

void findBookByISBN();

void removeBookByISBN();

void viewLoans();

void loanBook();

void returnBook();

int main() {
    menu();
}

void menu() {
    int option;
    do {
        showMenu();
        cin >> option;
        processOption(option);
    } while (option != 0);
}

void showMenu() {
    cout << "Menú:" << endl
         << "1. Agregar usuario." << endl
         << "2. Mostrar usuarios." << endl
         << "3. Buscar usuarios." << endl
         << "4. Eliminar usuarios." << endl
         << "5. Agregar libro." << endl
         << "6. Mostrar libros." << endl
         << "7. Buscar libro por ISBN." << endl
         << "8. Eliminar libro por ISBN." << endl
         << "9. Realizar préstamo de libro." << endl
         << "10. Devolver libro." << endl
         << "11 . Mostrar préstamos."
         << "Ingrese la opción: ";
}

void processOption(int option) {
    switch (option) {
        case 1:
            addUser();
            break;
        case 2:
            userList.displayUsers();
            break;
        case 3:
            findUserById();
            break;
        case 4:
            removeUserById();
            break;
        case 5:
            addBook();
            break;
        case 6:
            bookList.displayBooks();
            break;
        case 7:
            findBookByISBN();
            break;
        case 8:
            removeBookByISBN();
            break;
        case 9:
            loanBook();
            break;
        case 10:
            returnBook();
            break;
        case 11:
            viewLoans();
            break;
        default:
            cout << "Opción inválida." << endl;
            break;
    }
}

void addUser() {
    string name, lastName, adddress, email, birthDate, gender, userId;
    cin.ignore();
    cout << "Por favor ingrese el nombre del usuario: ";
    getline(cin, name);
    cout << "Por favor ingrese el apellido del usuario: ";
    getline(cin, lastName);
    cout << "Por favor ingrese la dirección del usuario: ";
    getline(cin, adddress);
    cout << "Por favor ingrese el email del usuario: ";
    getline(cin, email);
    cout << "Por favor ingrese la fecha de nacimiento del usuario (formato DD/MM/AAAA): ";
    getline(cin, birthDate);
    cout << "Por favor ingrese el género del usuario: ";
    getline(cin, gender);
    cout << "Por favor ingrese el id del usuario: ";
    getline(cin, userId);
    User newUser(name, lastName, adddress, email, birthDate, gender, userId);
    userList.addUser(newUser);
    cout << "Usuario agregado exitosamente!" << endl;
}

void findUserById() {
    string userId;
    cout << "Por favor ingrese el id del usuario a buscar: ";
    cin >> userId;
    User *user = userList.findUserById(userId);
    if (user != nullptr) {
        user->displayUserInfo();
    } else {
        std::cout << "Usuario no encontrado." << std::endl;
    }
}

void removeUserById() {
    string userId;
    cout << "Por favor ingrese el id del usuario a eliminar: ";
    cin >> userId;
    User *user = userList.findUserById(userId);
    if (user != nullptr) {
        cout << "Usuario: " << user->getName() << " " << user->getLastName() << " eliminado.";
        userList.removeUser(userId);
    } else {
        std::cout << "Usuario no encontrado." << std::endl;
    }
}

void addBook() {
    string title, editorial, author, ISBN, category, language;
    int publicationYear;
    bool available;
    cin.ignore();
    cout << "Por favor ingrese el título del libro: ";
    getline(cin, title);
    cout << "Por favor ingrese el año de publicación del libro: ";
    cin >> publicationYear;
    cin.ignore();
    cout << "Por favor ingrese la editorial del libro: ";
    getline(cin, editorial);
    cout << "Por favor ingrese el nombre del autor del libro: ";
    getline(cin, author);
    cout << "Por favor ingrese el ISBN del libro: ";
    getline(cin, ISBN);
    cout << "Por favor ingrese la categoría del libro: ";
    getline(cin, category);
    cout << "Por favor ingrese el idioma del libro: ";
    getline(cin, language);
    cout << "Ingrese si el libro está disponible (1 para sí, 0 para no): ";
    cin >> available;
    Book newBook(title, publicationYear, editorial, author, ISBN, category, language, available);
    bookList.addBook(newBook);
    cout << "Libro agregado exitosamente!" << endl;
}

void findBookByISBN() {
    string isbn;
    cout << "Por favor ingrese el ISBN del libro a buscar: ";
    cin >> isbn;
    Book *book = bookList.findBookByISBN(isbn);
    if (book != nullptr) {
        book->displayBookInfo();
    } else {
        cout << "Libro no encontrado." << endl;
    }
}

void removeBookByISBN() {
    string isbn;
    cout << "Por favor ingrese el ISBN del libro a eliminar: ";
    cin >> isbn;
    if (bookList.removeBook(isbn)) {
        cout << "Libro eliminado exitosamente." << endl;
    } else {
        cout << "Libro no encontrado." << endl;
    }
}

void loanBook() {
    std::string isbn, userId, loanDate, returnDate;
    std::cout << "Ingrese el ISBN del libro a prestar: ";
    std::cin >> isbn;
    std::cout << "Ingrese el ID del usuario: ";
    std::cin >> userId;
    std::cout << "Ingrese la fecha de préstamo (formato DD/MM/AAAA): ";
    std::cin >> loanDate;
    std::cout << "Ingrese la fecha de devolución (formato DD/MM/AAAA): ";
    std::cin >> returnDate;

    Book *book = bookList.findBookByISBN(isbn);
    User *user = userList.findUserById(userId);

    if (book != nullptr && user != nullptr) {
        if (!book->isLoaned()) {
            book->setLoaned(true);
            Loan loan(*book, *user, loanDate, returnDate);
            loanTree.addLoan(loan);
            std::cout << "Préstamo realizado con éxito." << std::endl;
        } else {
            std::cout << "El libro ya está prestado." << std::endl;
        }
    } else {
        std::cout << "Libro o usuario no encontrado." << std::endl;
    }
}

void returnBook() {
    string isbn;
    cout << "Ingrese el ISBN del libro a devolver: ";
    cin >> isbn;

    Loan loan = loanTree.findLoanByISBN(isbn);
    if (loan.getBook().getISBN() != "") {
        Book* book = bookList.findBookByISBN(isbn);
        if (book != nullptr) {
            book->setLoaned(false);
            loanTree.removeLoan(isbn);
            cout << "Libro devuelto con éxito." << endl;
        } else {
            cout << "Libro no encontrado." << endl;
        }
    } else {
        cout << "Préstamo no encontrado." << endl;
    }
}

void viewLoans() {
    std::cout << "Lista de todos los préstamos:" << std::endl;
    loanTree.displayAllLoans();
}


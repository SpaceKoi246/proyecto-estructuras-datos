#include <iostream>

using namespace std;

#include "User/User.h"
#include "User/UsersList.h"
#include "Book/Book.h"
#include "Book/BooksList.h"

UsersList userList;
BooksList bookList;

void menu();

void showMenu();

void processOption(int option);

void addUser();

void findUserById();

void removeUserById();

void addBook();

void findBookByISBN();

void removeBookByISBN();

int main() {
    userList.addUser(User("Alice", "Smith", "123 Main St", "alice@example.com", "01/01/1990", "Femenino", "001"));
    userList.addUser(User("Bob", "Johnson", "456 Elm St", "bob@example.com", "02/02/1991", "Masculino", "002"));
    bookList.addBook(Book("El Señor de los Anillos", 1954, "George Allen & Unwin", "J.R.R. Tolkien", "9780544003415", "Fantasía", "Inglés", true));
    bookList.addBook(Book("Cien Años de Soledad", 1967, "Editorial Sudamericana", "Gabriel García Márquez", "9780307474728", "Realismo mágico", "Español", true));
    bookList.addBook(Book("1984", 1949, "Secker & Warburg", "George Orwell", "9780451524935", "Distopía", "Inglés", false));
    bookList.addBook(Book("To Kill a Mockingbird", 1960, "J.B. Lippincott & Co.", "Harper Lee", "9780061120084", "Ficción histórica", "Inglés", true));
    bookList.addBook(Book("Don Quijote de la Mancha", 1605, "Francisco de Robles", "Miguel de Cervantes", "9788423349647", "Novela", "Español", false));
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
    cout << "Por favor ingrese la fecha de nacimiento del usuario: ";
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
#include <iostream>
#include "Loan.h"

Loan::Loan(Book book, User user, std::string loanDate, std::string returnDate)
        : book(book), user(user), loanDate(loanDate), returnDate(returnDate) {}


Book &Loan::getBook() {
    return book;
}

User Loan::getUser() const {
    return user;
}

std::string Loan::getLoanDate() const {
    return loanDate;
}

std::string Loan::getReturnDate() const {
    return returnDate;
}

void Loan::displayLoanDetails() const {
    std::cout << "ID de Usuario: " << user.getUserId() << ", ";
    std::cout << "Nombre de Usuario: " << user.getName() << ", ";
    std::cout << "ISBN del Libro: " << book.getISBN() << ", ";
    std::cout << "Título del Libro: " << book.getTitle() << ", ";
    std::cout << "Fecha de Préstamo: " << loanDate << ", ";
    std::cout << "Fecha de Devolución: " << returnDate << std::endl;
}

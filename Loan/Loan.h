#ifndef PROYECTOFINAL_LOAN_H
#define PROYECTOFINAL_LOAN_H


#include <string>
#include "../User/User.h"
#include "../Book/Book.h"

class Loan {
private:
    Book book;
    User user;
    std::string loanDate;
    std::string returnDate;

public:
    Loan() = default;

    Loan(Book book, User user, std::string loanDate, std::string returnDate);

    Book &getBook();

    User getUser() const;

    std::string getLoanDate() const;

    std::string getReturnDate() const;

    void displayLoanDetails() const;
};

#endif

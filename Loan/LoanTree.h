#ifndef PROYECTOFINAL_LOANTREE_H
#define PROYECTOFINAL_LOANTREE_H

#include <string>
#include "Loan.h"

class LoanNode {
public:
    Loan data;
    LoanNode* left;
    LoanNode* right;

    LoanNode(Loan data) : data(data), left(nullptr), right(nullptr) {}
};

class LoanTree {
private:
    LoanNode* root;

    void insert(LoanNode*& node, Loan loan);
    LoanNode* find(LoanNode* node, std::string isbn) const;
    void remove(LoanNode*& node, std::string isbn);
    LoanNode* minValueNode(LoanNode* node) const;
    void clear(LoanNode* node);
    void displayAllLoans(LoanNode* node) const;

public:
    LoanTree();
    ~LoanTree();
    void addLoan(Loan loan);
    Loan findLoanByISBN(std::string isbn) const;
    void removeLoan(std::string isbn);
    void displayAllLoans() const;
};

#endif

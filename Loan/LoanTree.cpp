#include "LoanTree.h"
#include "../Book/Book.h"

LoanTree::LoanTree() : root(nullptr) {}

LoanTree::~LoanTree() {
    clear(root);
}

void LoanTree::addLoan(Loan loan) {
    loan.getBook().setLoaned(true);
    insert(root, loan);
}

Loan LoanTree::findLoanByISBN(std::string isbn) const {
    LoanNode *node = find(root, isbn);
    return node ? node->data : Loan();
}

void LoanTree::removeLoan(std::string isbn) {
    remove(root, isbn);
}

void LoanTree::insert(LoanNode *&node, Loan loan) {
    if (node == nullptr) {
        node = new LoanNode(loan);
    } else if (loan.getBook().getISBN() < node->data.getBook().getISBN()) {
        insert(node->left, loan);
    } else {
        insert(node->right, loan);
    }
}

LoanNode *LoanTree::find(LoanNode *node, std::string isbn) const {
    if (node == nullptr || node->data.getBook().getISBN() == isbn) {
        return node;
    } else if (isbn < node->data.getBook().getISBN()) {
        return find(node->left, isbn);
    } else {
        return find(node->right, isbn);
    }
}

void LoanTree::remove(LoanNode*& node, std::string isbn) {
    if (node == nullptr) {
        return;
    }
    if (isbn < node->data.getBook().getISBN()) {
        remove(node->left, isbn);
    } else if (isbn > node->data.getBook().getISBN()) {
        remove(node->right, isbn);
    } else {
        node->data.getBook().setLoaned(false);
        if (node->left == nullptr || node->right == nullptr) {
            LoanNode* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            LoanNode* temp = minValueNode(node->right);
            node->data = temp->data;
            remove(node->right, temp->data.getBook().getISBN());
        }
    }
}

LoanNode *LoanTree::minValueNode(LoanNode *node) const {
    LoanNode *current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

void LoanTree::clear(LoanNode *node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void LoanTree::displayAllLoans() const {
    if (root != nullptr) {
        displayAllLoans(root);
    }
}

void LoanTree::displayAllLoans(LoanNode *node) const {
    if (node != nullptr) {
        displayAllLoans(node->left);
        node->data.displayLoanDetails();
        displayAllLoans(node->right);
    }
}
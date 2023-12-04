#include "LoanTree.h"
#include "../Book/Book.h" // Asegúrate de incluir la clase Book

// Constructor
LoanTree::LoanTree() : root(nullptr) {}

// Destructor
LoanTree::~LoanTree() {
    clear(root);
}

// Método para insertar un nuevo préstamo
void LoanTree::addLoan(Loan loan) {
    // Cambiar el estado del libro a prestado
    loan.getBook().setLoaned(true);
    insert(root, loan);
}

// Método para buscar un préstamo por el ISBN del libro
Loan LoanTree::findLoanByISBN(std::string isbn) const {
    LoanNode *node = find(root, isbn);
    return node ? node->data : Loan(); // Retorna un préstamo vacío si no se encuentra
}

// Método para eliminar un préstamo
void LoanTree::removeLoan(std::string isbn) {
    remove(root, isbn);
    // Aquí podrías cambiar el estado del libro a no prestado, si tienes acceso al libro
}

// Implementación del método insert
void LoanTree::insert(LoanNode *&node, Loan loan) {
    if (node == nullptr) {
        node = new LoanNode(loan);
    } else if (loan.getBook().getISBN() < node->data.getBook().getISBN()) {
        insert(node->left, loan);
    } else {
        insert(node->right, loan);
    }
}

// Implementación del método find
LoanNode *LoanTree::find(LoanNode *node, std::string isbn) const {
    if (node == nullptr || node->data.getBook().getISBN() == isbn) {
        return node;
    } else if (isbn < node->data.getBook().getISBN()) {
        return find(node->left, isbn);
    } else {
        return find(node->right, isbn);
    }
}

// Implementación del método remove
void LoanTree::remove(LoanNode *&node, std::string isbn) {
    if (node == nullptr) {
        return; // Elemento no encontrado, retorno
    }

    if (isbn < node->data.getBook().getISBN()) {
        remove(node->left, isbn); // Buscar en el subárbol izquierdo
    } else if (isbn > node->data.getBook().getISBN()) {
        remove(node->right, isbn); // Buscar en el subárbol derecho
    } else {
        // Nodo con un solo hijo o sin hijos
        if (node->left == nullptr || node->right == nullptr) {
            LoanNode *temp = node->left ? node->left : node->right;

            if (temp == nullptr) { // No tiene hijos
                temp = node;
                node = nullptr;
            } else { // Un hijo
                *node = *temp; // Copiar los contenidos del hijo
            }

            delete temp;

            // Cambiar el estado del libro a no prestado
            // Esto asume que tienes acceso al objeto Book aquí
            if (node != nullptr) {
                node->data.getBook().setLoaned(false);
            }
        } else {
            // Nodo con dos hijos: obtener el sucesor inorden (mínimo en el subárbol derecho)
            LoanNode *temp = minValueNode(node->right);

            // Copiar los datos del sucesor inorden al nodo actual
            node->data = temp->data;

            // Eliminar el sucesor inorden
            remove(node->right, temp->data.getBook().getISBN());
        }
    }
}

// Implementación del método minValueNode
LoanNode* LoanTree::minValueNode(LoanNode* node) const {
    LoanNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Implementación del método clear
void LoanTree::clear(LoanNode* node) {
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

void LoanTree::displayAllLoans(LoanNode* node) const {
    if (node != nullptr) {
        displayAllLoans(node->left);
        node->data.displayLoanDetails();
        displayAllLoans(node->right);
    }
}
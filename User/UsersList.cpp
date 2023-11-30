//
// Created by ldieg on 11/29/2023.
//

#include "UsersList.h"

UsersList::UsersList() : first(nullptr), last(nullptr) {}

void UsersList::addUser(const User &user) {
    User *newUser = new User(user);
    if (!first) {
        first = newUser;
        last = newUser;
    } else {
        last->setNext(newUser);
        newUser->setPrev(last);
        last = newUser;
        newUser->setNext(nullptr);
    }
}

void UsersList::displayUsers() const {
    User *current = first;
    while (current != nullptr) {
        current->displayUserInfo();
        current = current->getNext();
    }
}

User *UsersList::findUserById(const std::string &userId) const {
    User *current = first;
    while (current != nullptr) {
        if (current->getUserId() == userId) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

bool UsersList::removeUser(const std::string &userId) {
    User *current = first;
    User *previous = nullptr;

    while (current != nullptr) {
        if (current->getUserId() == userId) {
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
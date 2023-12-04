#ifndef PROYECTOFINAL_USERSLIST_H
#define PROYECTOFINAL_USERSLIST_H

#include "User.h"

class UsersList {
private:
    User *first;
    User *last;

public:
    UsersList();

    void addUser(const User &user);

    void displayUsers() const;

    User *findUserById(const std::string &userId) const;

    bool removeUser(const std::string &userId);
};

#endif

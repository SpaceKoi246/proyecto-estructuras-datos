#ifndef PROYECTOFINAL_USER_H
#define PROYECTOFINAL_USER_H


#include <string>

class User {
private:
    // Atributos
    std::string name;
    std::string lastName;
    std::string address;
    std::string email;
    std::string birthDate;
    std::string gender;
    std::string userId;

    User *next;
    User *prev;

public:
    // Constructor
    User() = default;

    User(const std::string& name, const std::string& lastName, const std::string& address, const std::string& email, const std::string& birthDate, const std::string& gender, const std::string& userId);

    // Getters
    std::string getName() const;

    std::string getLastName() const;

    std::string getAddress() const;

    std::string getEmail() const;

    std::string getBirthDate() const;

    std::string getGender() const;

    std::string getUserId() const;

    // Setters
    void setName(const std::string &newName);

    void setLastName(const std::string &newLastName);

    void setAddress(const std::string &newAddress);

    void setEmail(const std::string &newEmail);

    void setBirthDate(const std::string &newBirthDate);

    void setGender(const std::string &newGender);

    void setUserId(const std::string &newUserId);

    // Implementación de lista doble enlazada
    User *getNext() const;

    User *getPrev() const;

    void setNext(User *user);

    void setPrev(User *user);

    // Método para mostrar la información del usuario
    void displayUserInfo() const;
};


#endif

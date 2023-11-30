//
// Created by ldieg on 11/29/2023.
//

#include <iostream>
#include "User.h"

using namespace std;

User::User(const std::string& name, const std::string& lastName, const std::string& address, const std::string& email, const std::string& birthDate, const std::string& gender, const std::string& userId)
        : name(name), lastName(lastName), address(address), email(email), birthDate(birthDate), gender(gender), userId(userId), next(
        nullptr), prev(nullptr) {}

std::string User::getName() const {
    return name;
}

std::string User::getLastName() const {
    return lastName;
}

std::string User::getAddress() const {
    return address;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getBirthDate() const {
    return birthDate;
}

std::string User::getGender() const {
    return gender;
}

std::string User::getUserId() const {
    return userId;
}

void User::setName(const std::string &newName) {
    name = newName;
}

void User::setLastName(const std::string &newLastName) {
    lastName = newLastName;
}

void User::setAddress(const std::string &newAddress) {
    address = newAddress;
}

void User::setEmail(const std::string &newEmail) {
    email = newEmail;
}

void User::setBirthDate(const std::string &newBirthDate) {
    birthDate = newBirthDate;
}

void User::setGender(const std::string &newGender) {
    gender = newGender;
}

void User::setUserId(const std::string &newUserId) {
    userId = newUserId;
}

User *User::getNext() const {
    return next;
}

User *User::getPrev() const {
    return prev;
}

void User::setNext(User *user) {
    next = user;
}

void User::setPrev(User *user) {
    prev = user;
}

void User::displayUserInfo() const {
    std::cout << "Información de usuario:\n";
    std::cout << "Nombre: " << name << " " << lastName << "\n";
    std::cout << "Dirección: " << address << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Ano de nacimiento: " << birthDate << "\n";
    std::cout << "Genero: " << gender << "\n";
    std::cout << "ID: " << userId << "\n";
}

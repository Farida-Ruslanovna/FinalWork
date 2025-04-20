#include "User.h"

// Определение конструктора класса User
User::User(const std::string& login, const std::string& password, const std::string& name)
    : login(login), password(password), name(name) {
}

// Определение метода для получения логина
std::string User::getLogin() const {
    return login;
}

// Определение метода для получения пароля
std::string User::getPassword() const {
    return password;
}

// Определение метода для получения имени
std::string User::getName() const {
    return name;
}
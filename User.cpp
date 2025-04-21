#include "User.h"

// ќпределение конструктора класса User
User::User(const std::string& login, const std::string& password, const std::string& name)
    : login(login), password(password), name(name) {
}

// ќпределение метода дл¤ получени¤ логина
std::string User::getLogin() const {
    return login;
}

// ќпределение метода дл¤ получени¤ парол¤
std::string User::getPassword() const {
    return password;
}

// ќпределение метода дл¤ получени¤ имени
std::string User::getName() const {
    return name;
}
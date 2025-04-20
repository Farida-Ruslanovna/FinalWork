#pragma once
#include <string>

// Класс пользователя
class User {
public:
    // Конструктор
    User(const std::string& login, const std::string& password, const std::string& name);

    // Методы для получения данных пользователя
    std::string getLogin() const;
    std::string getPassword() const;
    std::string getName() const;

private:
    std::string login;    // Логин пользователя
    std::string password; // Пароль пользователя
    std::string name;     // Имя пользователя
};
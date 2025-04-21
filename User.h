#pragma once
#include <string> // библиотека для работы со строками

// Класс пользователя
class User {
public:
    // Конструктор класса, принимающий логин, пароль и имя
    User(const std::string& login, 
	     const std::string& password, 
		 const std::string& name);

    // Методы для получения данных пользователя
    std::string getLogin() const;
    std::string getPassword() const;
    std::string getName() const;

private:
    // Хранение данных
    std::string login;    // Логин пользователя
    std::string password; // Пароль пользователя
    std::string name;     // Имя пользователя
};
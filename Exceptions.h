#pragma once
#include <exception> // стандартная библиотека для обработки исключений

// Исключение для уже существующего пользователя
class UserAlreadyExistsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Пользователь уже существует.";
    }
};

// Исключение для неверного логина или пароля
class InvalidCredentialsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Неверный логин или пароль.";
    }
};

// Исключение для отсутствия пользователя в системе
class UserNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Получатель не найден.";
    }
};

// Исключение для необходимости входа в систему
class NotLoggedInException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Для отправки сообщений Вы должны войти в систему.";
    }
};
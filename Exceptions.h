#include <exception> // библиотека для работы с исключениями
#include <string> // библиотека для работы со строками

// Исключение для уже существующего пользователя
class UserAlreadyExistsException : public std::exception {
public:
    UserAlreadyExistsException(const std::string& message) 
        : message(message) {} 

    const char* what() const noexcept override {
        return message.c_str(); // Возвращаем указатель на C-строку
    }

private:
    std::string message; // Хранение сообщения об ошибке
};

// Исключение для неверных учетных данных
class InvalidCredentialsException : public std::exception {
public:
    InvalidCredentialsException(const std::string& message) 
        : message(message) {}

    const char* what() const noexcept override {
        return message.c_str(); // Возвращаем указатель на C-строку
    }

private:
    std::string message; // Хранение сообщения об ошибке
};

// Исключение для отсутствия пользователя в системе
class UserNotFoundException : public std::exception {
public:
    UserNotFoundException(const std::string& message) 
        : message(message) {} 

    const char* what() const noexcept override {
        return message.c_str(); // Возвращаем указатель на C-строку
    }

private:
    std::string message; // Хранение сообщения об ошибке
};

// Исключение для необходимости входа в систему
class NotLoggedInException : public std::exception {
public:
    NotLoggedInException(const std::string& message) 
        : message(message) {} 

    const char* what() const noexcept override {
        return message.c_str(); // Возвращаем указатель на C-строку
    }

private:
    std::string message; // Хранение сообщения об ошибке
};
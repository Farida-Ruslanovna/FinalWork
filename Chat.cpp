#include "Chat.h"
#include "Exceptions.h"

// Метод для регистрации нового пользователя
void Chat::registerUser(const std::string& login, const std::string& password, const std::string& name) {
    for (const auto& user : users) {
        if (user.getLogin() == login) {
            throw UserAlreadyExistsException(); // Генерация исключения, если пользователь уже существует
        }
    }
    users.emplace_back(login, password, name);
    std::cout << "Пользователь успешно зарегистрировался.\n";
}

// Метод для входа пользователя в систему
void Chat::loginUser(const std::string& login, const std::string& password) {
    for (const auto& user : users) {
        if (user.getLogin() == login) {
            if (user.getPassword() == password) {
                currentUser = login;
                std::cout << "Вошел в систему как " << user.getName() << "\n";
                return;
            }
            else {
                throw InvalidCredentialsException(); // Генерация исключения, если пароль неверный
            }
        }
    }
    throw InvalidCredentialsException(); // Генерация исключения, если пользователь не найден
}

// Метод для отправки сообщения пользователю
void Chat::sendMessage(const std::string& recipient, const std::string& message) {
    if (currentUser.empty()) {
        throw NotLoggedInException(); // Генерация исключения, если пользователь не вошел
    }

    bool recipientExists = false;
    for (const auto& user : users) {
        if (user.getLogin() == recipient) {
            recipientExists = true;
            break;
        }
    }

    if (!recipientExists) {
        throw UserNotFoundException(); // Генерация исключения, если получатель не найден
    }

    messages.push_back(currentUser + " to " + recipient + ": " + message);
    std::cout << "Сообщение, отправленное на " << recipient << ".\n";
}

// Метод для отображения всех сообщений
void Chat::showMessages() const {
    if (messages.empty()) {
        std::cout << "Сообщений пока нет \n";
        return;
    }

    for (const auto& msg : messages) {
        std::cout << msg << "\n";
    }
}
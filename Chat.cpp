#include "Chat.h" // Подключение заголовочного файла Chat.h
#include "Exceptions.h" // Подключение заголовочного файла исключений
#include <iostream> // Для вывода в консоль

// Проверка существования пользователя
bool Chat::isUserExists(const std::string& login) const {
    for (const auto& user : users) {
        if (user.getLogin() == login) {
            return true; // Пользователь найден
        }
    }
    return false; // Пользователь не найден
}

// Метод для регистрации нового пользователя
void Chat::registerUser(const std::string& login, const std::string& password, const std::string& name) {
    // Проверка на пустой логин
    if (login.empty()) {
        throw InvalidCredentialsException("Логин не может быть пустым.");
    }
    // Проверка на пустой пароль
    if (password.empty()) {
        throw InvalidCredentialsException("Пароль не может быть пустым.");
    }

    // Проверка, существует ли уже пользователь с таким логином   
    if (isUserExists(login)) {
        throw UserAlreadyExistsException("Пользователь с таким логином уже существует.");
    }

    // Добавление нового пользователя в вектор
    users.emplace_back(login, password, name);
    std::cout << "Пользователь успешно зарегистрировался.\n";
}

// Метод для входа пользователя в систему
void Chat::loginUser(const std::string& login, const std::string& password) {
    // Проверка на пустой логин
    if (login.empty()) {
        throw InvalidCredentialsException("Логин не может быть пустым.");
    }
    // Проверка на пустой пароль
    if (password.empty()) {
        throw InvalidCredentialsException("Пароль не может быть пустым.");
    }

    // Проверка, существует ли пользователь и правильный ли пароль
    for (const auto& user : users) {
        if (user.getLogin() == login) {
            if (user.getPassword() == password) {
                currentUser = login; // Установка текущего пользователя
                std::cout << "Вошел в систему как " << user.getName() << "\n";
                return;
            } else {
                throw InvalidCredentialsException("Неверный пароль.");
            }
        }
    }
    throw UserNotFoundException("Пользователь не найден.");
}

// Метод для выхода пользователя из системы
void Chat::logoutUser() {
    if (currentUser.empty()) {
        throw NotLoggedInException("Пользователь не вошел в систему.");
    }
    currentUser.clear(); // Очистка текущего пользователя
    std::cout << "Вы вышли из системы.\n";
}

// Метод для отправки сообщения пользователю
void Chat::sendMessage(const std::string& recipient, const std::string& message) {
    // Проверка, что пользователь вошел в систему
    if (currentUser.empty()) {
        throw NotLoggedInException("Необходимо войти в систему для отправки сообщения.");
    }

    // Проверка на пустое сообщение
    if (message.empty()) {
        throw InvalidCredentialsException("Сообщение не может быть пустым.");
    }

    // Проверка длины сообщения
    const size_t maxMessageLength = 500; // Максимальная длина сообщения
    if (message.length() > maxMessageLength) {
        throw InvalidCredentialsException("Сообщение не может превышать 500 символов.");
    }

    // Проверка, существует ли получатель
    if (!isUserExists(recipient)) {
        throw UserNotFoundException("Получатель не найден.");
    }

    // Добавление сообщения в вектор сообщений
    messages.push_back(currentUser + " to " + recipient + ": " + message);
    std::cout << "Сообщение, отправленное на " << recipient << ".\n";
}

// Метод для отображения всех сообщений
void Chat::showMessages() const {
    // Проверка, есть ли сообщения
    if (messages.empty()) {
        std::cout << "Сообщений пока нет.\n";
        return;
    }
    // Вывод всех сообщений
    for (const auto& msg : messages) {
        std::cout << msg << "\n"; // Вывод сообщения
    }
}
#include "Chat.h" // Подключение заголовочного файла Chat.h
#include "Exceptions.h"

// Метод для регистрации нового пользователя
void Chat::registerUser(const std::string& login, const std::string& password, const std::string& name) {
   // Проверка, существует ли уже пользователь с таким логином   
   for (const auto& user : users) {
        if (user.getLogin() == login) {
            throw UserAlreadyExistsException(); // Генерация исключения, если пользователь уже существует
        }
    }
	// Добавление нового пользователя в вектор
    users.emplace_back(login, password, name);
    std::cout << "Пользователь успешно зарегистрировался.\n";
}

// Метод для входа пользователя в систему
void Chat::loginUser(const std::string& login, const std::string& password) {
     // Проверка, существует ли пользователь и правильный ли пароль
	for (const auto& user : users) {
        if (user.getLogin() == login) {
            if (user.getPassword() == password) {
                currentUser = login; // Установка текущего пользователя
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
     // Проверка, что пользователь вошел в систему
	if (currentUser.empty()) {
        throw NotLoggedInException(); // Генерация исключения, если пользователь не вошел
    }
   // Проверка, существует ли получатель
    bool recipientExists = false;
    for (const auto& user : users) {
        if (user.getLogin() == recipient) {
            recipientExists = true; // Установить флаг, если получатель найден
            break;
        }
    }

    if (!recipientExists) {
        throw UserNotFoundException(); // Генерация исключения, если получатель не найден
    }
// Добавление сообщения в вектор сообщений
    messages.push_back(currentUser + " to " + recipient + ": " + message);
    std::cout << "Сообщение, отправленное на " << recipient << ".\n"; 
}

// Метод для отображения всех сообщений
void Chat::showMessages() const {
	 // Проверка, есть ли сообщения
	 if (messages.empty()) {
        std::cout << "Сообщений пока нет \n"; // Уведомление о том, что сообщений нет
        return;
    }
    // Вывод всех сообщений
    for (const auto& msg : messages) {
        std::cout << msg << "\n";// Вывод сообщения
    }
}
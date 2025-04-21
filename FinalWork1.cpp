#include <iostream>
#include <string>
#include "Chat.h"
#include "Exceptions.h"

bool isValidInput(const std::string& input) {
    // Проверка на допустимые символы и длину
    return !input.empty() && input.length() <= 100; // максимум 100 символов
}

int main() {
    setlocale(LC_ALL, "Russian");
    Chat chat;
    std::string command;

    while (true) {
        std::cout << "Введите команду (register, login, send, show, exit): ";
        std::cin >> command;

        try {
            if (command == "register") {
                std::string login, password, name;
                std::cout << "Введите логин: ";
                std::cin >> login;
                if (!isValidInput(login)) {
                    std::cout << "Некорректный логин.\n";
                    continue;
                }
                std::cout << "Введите пароль: ";
                std::cin >> password;
                if (!isValidInput(password)) {
                    std::cout << "Некорректный пароль.\n";
                    continue;
                }
                std::cout << "Введите имя: ";
                std::cin >> name;
                if (!isValidInput(name)) {
                    std::cout << "Некорректное имя.\n";
                    continue;
                }
                chat.registerUser(login, password, name);
            }
            else if (command == "login") {
                std::string login, password;
                std::cout << "Введите логин: ";
                std::cin >> login;
                if (!isValidInput(login)) {
                    std::cout << "Некорректный логин.\n";
                    continue;
                }
                std::cout << "Введите пароль: ";
                std::cin >> password;
                if (!isValidInput(password)) {
                    std::cout << "Некорректный пароль.\n";
                    continue;
                }
                chat.loginUser(login, password);
            }
            else if (command == "send") {
                std::string recipient, message;
                std::cout << "Введите получателя: ";
                std::cin >> recipient;
                if (!isValidInput(recipient)) {
                    std::cout << "Некорректный логин получателя.\n";
                    continue;
                }
                std::cout << "Введите сообщение: ";
                std::cin.ignore(); // Игнорируем символ новой строки
                std::getline(std::cin, message);
                chat.sendMessage(recipient, message);
            }
            else if (command == "show") {
                chat.showMessages();
            }
            else if (command == "exit") {
                break;
            }
            else {
                std::cout << "Неизвестная команда.\n";
            }
        }
        catch (const UserAlreadyExistsException& e) {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
        catch (const InvalidCredentialsException& e) {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
        catch (const UserNotFoundException& e) {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
        catch (const NotLoggedInException& e) {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
    }

    return 0;
}
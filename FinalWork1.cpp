// FinalWork1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include "Chat.h"
#include "Exceptions.h"

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
                std::cout << "Введите пароль: ";
                std::cin >> password;
                std::cout << "Введите имя: ";
                std::cin >> name;
                chat.registerUser(login, password, name);
            }
            else if (command == "login") {
                std::string login, password;
                std::cout << "Введите логин: ";
                std::cin >> login;
                std::cout << "Введите пароль: ";
                std::cin >> password;
                chat.loginUser(login, password);
            }
            else if (command == "send") {
                std::string recipient, message;
                std::cout << "Введите получателя: ";
                std::cin >> recipient;
                std::cout << "Введите сообщение: ";
                std::cin.ignore();
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
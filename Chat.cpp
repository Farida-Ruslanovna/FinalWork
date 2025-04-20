#include "Chat.h"
#include "Exceptions.h"

// ����� ��� ����������� ������ ������������
void Chat::registerUser(const std::string& login, const std::string& password, const std::string& name) {
    for (const auto& user : users) {
        if (user.getLogin() == login) {
            throw UserAlreadyExistsException(); // ��������� ����������, ���� ������������ ��� ����������
        }
    }
    users.emplace_back(login, password, name);
    std::cout << "������������ ������� �����������������.\n";
}

// ����� ��� ����� ������������ � �������
void Chat::loginUser(const std::string& login, const std::string& password) {
    for (const auto& user : users) {
        if (user.getLogin() == login) {
            if (user.getPassword() == password) {
                currentUser = login;
                std::cout << "����� � ������� ��� " << user.getName() << "\n";
                return;
            }
            else {
                throw InvalidCredentialsException(); // ��������� ����������, ���� ������ ��������
            }
        }
    }
    throw InvalidCredentialsException(); // ��������� ����������, ���� ������������ �� ������
}

// ����� ��� �������� ��������� ������������
void Chat::sendMessage(const std::string& recipient, const std::string& message) {
    if (currentUser.empty()) {
        throw NotLoggedInException(); // ��������� ����������, ���� ������������ �� �����
    }

    bool recipientExists = false;
    for (const auto& user : users) {
        if (user.getLogin() == recipient) {
            recipientExists = true;
            break;
        }
    }

    if (!recipientExists) {
        throw UserNotFoundException(); // ��������� ����������, ���� ���������� �� ������
    }

    messages.push_back(currentUser + " to " + recipient + ": " + message);
    std::cout << "���������, ������������ �� " << recipient << ".\n";
}

// ����� ��� ����������� ���� ���������
void Chat::showMessages() const {
    if (messages.empty()) {
        std::cout << "��������� ���� ��� \n";
        return;
    }

    for (const auto& msg : messages) {
        std::cout << msg << "\n";
    }
}
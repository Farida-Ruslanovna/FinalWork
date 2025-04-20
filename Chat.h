#pragma once
#include "User.h"
#include <vector>
#include <string>
#include <iostream>

// ����� ����
class Chat {
public:
    // ����� ��� ����������� ������ ������������
    void registerUser(const std::string& login, const std::string& password, const std::string& name);

    // ����� ��� ����� ������������ � �������
    void loginUser(const std::string& login, const std::string& password);

    // ����� ��� �������� ��������� ������������
    void sendMessage(const std::string& recipient, const std::string& message);

    // ����� ��� ����������� ���� ���������
    void showMessages() const;

private:
    std::vector<User> users; // ������ ��� �������� �������������
    std::vector<std::string> messages; // ������ ��� �������� ���������
    std::string currentUser; // ����� �������� ������������
};
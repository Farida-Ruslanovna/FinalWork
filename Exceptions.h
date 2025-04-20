#pragma once
#include <exception>

// ���������� ��� ��� ������������� ������������
class UserAlreadyExistsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "������������ ��� ����������.";
    }
};

// ���������� ��� ��������� ������ ��� ������
class InvalidCredentialsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "�������� ����� ��� ������.";
    }
};

// ���������� ��� ���������� ������������ � �������
class UserNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "���������� �� ������.";
    }
};

// ���������� ��� ������������� ����� � �������
class NotLoggedInException : public std::exception {
public:
    const char* what() const noexcept override {
        return "��� �������� ��������� �� ������ ����� � �������.";
    }
};
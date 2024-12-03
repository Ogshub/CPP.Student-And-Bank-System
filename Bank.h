#pragma once

#include <iostream>
#include <string>

class Bank {
    std::string m_name{};
    int m_accNum{};
    double m_balance{};

public:
    Bank(const std::string& name, int acc, double bal)
        : m_name{ name }, m_accNum{ acc }, m_balance{ bal } {
    }

    void deposit();

    void withdraw();

    void print();
};
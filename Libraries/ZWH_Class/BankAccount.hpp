#pragma once
#include <string>


class BankAccount
{
public:
    BankAccount(std::string name, double amount);//Constructor!
    void deposit(double depositAmount);
    void withdraw(double withdrawAmount);
    void transfer(double transferAmount, BankAccount& recipient);
private:
    std::string name;
    double amount;
};

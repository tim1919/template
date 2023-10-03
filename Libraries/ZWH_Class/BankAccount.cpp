#include <BankAccount.hpp>
#include <iostream>
//#include <error>

void bankDemoClasses(void)
{
    BankAccount nick("Nick", 100);//注意这里的Constructor的用法，用括号!
    BankAccount kylie("Kylie", 1000);

    nick.deposit(500);

    nick.transfer(20, kylie);
}

BankAccount::BankAccount(std::string name, double amount)//Constructor!
{
    this->name = name;//注意this指针!一般当名字冲突的时候用
    this->amount = amount;
}
void BankAccount::deposit(double depositAmount)
{
    if (depositAmount < 0)
    {
        std::cout << "error!Can't have negative money!\n" << std::endl;
    }
}
void BankAccount::withdraw(double withdrawAmount)
{
    if (withdrawAmount < 0)
    {
        std::cout << "error!Can't have negative money!\n" << std::endl;
    }
}
void BankAccount::transfer(double transferAmount, BankAccount& recipient)
{
    withdraw(transferAmount);
    //或者this->withdraw(transferAmount);
    recipient.deposit(transferAmount);
}

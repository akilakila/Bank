#include <iostream>
#include <iomanip>
#include <string>
#include "account.h"

using namespace std;

Account::Account()
{
    balance = 0;
}

Account::Account(string na, int num, int pass, double amount)
{
    name = na;
    accnum = num;
    pin = pass;
    balance = amount;
}

void Account::setName(string na)
{
    name = na;
}

string Account::getName()
{
    return name;
}

void Account::setAccountNum(int num)
{
    accnum = num;
}

int Account::getAccountNum()
{
    return accnum;
}

double Account::getBalance()
{
    return balance;
}

void Account::setPin(int pass)
{
    pin = pass;
}

bool Account::checkPin(int pass)
{
    if (pass == pin)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Account::deposit(double depo)
{
    if (depo > 0)
    {
        balance += depo;
    }
    else
    {
        cout << "Invalid input." << endl;
    }
    cout << "Balance is: " << balance << endl;
}

void Account::withdraw(double draw)
{
    if (balance == 0)
    {
        cout << "There is no balance!" << endl;
    }
    else if (draw > 0 && draw <= balance)
    {
        balance -= draw;
    }
    else
    {
        cout << "Insufficient funds, or invalid input." << endl;
    }
    cout << "Balance is: " << balance << endl;
}





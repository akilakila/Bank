//Name: Akila Suresh
//Assignment: Lab 4
//Date: 10/05/2021

#ifndef ACCOUNT_H
#define ACCOUNT_H 

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Account
{
    private:
        string name;
        int accnum;
        int pin;
        double balance;
    public: 
        //must set balance to 0 
        Account();
        //set attributes to given parameters
        Account(string, int, int, double);
        //Store the name
        void setName(string na);
        //return the name
        string getName();
        //Store the account number
        void setAccountNum(int num);
        //Return the account number
        int getAccountNum();
        //return the balance
        double getBalance();
        //Store the PIN number
        void setPin(int pass);
        //receives a PIN number as parameter
        //returns TRUE if it matches the PIN in the object, false if it does not
        bool checkPin(int pass);
        //Receives amount of money to deposit.  
        //If this amount is valid (positive) then add to balance. Otherwise do nothing.
        void deposit(double depo);
        //Receives amount of money to withdraw.  
        //If this amount is valid (positive) then make sure there are funds to cover the withdrawal.  
        //If so then subtract from balance.  
        //If not enough money then print the message “Insufficient funds” and make no changes.  No return value.
        void withdraw(double draw);
};

#endif
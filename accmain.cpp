#include <iostream>
#include <iomanip>
#include <string>
#include "account.h"

using namespace std;

int findAccount(Account[] , int, int);
void processAccount(Account[] , int);

int main()
{
    Account Bankinfo[5];
    Bankinfo[0] = Account("Joe", 1234, 1111, 1000);
    Bankinfo[1] = Account("Jane", 2345, 2222, 2500);
    Bankinfo[2] = Account("Xo", 3456, 3333, 500.25);
    Bankinfo[3] = Account("Petra", 4567, 4444, 50000);
    Bankinfo[4] = Account("Michael", 5678, 5555, 3300.75);

    cout << "Welcome to Akila's Bank!" << endl;
    int number;
    do
    {
        cout << "Enter account number, 0 to quit: ";
        cin >> number;
        int acc_pos = findAccount(Bankinfo, 5, number);
        if (number == 0)
        {
            cout << "Goodbye!" << endl;
        }
        else if (acc_pos == -1)
        {
           cout << "Invalid account. Please try again." << endl;
        }
        else
        {
            int count;
            int pass;
            do
            {

                cout << "Enter PIN: ";
                cin >> pass;

                count++;
            } while (!Bankinfo[acc_pos].checkPin(pass) && count < 4);
    
            if (count == 4)
            {
                cout << "Security Error!" << endl;
            }
            else
            {
                cout << "Welcome " << Bankinfo[acc_pos].getName() << "!" << endl;
                processAccount(Bankinfo, acc_pos);
            }
        }

    } while (number != 0);
    
    cout << "Coded by: Akila Suresh" << endl;
    return 0;
}

int findAccount(Account Bankinfo[], int size, int num) 
{
    for (int i = 0; i < size; i++)
    {
        if (num == Bankinfo[i].getAccountNum())
        {
            //cout << "this is i" << endl;
            return i;
        }
    }

    return -1;
}

void processAccount(Account Bankinfo[], int position)
{
    char response;
    do
    {
        cout << left << setw(10) << "Withdraw" << setw(10) << "[W]" << endl;
        cout << left << setw(10) << "Deposit" << setw(10) << "[D]" << endl;
        cout << left << setw(10) << "Quit" << setw(10) << "[Q]" << endl;
        cout << "Choose an option: ";
        cin >> response;

        char entry;
        double amount;
        if (toupper(response) == 'W')
        {

            cout << "Amount to withdraw, 0 to quit: ";
            cin >> amount;

            Bankinfo[position].withdraw(amount);
            
        }
        else if (toupper(response) == 'D')
        {
            cout << "Amount to deposit, 0 to quit: ";
            cin >> amount;

            Bankinfo[position].deposit(amount);
        }
        else if (toupper(response) == 'Q')
        {
            cout << "Goodbye, " << Bankinfo[position].getName() << "!" << endl;
        }

    } while (toupper(response) == 'W' || toupper(response) == 'D');
}

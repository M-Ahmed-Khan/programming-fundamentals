#include <iostream>
#include <string>
/* Creates a "BankAccount" class with attributes "accountNumber",
"accountHolder", and "balance" and implements methods to deposit,
withdraw, and display the account balance */

using namespace std;

class BankAccount
{
private:
    long balance;

public:
    string accountHolder;
    string accountNumber;

    BankAccount(string accountHolder, string accountNumber, long balance)
    {
        this->accountHolder = accountHolder;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void deposit()
    {
        long amount;

        cout << "Enter the amount: ";
        cin >> amount;

        balance = balance + amount;

        cout << "You have succesfully deposited " << amount;
    }

    void withdraw()
    {
        long amount;

        cout << "Enter the amount: ";
        cin >> amount;

        balance = balance - amount;

        cout << "You have succesfully withdrew " << amount;
    }

    void displayBalance()
    {
        cout << "Current Balance: " << balance;
    }
};

int main()
{
    BankAccount account("Mr. Williams", "1234 5678 9012", 510000);

    while (true)
    {
        cout << "\n1. Deposit";
        cout << "\n2. Withdrawal";
        cout << "\n3. Check Remaining balance";
        int user_choice;
        cout << "\nEnter your choice: ";
        cin >> user_choice;

        if (user_choice == 1)
        {
            account.deposit();
        }
        else if (user_choice == 2)
        {
            account.withdraw();
        }
        else if (user_choice == 3)
        {
            account.displayBalance();
        }

        string exit_status;

        cout << "\nExit? ";
        cin >> exit_status;

        if (exit_status == "Yes" || exit_status == "yes")
        {
            break;
        }
    }

    return 0;
}
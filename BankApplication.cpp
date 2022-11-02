//Implementation of BankApplication Class
#include "BankSystem_Classes.h"
BankApplication::BankApplication()
{
    int choose;
    cout << "Welcome to FCAI Banking Application\n"
            "1. Create a New Account\n"
            "2. List Clients and Accounts\n"
            "3. Withdraw Money\n"
            "4. Deposit Money\n"
            "Please Enter Choice =>  ";
    cin >> choose;
    if ( choose == 1 )
        cout << "create";
    else if (choose == 2)
        cout << "list";
    else if (choose == 3)
        cout << "Withdraw";
    else if ( choose == 4 )
        cout << "Deposit";
    else
        throw invalid_argument("Bad Input !!");
}

bool BankApplication::addClient()
{
    cout << "What Type of Account Do You Like? \n (1) Basic (2) Saving – Type 1 or 2 => ";
    int choose;
    cin >> choose;
    if (choose == 1 )
        cout << "Basic";
    else if (choose == 2)
        cout << "Saving";
    else
        throw invalid_argument("Bad Input !!");
}
void BankApplication::displayClientsAndAccounts()
{
    for(auto i : clients)
        cout << i << endl;
}

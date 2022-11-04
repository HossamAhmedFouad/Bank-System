//Implementation of SavingsBankAccount Class
#include "BankSystem_Classes.h"

SavingsBankAccount::SavingsBankAccount(double initialBalance,double minimumBalance)
{
        if (initialBalance < minimumBalance)
            cout << "The Minimum price to create an account is " << minimumBalance<<endl;
        else {
            cout << "Account has been created\n";
            this->minimumBalance = minimumBalance;
            setBalance(initialBalance);
            setAccounttype("Savings Account");
        }
}

double SavingsBankAccount::deposit(double amount)
{
    if (amount >= 100){
        setBalance(amount+getBalance());
    }
    else
        cout << "Sorry,  can't do this - [NOTE] the minimum deposit is "<<minimumBalance<<" LE"<<endl;
    return getBalance();
}
double SavingsBankAccount::withdraw(double amount)
{
    if ( amount < minimumBalance)
        cout << "Sorry,  can't do this - [NOTE] the minimum account Balance is "<< minimumBalance<<endl;
    else
        setBalance(getBalance()-amount);
    return getBalance();
}
double SavingsBankAccount::getMinimumBalance()
{
        return minimumBalance;
}
void SavingsBankAccount::setMinimumBalance(double amount)
{
    minimumBalance = amount;
}

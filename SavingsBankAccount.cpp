//Implementation of SavingsBankAccount Class
#include "BankSystem_Classes.h"

SavingsBankAccount::SavingsBankAccount(double initialBalance,double minimumBalance = 1000)
{
    if ( initialBalance < minimumBalance)
        cout << "The Minimum price to create an account is " << minimumBalance;
    else
        cout << "Account has been created you make deposits that are not less than 100 to active your account";
// here force him to deposit .

}

double SavingsBankAccount::deposit(double amount)
{
    if (amount >= 100)
        setBalance(amount+getBalance());
    else
        cout << "Sorry,  can't do this - [NOTE] the minimum deposit is 100 LE";
}
double SavingsBankAccount::withdraw(double amount)
{
    if ( amount < minimumBalance)
        cout << "Sorry,  can't do this - [NOTE] the minimum account Balance is "<< minimumBalance;
    else
        setBalance(getBalance()-amount);
}
double SavingsBankAccount::getMinimumBalance()
{
        return minimumBalance;
}
void SavingsBankAccount::setMinimumBalance(double amount)
{
    minimumBalance = amount;
}

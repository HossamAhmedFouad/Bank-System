//Implementation of SavingsBankAccount Class
#include "BankSystem_Classes.h"

SavingsBankAccount::SavingsBankAccount(double initialBalance,double minimumBalance = 100)
{
    if ( initialBalance < minimumBalance)
        cout << "The Minimum price to create an account is " << minimumBalance<<endl;
    else
        cout << "Account has been created you can make deposits that are not less than 100 to activate your account\n";
// here force him to deposit .

}

double SavingsBankAccount::deposit(double amount)
{
    if (amount >= 100){
        setBalance(amount+getBalance());
        return true;
    }

    else
        cout << "Sorry,  can't do this - [NOTE] the minimum deposit is "<<minimumBalance<<" LE"<<endl;
}
double SavingsBankAccount::withdraw(double amount)
{
    if ( amount < minimumBalance)
        cout << "Sorry,  can't do this - [NOTE] the minimum account Balance is "<< minimumBalance<<endl;
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

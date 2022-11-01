
#ifndef BANK_SYSTEM_BANKSYSTEM_CLASSES_H
#define BANK_SYSTEM_BANKSYSTEM_CLASSES_H
#include <string>
#include <vector>
using namespace std;

class BankAccount{
private:
    string accountID{};
    double balance{};
public:
    BankAccount();
    BankAccount(double amount);
    virtual double deposit(double amount);
    virtual double withdraw(double amount);
    string getAccountID();
    void setAccountID(string accountID);
    double getBalance();
    void setBalance(double balance);
};

class SavingsBankAccount : public BankAccount{
private:
    double minimumBalance{};
public:
    SavingsBankAccount(double initialBalance,double minimumBalance);
    double deposit(double amount) override;
    double withdraw(double amount) override;
    double getMinimumBalance();
    void setMinimumBalance(double amount);

};

class Client{
private:
    string name{},address{},phoneNumber{};
    BankAccount* bankAccount;
public:
    Client(string name,string address,string phoneNumber, BankAccount account);
    string getName();
    void setName(string name);
    string getAddress();
    void setAddress(string address);
    string getPhoneNumber();
    void setPhoneNumber(string phoneNumber);
    BankAccount* getBankAccount();
};



class BankApplication{
private:
    vector<Client>clients{};
public:
    BankApplication();
    bool addClient();
    void displayClientsAndAccounts();
};



#endif //BANK_SYSTEM_BANKSYSTEM_CLASSES_H


#ifndef BANK_SYSTEM_BANKSYSTEM_CLASSES_H
#define BANK_SYSTEM_BANKSYSTEM_CLASSES_H

#include <bits/stdc++.h>

using namespace std;

class BankAccount{
private:
    string accountID{};
    double balance{};
    string accounttype{};
    int fcinum = 0;
public:
    BankAccount();
    BankAccount(double amount);

    virtual double deposit(double amount);
    virtual double withdraw(double amount);
    string getAccountID();
    string getAccounttype();
    void setAccountID(string accountID);
    void setAccounttype(string accounttype);
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
    friend ostream &operator << (ostream &out, Client num);
    Client(string name,string address,string phoneNumber, BankAccount* account);
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
    void run();
};



#endif //BANK_SYSTEM_BANKSYSTEM_CLASSES_H

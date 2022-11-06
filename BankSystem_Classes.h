// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifndef BANK_SYSTEM_BANKSYSTEM_CLASSES_H
#define BANK_SYSTEM_BANKSYSTEM_CLASSES_H

#include <bits/stdc++.h>

using namespace std;

class BankAccount{
private:
    string accountID{};
    double balance{};
    string accounttype{};
    static int fcinum;
public:
    BankAccount();
    BankAccount(double amount);

    virtual double deposit(double amount);
    virtual double withdraw(double amount);
    string getAccountID();
    string getAccounttype();
    void setAccountID(string accountID);
    void setAccounttype(string accounttype);
    static void setfci(int fcinumx)
    {
        fcinum = fcinumx;
    }
    static double getfci()
    {
        return fcinum;
    }
    double getBalance();
    void setBalance(double balance);
};

class SavingsBankAccount : public BankAccount{
private:
    double minimumBalance=1000;
public:
    SavingsBankAccount(double initialBalance,double minimumBalance = 1000);
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

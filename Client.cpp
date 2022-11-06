// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//Implementation of Client Class

#include "BankSystem_Classes.h"

Client::Client(string name,string address,string phoneNumber, BankAccount* account)
{
        this->name = name;
        this ->address = address;
        this->phoneNumber = phoneNumber;
        this->bankAccount = account;
}
string Client::getName()
{
    return this->name;
}
void Client::setName(string name)
{
    this-> name = name;
}
string Client::getAddress()
{
    return this->address;
}
void Client::setAddress(string address)
{
    this->address=address;
}
string Client::getPhoneNumber()
{
    return this->phoneNumber;
}
void Client::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
BankAccount* Client::getBankAccount()
{
    return this->bankAccount;
}
ostream &operator << (ostream &out, Client num)
{
    out << "----------------" << num.getName() << "----------------" <<endl;
    out << "Address : " << num.getAddress() << " , " << "Phone Number : " << num.getPhoneNumber() <<endl ;
    out << "Account ID: " << num.bankAccount->getAccountID() << "  (" << num.bankAccount->getAccounttype() << " )\n";
    out << "Balance : " <<num.bankAccount->getBalance() << "\n";
    out << "----------------" << setw(num.getName().size()) << setfill('-') << "----------------";
    return out;
}

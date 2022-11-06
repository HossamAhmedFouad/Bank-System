// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//Implementation of BankApplication Class
#include "BankSystem_Classes.h"
BankApplication::BankApplication()
{
}

bool BankApplication::addClient()
{
    string name,address,phone;
    int type{0};
    BankAccount *account = nullptr;
    cout<<"Please enter name: ";cin.ignore();getline(cin,name);
    while (!regex_match(name, regex("([_a-zA-Z]*)")))
    {
        cout << "Invalid User Name!, Try Again\n:";
        getline(cin,name);

    }
    cout<<"Please enter address: ";getline(cin,address);
    cout<<"Please enter phone number: ";cin>>phone;
    while(!regex_match(phone, regex("(01)(1|2|5|0)([0-9]+)")) || (phone.size() != 11 && phone.size() != 10) )
    {
        cout<<"Please enter a correct phone number: ";
        cin >> phone;
    }
    cout<<"What Type of Account Do You Like? (1) Basic (2) Saving - Type 1 or 2: "; cin>>type;
    if(type==1){
        double initialBalance = 0;
        cout<<"Please enter the starting balance: ";cin>>initialBalance;
        if(initialBalance<=0){
            cout<<"Sorry,Bad input\n";
            return false;
        }
        account = new BankAccount(initialBalance);
        Client client(name,address,phone,account);
        clients.push_back(client);
    }else if(type==2){
        SavingsBankAccount temp(0);
        double initialBalance= 0;
        cout<<"Please enter the starting balance of your savings account: ";
        cin>>initialBalance;
        temp.setfci(temp.getfci()-1);
        if(initialBalance<temp.getMinimumBalance()){
            cout << "The Minimum price to create an account is " << temp.getMinimumBalance() <<endl;
        }else{
            account = new SavingsBankAccount(initialBalance);
            Client client(name,address,phone,account);
            clients.push_back(client);
        }
    }
    //Have to change constructor of client to take Bank Account Pointer to allow for polymorphism
}

void BankApplication::displayClientsAndAccounts()
{
    for(auto i : clients)
        cout << i << endl;
}

void BankApplication::run() {
    start:;
    int choose;
    cout << "Welcome to FCAI Banking Application\n"
            "1. Create a New Account\n"
            "2. List Clients and Accounts\n"
            "3. Withdraw Money\n"
            "4. Deposit Money\n"
            "5. Exit\n"
            "Please Enter Choice : ";
    cin >> choose;
    if ( choose == 1 ){
        this->addClient();
    }
    else if (choose == 2){
        this->displayClientsAndAccounts();
    }
    else if (choose == 3){

        string accountID;
        bool founded= false;
        cin.ignore();
        cout << "Please enter account ID: ";getline(cin,accountID);
        while (accountID.length()>20){
            cout<<"Input too long,Please try again"<<endl;
            cout << "Please enter account ID: ";getline(cin,accountID);
        }
        for(auto& client : clients){
            //To - Do : Assuming best case scenario that the account exist.... but what if account does not exist? Add that else condition
            if(client.getBankAccount()->getAccountID()==accountID){
                cout<<"Account ID: "<<accountID<<endl;
                cout<<"Account Type: "<<client.getBankAccount()->getAccounttype()<<endl;
                cout<<"Balance: "<<client.getBankAccount()->getBalance()<<endl;
                double amount;
                cout<<"Please enter the amount to withdraw: ";cin>>amount;
                client.getBankAccount()->withdraw(amount);
                cout<<"Thank You."<<endl;
                cout<<"Account ID: "<<accountID<<endl;
                cout<<"New balance: "<<client.getBankAccount()->getBalance()<<endl;
                founded= true;
                break; // End the search for clients
            }
            // TO-DO: Add else condition "done"
        }
        if(!founded){
            cout<<"Account not founded,Please try again"<<endl;
            goto start;
        }
    }
    else if ( choose == 4 ) {  //Same as withdraw but only difference -> call deposit.

        string accountID;
        cin.ignore();
        cout << "Please enter account ID: ";getline(cin,accountID);
        while (accountID.length()>20){
            cout<<"Input too long,Please try again"<<endl;
            cout << "Please enter account ID: ";getline(cin,accountID);
        }
        bool founded= false;
        for(auto& client : clients){
            //To - Do : Assuming best case scenario that the account exist.... but what if account does not exist? Add that else condition
            //Fix account type using base constructor
            //Fix taking long string input using get line function
            if(client.getBankAccount()->getAccountID()==accountID){
                cout<<"Account ID: "<<accountID<<endl;
                cout<<"Account Type: "<<client.getBankAccount()->getAccounttype()<<endl;
                cout<<"Balance: "<<client.getBankAccount()->getBalance()<<endl;
                double amount;
                cout<<"Please enter the amount to deposit: ";cin>>amount;
                client.getBankAccount()->deposit(amount);
                cout<<"Thank You."<<endl;
                cout<<"Account ID: "<<accountID<<endl;
                cout<<"New balance: "<<client.getBankAccount()->getBalance()<<endl;
                founded= true;
                break; // End the search for clients
            }
            // TO-DO: Add else condition "done"
        }
        if(!founded){
            cout<<"Account not founded,Please try again"<<endl;
            goto start;
        }
    }else if(choose==5){
        cout<<"Thank You."<<endl;
        exit(0);
    }else
        throw invalid_argument("Bad Input !!");
}




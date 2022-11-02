//Implementation of BankApplication Class
#include "BankSystem_Classes.h"
BankApplication::BankApplication()
{
}

bool BankApplication::addClient()
{
    string name,address,phone;
    int type{0};
    BankAccount* account;
    cout<<"Please enter name: ";cin>>name;
    cout<<"Please enter address: ";cin>>address;
    cout<<"Please enter phone number: ";cin>>phone;
    cout<<"What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2: "; cin>>type;
    if(type==1){
        int initialBalance = 0;
        cout<<"Please enter the starting balance: ";cin>>initialBalance;
        account = new BankAccount(initialBalance);
    }else if(type==2){
        double initialBalance= 0;
        cout<<"Please enter the starting balance of your savings account: ";cin>>initialBalance;
        account = new SavingsBankAccount(initialBalance,1000);
    }

    //Have to change constructor of client to take Bank Account Pointer to allow for polymorphism
    Client client(name,address,phone,account);
    clients.push_back(client);
}
void BankApplication::displayClientsAndAccounts()
{
    for(auto i : clients)
        cout << i << endl;
}

void BankApplication::run() {
    int choose;
    cout << "Welcome to FCAI Banking Application\n"
            "1. Create a New Account\n"
            "2. List Clients and Accounts\n"
            "3. Withdraw Money\n"
            "4. Deposit Money\n"
            "5. Exit\n"
            "Please Enter Choice =>  ";
    cin >> choose;
    if ( choose == 1 ){
        this->addClient();
    }
    else if (choose == 2){
        this->displayClientsAndAccounts();
    }
    else if (choose == 3){
        string accountID;
        cout << "Please enter account ID: ";cin>>accountID;
        for(auto& client : clients){
            //To - Do : Assuming best case scenario that the account exist.... but what if account does not exist? Add that else condition
            if(client.getBankAccount()->getAccountID()==accountID){
                cout<<"Account ID: "<<accountID<<endl;
                cout<<"Account Type: "<< "TO DO - FIX account type attribute by calling Base constructor to child constructor and add the base constructor call to child constructor"<<endl;
                cout<<"Balance: "<<client.getBankAccount()->getBalance()<<endl;
                double amount;
                cout<<"Please enter the amount to withdraw: ";cin>>amount;
                client.getBankAccount()->withdraw(amount);
                cout<<"Thank You."<<endl;
                cout<<"Account ID: "<<accountID<<endl;
                cout<<"New balance: "<<client.getBankAccount()->getBalance()<<endl;
                break; // End the search for clients
            }
            // TO-DO: Add else condition
        }
    }
    else if ( choose == 4 ) {  //Same as withdraw but only difference -> call deposit.
        string accountID;
        cout << "Please enter account ID: ";cin>>accountID;
        for(auto& client : clients){
            //To - Do : Assuming best case scenario that the account exist.... but what if account does not exist? Add that else condition
            //Fix account type using base constructor
            //Fix taking long string input using get line function
            if(client.getBankAccount()->getAccountID()==accountID){
                cout<<"Account ID: "<<accountID<<endl;
                cout<<"Account Type: "<< "-FIXME-"<<endl;
                cout<<"Balance: "<<client.getBankAccount()->getBalance()<<endl;
                double amount;
                cout<<"Please enter the amount to deposit: ";cin>>amount;
                client.getBankAccount()->deposit(amount);
                cout<<"Thank You."<<endl;
                cout<<"Account ID: "<<accountID<<endl;
                cout<<"New balance: "<<client.getBankAccount()->getBalance()<<endl;
                break; // End the search for clients
            }
            // TO-DO: Add else condition
        }
    }else if(choose==5){
        cout<<"Thank You."<<endl;
        exit(0);
    }else
        throw invalid_argument("Bad Input !!");
}

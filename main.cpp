#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// Transaction Class
class Transaction {
    int transactionID;
    string dateTime;
    string type;
    double amount;
    string description;

    string getCurrentDateTime() {
        time_t now = time(0);
        char* dt = ctime(&now);
        return string(dt);
    }

public:
    Transaction(int id, string t, double amt, string desc)
        : transactionID(id), type(t), amount(amt), description(desc) {
        dateTime = getCurrentDateTime();
    }

    void displayTransaction() {
        cout << "ID: " << transactionID << " | " << type
             << " | Amount: " << amount << " | " << dateTime
             << " | " << description;
    }
};

// Account Class
class Account {
    int accountNumber;
    double balance;
    vector<Transaction> transactions;
    static int transactionCounter;

public:
    Account(int accNo) : accountNumber(accNo), balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction(++transactionCounter, "Deposit", amount, "Deposit"));
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!" << endl;
            return;
        }
        balance -= amount;
        transactions.push_back(Transaction(++transactionCounter, "Withdrawal", amount, "Withdraw"));
        cout << "Withdrawn: " << amount << endl;
    }

    void transfer(Account &toAccount, double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance for Transfer!" << endl;
            return;
        }
        balance -= amount;
        toAccount.balance += amount;

        transactions.push_back(Transaction(++transactionCounter, "Transfer", amount, "To Account " + to_string(toAccount.accountNumber)));
        toAccount.transactions.push_back(Transaction(++transactionCounter, "Received", amount, "From Account " + to_string(accountNumber)));

        cout << "Transferred: " << amount << " to Account No: " << toAccount.accountNumber << endl;
    }

    void viewTransactions() {
        cout << "\nTransactions for Account No: " << accountNumber << endl;
        for (auto &t : transactions) {
            t.displayTransaction();
        }
    }

    void displayAccountInfo() {
        cout << "Account No: " << accountNumber << " | Balance: " << balance << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }
};
int Account::transactionCounter = 0;

// Customer Class
class Customer {
    int customerID;
    string name;
    vector<Account> accounts;

public:
    Customer(int id, string n) : customerID(id), name(n) {}

    void createAccount(int accNo) {
        accounts.push_back(Account(accNo));
        cout << "Account Created: " << accNo << endl;
    }

    Account* getAccountByNumber(int accNo) {
        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNo)
                return &acc;
        }
        return nullptr;
    }

    void displayCustomerInfo() {
        cout << "\nCustomer ID: " << customerID << " | Name: " << name << endl;
        for (auto &acc : accounts) {
            acc.displayAccountInfo();
        }
    }

    int getCustomerID() {
        return customerID;
    }
};

// Banking System Class (Main Controller)
class BankingSystem {
    vector<Customer> customers;

public:
    void mainMenu() {
        int choice;
        do {
            cout << "\n=== Banking System Menu ===\n";
            cout << "1. Add Customer\n2. Create Account\n3. Deposit\n4. Withdraw\n5. Transfer\n6. View Account Info\n7. View Transactions\n0. Exit\n";
            cout << "Enter Choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addCustomer(); break;
                case 2: createAccount(); break;
                case 3: depositAmount(); break;
                case 4: withdrawAmount(); break;
                case 5: transferAmount(); break;
                case 6: viewAccountInfo(); break;
                case 7: viewTransactions(); break;
                case 0: cout << "Exiting...\n"; break;
                default: cout << "Invalid Choice!\n";
            }
        } while (choice != 0);
    }

    Customer* getCustomerByID(int id) {
        for (auto &cust : customers) {
            if (cust.getCustomerID() == id)
                return &cust;
        }
        return nullptr;
    }

    void addCustomer() {
        int id;
        string name;
        cout << "Enter Customer ID: "; cin >> id;
        cin.ignore();
        cout << "Enter Customer Name: "; getline(cin, name);
        customers.push_back(Customer(id, name));
        cout << "Customer Added Successfully.\n";
    }

    void createAccount() {
        int custID, accNo;
        cout << "Enter Customer ID: "; cin >> custID;
        Customer* cust = getCustomerByID(custID);
        if (!cust) {
            cout << "Customer Not Found!\n"; return;
        }
        cout << "Enter New Account Number: "; cin >> accNo;
        cust->createAccount(accNo);
    }

    void depositAmount() {
        int custID, accNo;
        double amount;
        cout << "Enter Customer ID: "; cin >> custID;
        Customer* cust = getCustomerByID(custID);
        if (!cust) { cout << "Customer Not Found!\n"; return; }

        cout << "Enter Account No: "; cin >> accNo;
        Account* acc = cust->getAccountByNumber(accNo);
        if (!acc) { cout << "Account Not Found!\n"; return; }

        cout << "Enter Deposit Amount: "; cin >> amount;
        acc->deposit(amount);
    }

    void withdrawAmount() {
        int custID, accNo;
        double amount;
        cout << "Enter Customer ID: "; cin >> custID;
        Customer* cust = getCustomerByID(custID);
        if (!cust) { cout << "Customer Not Found!\n"; return; }

        cout << "Enter Account No: "; cin >> accNo;
        Account* acc = cust->getAccountByNumber(accNo);
        if (!acc) { cout << "Account Not Found!\n"; return; }

        cout << "Enter Withdrawal Amount: "; cin >> amount;
        acc->withdraw(amount);
    }

    void transferAmount() {
        int custID, fromAccNo, toAccNo;
        double amount;
        cout << "Enter Customer ID: "; cin >> custID;
        Customer* cust = getCustomerByID(custID);
        if (!cust) { cout << "Customer Not Found!\n"; return; }

        cout << "Enter Source Account No: "; cin >> fromAccNo;
        Account* fromAcc = cust->getAccountByNumber(fromAccNo);
        if (!fromAcc) { cout << "Source Account Not Found!\n"; return; }

        cout << "Enter Destination Account No: "; cin >> toAccNo;
        Account* toAcc = cust->getAccountByNumber(toAccNo);
        if (!toAcc) { cout << "Destination Account Not Found!\n"; return; }

        cout << "Enter Transfer Amount: "; cin >> amount;
        fromAcc->transfer(*toAcc, amount);
    }

    void viewAccountInfo() {
        int custID;
        cout << "Enter Customer ID: "; cin >> custID;
        Customer* cust = getCustomerByID(custID);
        if (!cust) { cout << "Customer Not Found!\n"; return; }

        cust->displayCustomerInfo();
    }

    void viewTransactions() {
        int custID, accNo;
        cout << "Enter Customer ID: "; cin >> custID;
        Customer* cust = getCustomerByID(custID);
        if (!cust) { cout << "Customer Not Found!\n"; return; }

        cout << "Enter Account No: "; cin >> accNo;
        Account* acc = cust->getAccountByNumber(accNo);
        if (!acc) { cout << "Account Not Found!\n"; return; }

        acc->viewTransactions();
    }
};

// Main Function
int main() {
    BankingSystem bank;
    bank.mainMenu();
    return 0;
}

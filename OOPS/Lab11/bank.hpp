#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getCurrentDateTime() {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%S", timeinfo);
    string str(buffer);
    return str;
}

class Customer {
    string UID;
    string name;
    int age;
    string mobile;

   public:
    // Constructors
    Customer() {
        this->name = "";
        this->age = 0;
        this->UID = "";
        this->mobile = "";
    }
    Customer(string name, int age, string UID, string mobile) {
        this->name = name;
        this->age = age;
        this->UID = UID;
        this->mobile = mobile;
    }
    // Getter Setter
    string getmobile() {
        return this->mobile;
    }
    void setmobile(string mobile) {
        this->mobile = mobile;
    }
    int getAge() {
        return this->age;
    }
    void setAge(int age) {
        this->age = age;
    }
    string getUID() {
        return this->UID;
    }
    void setUID(string UID) {
        this->UID = UID;
    }
    string getName() {
        return this->name;
    }
    void setName(string name) {
        this->name = name;
    }
};

class Account {
   protected:
    Customer customer;
    double balance;
    string accountNo;

   public:
    // Getters & Setters
    string getaccountNo() {
        return this->accountNo;
    }
    void setaccountNo(string accountNo) {
        this->accountNo = accountNo;
    }
    Customer getCustomer() {
        return this->customer;
    }
    void setCustomer(Customer customer, double balance) {
        this->customer = customer;
        this->balance = balance;
    }
    double getBalance() {
        return this->balance;
    }
    void setBalance(double balance) {
        this->balance = balance;
    }
    void deposit(double amount) {
        if (amount > 0) {
            this->balance = this->balance + amount;
        } else {
            cerr << "Cannot deposit amount less than zero!\n";
        }
    }
    // Constructors
    Account() {
        this->customer = Customer();
        this->balance = 0.0;
        this->accountNo = "";
    };
    Account(double balance, Customer customer, string accountNo) {
        this->balance = balance;
        this->customer = customer;
        this->accountNo = accountNo;
    };
};

class Transaction {
    string operation;
    string accountNo;
    double amount;
    string date;

   public:
    Transaction() {
        this->operation = "None";
        this->amount = 0;
        this->date = "";
        this->accountNo = "";
    }
    Transaction(string operation, double amount, string date, string accountNo) {
        this->operation = operation;
        this->amount = amount;
        this->date = date;
        this->accountNo = accountNo;
    }
    string getAccountNo() {
        return this->accountNo;
    }
    void setAccountNo(string account) {
        this->accountNo = account;
    }
    string getDate() {
        return this->date;
    }
    void setDate(string date) {
        this->date = date;
    }
    double getAmount() {
        return this->amount;
    }
    void setAmount(double amount) {
        this->amount = amount;
    }
    string getOperation() {
        return this->operation;
    }
    void setOperation(string operation) {
        this->operation = operation;
    }
};

class SavingsAccount : public Account {
   protected:
    double MaxLimit;
    double MinimumBalance;

   public:
    bool withdraw(double amount) {
        if (this->balance - amount < this->MinimumBalance && amount <= this->MaxLimit) {
            return false;
        }
        this->balance = this->balance - amount;
        return true;
    }
    // Constructor
    SavingsAccount() : Account() {
        this->MaxLimit = 100000;
        this->MinimumBalance = 200;
    }
    SavingsAccount(Customer customer, double balance, string accountNo) : Account(balance, customer, accountNo) {
        this->MaxLimit = 100000;
        this->MinimumBalance = 200;
    }
    // Getters & Setters
    double getMinimumBalance() {
        return this->MinimumBalance;
    }
    void setMinimumBalance(double MinimumBalance) {
        this->MinimumBalance = MinimumBalance;
    }
    double getMaxLimit() {
        return this->MaxLimit;
    }
    void setMaxLimit(double MaxLimit) {
        this->MaxLimit = MaxLimit;
    }
};

class CurrentAccount : public Account {
   protected:
    double MinimumActiveBalance;

   public:
    bool withdraw(double amount) {
        if (this->balance - amount < this->MinimumActiveBalance) {
            return false;
        }
        this->balance = this->balance - amount;
        return true;
    }
    CurrentAccount() : Account() {
        this->MinimumActiveBalance = 40;
    }
    CurrentAccount(Customer customer, double balance, string accountNo) : Account(balance, customer, accountNo) {
        this->MinimumActiveBalance = 40;
    }
    double getMinimumActiveBalance() {
        return this->MinimumActiveBalance;
    }
    void setMinimumActiveBalance(double MinimumActiveBalance) {
        this->MinimumActiveBalance = MinimumActiveBalance;
    }
};

class Bank {
   private:
    string Name;
    string Branch;
    string IFSC;
    int AccountCount;
    vector<SavingsAccount> SavingsAccounts;
    vector<CurrentAccount> CurrentAccounts;
    vector<Transaction> transactions;

   public:
    bool Withdraw(string accountNo, double amount, string type) {
        int i;
        if (type[0] == 's' || type[0] == 'S') {
            for (i = 0; i < this->SavingsAccounts.size(); i++) {
                if (accountNo == this->SavingsAccounts[i].getaccountNo()) {
                    break;
                }
            }
            if (i == this->SavingsAccounts.size()) {
                return false;
            } else {
                if (this->SavingsAccounts[i].withdraw(amount)) {
                    this->transactions.push_back(
                        Transaction("Withdrawl", amount, getCurrentDateTime(), accountNo));
                    return true;
                } else {
                    return false;
                }
            }
        } else {
            for (i = 0; i < this->CurrentAccounts.size(); i++) {
                if (accountNo == this->CurrentAccounts[i].getaccountNo()) {
                    break;
                }
            }
            if (i == this->CurrentAccounts.size()) {
                return false;
            } else {
                if (this->CurrentAccounts[i].withdraw(amount)) {
                    this->transactions.push_back(
                        Transaction("Withdrawl", amount, getCurrentDateTime(), accountNo));
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    bool Deposit(string accountNo, double amount) {
        int i;
        for (i = 0; i < this->SavingsAccounts.size(); i++) {
            if (accountNo == this->SavingsAccounts[i].getaccountNo()) {
                break;
            }
        }
        if (i < this->SavingsAccounts.size()) {
            this->SavingsAccounts[i].deposit(amount);
            this->transactions.push_back(
                Transaction("Deposit", amount, getCurrentDateTime(), accountNo));
            return true;
        }

        for (i = 0; i < this->CurrentAccounts.size(); i++) {
            if (accountNo == this->CurrentAccounts[i].getaccountNo()) {
                break;
            }
        }
        if (i == this->CurrentAccounts.size()) {
            return false;
        } else {
            this->CurrentAccounts[i].deposit(amount);
            this->transactions.push_back(
                Transaction("Deposit", amount, getCurrentDateTime(), accountNo));
            return true;
        }
    }
    bool Tranfer(string from, string type, string to, double amount) {
        int i;
        if (type[0] == 's' || type[0] == 'S') {
            for (i = 0; i < this->SavingsAccounts.size(); i++) {
                if (from == this->SavingsAccounts[i].getaccountNo()) {
                    break;
                }
            }
            if (i == this->SavingsAccounts.size()) {
                return false;
            } else {
                if (this->SavingsAccounts[i].withdraw(amount)) {
                    if (this->Deposit(to, amount)) {
                        this->transactions.push_back(
                            Transaction("Transferred to " + to, amount, getCurrentDateTime(), from));
                        this->transactions.push_back(
                            Transaction("Recieved from " + from, amount, getCurrentDateTime(), to));
                        return true;
                    } else {
                        this->SavingsAccounts[i].deposit(amount);
                    }
                } else {
                    return false;
                }
            }
        } else {
            for (i = 0; i < this->CurrentAccounts.size(); i++) {
                if (from == this->CurrentAccounts[i].getaccountNo()) {
                    break;
                }
            }
            if (i == this->CurrentAccounts.size()) {
                return false;
            } else {
                if (this->CurrentAccounts[i].withdraw(amount)) {
                    if (this->Deposit(to, amount)) {
                        this->transactions.push_back(
                            Transaction("Transferred to " + to, amount, getCurrentDateTime(), from));
                        this->transactions.push_back(
                            Transaction("Recieved from " + from, amount, getCurrentDateTime(), to));
                        return true;
                    } else {
                        this->CurrentAccounts[i].deposit(amount);
                    }
                } else {
                    return false;
                }
            }
        }
    }

    void AddTransaction(Transaction transaction) {
        this->transactions.push_back(transaction);
    }
    void AddSavingsAccount(Customer customer, string accountNo) {
        SavingsAccount AC(customer, 0, accountNo);
        this->SavingsAccounts.push_back(AC);
    }
    void AddSavingsAccount(SavingsAccount account) {
        this->SavingsAccounts.push_back(account);
    }
    void AddCurrentAccount(Customer customer, string accountNo) {
        CurrentAccount AC(customer, 0, accountNo);
        this->CurrentAccounts.push_back(AC);
    }
    void AddCurrentAccount(CurrentAccount account) {
        this->CurrentAccounts.push_back(account);
    }

    // Constructor
    Bank() {
        this->Name = "";
        this->Branch = "";
        this->IFSC = "";
        this->AccountCount = 0;
        this->SavingsAccounts = vector<SavingsAccount>();
        this->CurrentAccounts = vector<CurrentAccount>();
    }
    Bank(string Name, string Branch, string IFSC) {
        this->Name = Name;
        this->Branch = Branch;
        this->IFSC = IFSC;
        this->AccountCount = 0;
        this->SavingsAccounts = vector<SavingsAccount>();
        this->CurrentAccounts = vector<CurrentAccount>();
    }
    int getAccountCount() {
        return this->AccountCount;
    }
    void setAccountCount(int AccountCount) {
        this->AccountCount = AccountCount;
    }

    // Getters & Setters
    vector<Transaction> gettransactions() {
        return this->transactions;
    }
    void settransactions(vector<Transaction> transactions) {
        this->transactions = transactions;
    }
    vector<CurrentAccount> getCurrentAccounts() {
        return this->CurrentAccounts;
    }
    void setCurrentAccounts(vector<CurrentAccount> CurrentAccounts) {
        this->CurrentAccounts = CurrentAccounts;
    }
    vector<SavingsAccount> getSavingsAccounts() {
        return this->SavingsAccounts;
    }
    void setSavingsAccounts(vector<SavingsAccount> SavingsAccounts) {
        this->SavingsAccounts = SavingsAccounts;
    }
    string getIFSC() {
        return this->IFSC;
    }
    void setIFSC(string IFSC) {
        this->IFSC = IFSC;
    }
    string getBranch() {
        return this->Branch;
    }
    void setBranch(string Branch) {
        this->Branch = Branch;
    }
    string getName() {
        return this->Name;
    }
    void setName(string Name) {
        this->Name = Name;
    }
};

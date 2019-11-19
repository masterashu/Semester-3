#include <ctime>
#include <fstream>
#include <iostream>
#include "bank.hpp"
#include "dist/json/json.h"

using namespace std;

Customer findCustomerByUID(string uid, vector<Customer> customers) {
    for (int i = 0; i < customers.size(); i++) {
        if (uid == customers[i].getUID()) {
            return customers[i];
        }
    }
    cerr << "Customer not Found!\n";
    exit(11);
}

Account *findAccountByAccountNo(string accountNo, Bank bank) {
    for (int i = 0; i < bank.getCurrentAccounts().size(); i++) {
        if (accountNo == bank.getCurrentAccounts()[i].getaccountNo()) {
            return &(bank.getCurrentAccounts()[i]);
        }
    }
    for (int i = 0; i < bank.getSavingsAccounts().size(); i++) {
        if (accountNo == bank.getSavingsAccounts()[i].getaccountNo()) {
            return &(bank.getCurrentAccounts()[i]);
        }
    }
    cerr << "Customer not Found!\n";
    return NULL;
}

void UpdateCustomerJSON(vector<Customer> customers) {
    Json::StyledWriter writer;
    Json::Value customers_json(Json::arrayValue);
    for (int i = 0; i < customers.size(); i++) {
        Json::Value c1;
        c1["name"] = customers[i].getName();
        c1["age"] = customers[i].getAge();
        c1["uid"] = customers[i].getUID();
        c1["mobile"] = customers[i].getmobile();
        customers_json.append(c1);
    }

    ofstream cust_json;
    cust_json.open("customers.json");

    cust_json << writer.write(customers_json) << endl;
    cust_json.close();
}

void UpdateBankDetails(Bank bank) {
    // Updating Current Account
    Json::StyledWriter writer;
    Json::Value c_acc(Json::arrayValue);

    for (int i = 0; i < bank.getCurrentAccounts().size(); i++) {
        Json::Value c1;
        CurrentAccount ca = bank.getCurrentAccounts()[i];
        c1["accountNo"] = ca.getaccountNo();
        c1["balance"] = ca.getBalance();
        c1["customer"] = ca.getCustomer().getUID();
        c1["MinimumActiveBalance"] = ca.getMinimumActiveBalance();
        c_acc.append(c1);
    }

    ofstream ca_json;
    ca_json.open("current_account.json");

    ca_json << writer.write(c_acc) << endl;
    ca_json.close();

    // Updating Savings Account
    Json::Value s_acc(Json::arrayValue);

    for (int i = 0; i < bank.getSavingsAccounts().size(); i++) {
        Json::Value c1;
        SavingsAccount sa = bank.getSavingsAccounts()[i];
        c1["accountNo"] = sa.getaccountNo();
        c1["balance"] = sa.getBalance();
        c1["customer"] = sa.getCustomer().getUID();
        c1["MaxLimit"] = sa.getMaxLimit();
        c1["MinimumBalance"] = sa.getMinimumBalance();
        s_acc.append(c1);
    }

    ofstream sa_json;
    sa_json.open("saving_account.json");

    sa_json << writer.write(s_acc) << endl;
    sa_json.close();

    // Updating Transactions

    Json::Value txn(Json::arrayValue);

    for (int i = 0; i < bank.gettransactions().size(); i++) {
        Transaction tx = bank.gettransactions()[i];
        Json::Value tx_val;
        tx_val["operation"] = tx.getOperation();
        tx_val["amount"] = tx.getAmount();
        tx_val["date"] = tx.getDate();
        tx_val["account"] = tx.getAccountNo();
        cout << tx.getAccountNo() << endl;
        txn.append(tx_val);
    }

    ofstream txn_json;
    txn_json.open("transactions.json");

    txn_json << writer.write(txn) << endl;
    txn_json.close();
}

void LoadDataFromJSON(Bank &bank, vector<Customer> &customers) {
    // Loading Customers
    // Reading File
    ifstream infile{"customers.json"};
    string customer_json{istreambuf_iterator<char>(infile), istreambuf_iterator<char>()};

    Json::Reader reader;
    Json::Value root;

    bool parseSuccess = reader.parse(customer_json, root, false);
    if (!parseSuccess) {
        cerr << "Unable to Parse customers.json!\n";
        exit(10);
    }

    for (Json::Value::ArrayIndex i = 0; i < root.size(); i++) {
        if (root[i].isMember("name") && root[i].isMember("uid") && root[i].isMember("age") && root[i].isMember("mobile")) {
            Customer cust(
                root[i]["name"].asString(),
                root[i]["age"].asInt(),
                root[i]["uid"].asString(),
                root[i]["mobile"].asString());
            customers.push_back(cust);
        }
    }

    infile.close();

    // Loading Saving Accounts

    Json::Value s_acc;

    ifstream infile2{"saving_account.json"};
    string saving_account_json{istreambuf_iterator<char>(infile2), istreambuf_iterator<char>()};

    parseSuccess = reader.parse(saving_account_json, s_acc, false);

    if (!parseSuccess) {
        cerr << "Unable to Parse saving_account.json!\n";
        exit(10);
    }

    for (Json::Value::ArrayIndex i = 0; i < s_acc.size(); i++) {
        if (s_acc[i].isMember("customer") && s_acc[i].isMember("balance") && s_acc[i].isMember("accountNo")) {
            SavingsAccount AC(
                findCustomerByUID(s_acc[i]["customer"].asString(), customers),
                s_acc[i]["balance"].asDouble(),
                s_acc[i]["accountNo"].asString());

            if (s_acc[i].isMember("maxLimit")) {
                AC.setMaxLimit(s_acc[i]["maxLimit"].asDouble());
            }
            if (s_acc[i].isMember("MinimumBalance")) {
                AC.setMinimumBalance(s_acc[i]["MinimumBalance"].asDouble());
            }
            bank.AddSavingsAccount(AC);
        }
    }

    infile2.close();

    // Loading Current Accounts

    Json::Value c_acc;

    ifstream infile3{"current_account.json"};
    string current_account_json{istreambuf_iterator<char>(infile3), istreambuf_iterator<char>()};

    parseSuccess = reader.parse(current_account_json, c_acc, false);

    if (!parseSuccess) {
        cerr << "Unable to Parse current_account.json!\n";
        exit(10);
    }

    for (Json::Value::ArrayIndex i = 0; i < c_acc.size(); i++) {
        if (c_acc[i].isMember("customer") && c_acc[i].isMember("balance") && c_acc[i].isMember("balance")) {
            CurrentAccount AC(
                findCustomerByUID(c_acc[i]["customer"].asString(), customers),
                c_acc[i]["balance"].asDouble(),
                c_acc[i]["accountNo"].asString());

            if (c_acc[i].isMember("MinimumActiveBalance")) {
                AC.setMinimumActiveBalance(c_acc[i]["MinimumActiveBalance"].asDouble());
            }
            bank.AddCurrentAccount(AC);
        }
    }

    infile3.close();

    // Loading Transactions

    Json::Value txn;

    ifstream infile4{"transactions.json"};
    string transactions_json{istreambuf_iterator<char>(infile4), istreambuf_iterator<char>()};

    parseSuccess = reader.parse(transactions_json, txn, false);

    if (!parseSuccess) {
        cerr << "Unable to Parse transactions.json!\n";
        exit(10);
    }

    for (Json::Value::ArrayIndex i = 0; i < txn.size(); i++) {
        if (txn[i].isMember("operation") && txn[i].isMember("date") && txn[i].isMember("amount") && txn[i].isMember("account")) {
            Transaction Txn(
                txn[i]["operation"].asString(),
                txn[i]["amount"].asDouble(),
                txn[i]["date"].asString(),
                txn[i]["account"].asString());
            bank.AddTransaction(Txn);
        }
    }
    infile4.close();
}

int main() {
    vector<Customer> customers;
    Bank B("Goliath National Bank", "New York", "GNP000100121");

    // Load Program Data
    LoadDataFromJSON(B, customers);
    // UpdateCustomerJSON(customers);
    UpdateBankDetails(B);

    int ch = 1;
    while (ch != 0) {
        cout << "Welcome to " << B.getName() << endl;
        cout << "1: Register a new Customer" << endl;
        cout << "2: Add New Savings Account" << endl;
        cout << "3: Add New Current Account" << endl;
        cout << "4: Make a Withdrawl" << endl;
        cout << "5: Make a Deposit" << endl;
        cout << "6: Send money to another count" << endl;
        cout << "0: To EXIT" << endl;
        cout << "Enter Choice: ";
        cin >> ch;
        string cid, name, mobile, uid, accountNo, dummy, acNo;
        int age;
        double balance, amount;
        Customer c1;
        switch (ch) {
            // Add new Customer
            case 1:
                getline(cin, dummy);
                cout << "Enter Customer Details:\nName: ";
                getline(cin, name);
                cout << "Mobile: ";
                getline(cin, mobile);
                cout << "UID: ";
                getline(cin, uid);
                cout << "Age: ";
                cin >> age;
                customers.push_back(Customer(name, age, uid, mobile));
                UpdateCustomerJSON(customers);
                break;
            // Add New Savings Account
            case 2:
                cout << "Enter Customer UID\n";
                cin >> cid;
                c1 = findCustomerByUID(cid, customers);
                // If Customer is not found
                if (c1.getUID() == "") {
                    cout << "Enter Customer Details:\nName: ";
                    cin >> name;
                    cout << "Age: ";
                    cin >> age;
                    cout << "Mobile: ";
                    cin >> mobile;
                    c1.setName(name);
                    c1.setAge(age);
                    c1.setmobile(mobile);
                    customers.push_back(c1);
                }
                cout << "Adding New Savings Account\n";
                cout << "Account No: ";
                cin >> accountNo;
                B.AddSavingsAccount(c1, accountNo);
                break;
            // Add New Current Account
            case 3:
                cout << "Enter Customer UID\n";
                cin >> cid;
                c1 = findCustomerByUID(cid, customers);
                // If Customer is not found
                if (c1.getUID() == "") {
                    cout << "Enter Customer Details:\nName: ";
                    cin >> name;
                    cout << "Age: ";
                    cin >> age;
                    cout << "Mobile: ";
                    cin >> mobile;
                    c1.setName(name);
                    c1.setAge(age);
                    c1.setmobile(mobile);
                    customers.push_back(c1);
                }
                cout << "Adding New Current Account\n";
                cout << "Account No: ";
                cin >> accountNo;
                B.AddCurrentAccount(c1, accountNo);
                break;
            // Make a Withdrawl
            case 4:
                cout << "Enter Account No: ";
                cin >> accountNo;
                cout << "Account Type (S)Savings/(C)Current: ";
                cin >> dummy;
                cout << "Enter Amount: ";
                cin >> amount;
                if (B.Withdraw(accountNo, amount, dummy)) {
                    cout << "Success" << endl;
                } else {
                    cerr << "Unable to process" << endl;
                }
                UpdateBankDetails(B);
                break;
            // Make a Deposit
            case 5:
                cout << "Enter Account No: ";
                cin >> accountNo;
                cout << "Account Type (S)Savings/(C)Current: ";
                cin >> dummy;
                cout << "Enter Amount: ";
                cin >> amount;
                B.Deposit(accountNo, amount);
                UpdateBankDetails(B);
                break;
            // Transfer money
            case 6:
                cout << "Enter Account No: ";
                cin >> accountNo;
                cout << "Account Type (S)Savings/(C)Current: ";
                cin >> dummy;
                cout << "Tranfer to Account No: ";
                cin >> acNo;
                cout << "Enter amount: ";
                cin >> amount;
                B.Tranfer(accountNo, dummy, acNo, amount);
                UpdateBankDetails(B);
                break;
        }
    }
    UpdateBankDetails(B);
    return 0;
}

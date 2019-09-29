#include "bank.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    string BName, Branch, IFSC;
    cout << "Enter Bank Name:";
    cin >> BName;
    cout << "Enter Bank Branch:";
    cin >> Branch;
    cout << "Enter Bank IFSC:";
    cin >> IFSC;
    Bank B(BName, Branch, IFSC);

    int ch = 1;
    while (ch != 0) {
        cout << "1: Add New Savings Account" << endl;
        cout << "2: Add New Current Account" << endl;
        cout << "3: Add Fixed Deposits" << endl;
        cout << "0: To EXIT" << endl;
        cout << "Enter Choice: ";
        cin >> ch;
        string AccountNo, ACHolderName, Mobile, FDID;
        double InitialAmount, IntrestRate, Balance;
        switch (ch) {
            // Add New Savings Account
            case 1:
                cout << "Adding New Savings Account\n";
                cout << "Enter Account Holder Name: ";
                cin >> ACHolderName;
                cout << "Enter Mobile No: ";
                cin >> Mobile;
                AccountNo = to_string(B.getAccountCount() + 1);
                B.setAccountCount(B.getAccountCount() + 1);
                B.AddSavingsAccount(AccountNo, ACHolderName, Mobile);
                break;

            // Add New Non Current Account
            case 2:
                cout << "Adding New Current Account\n";
                cout << "Enter Account Holder Name: ";
                cin >> ACHolderName;
                cout << "Enter Mobile No: ";
                cin >> Mobile;
                AccountNo = to_string(B.getAccountCount() + 1);
                B.setAccountCount(B.getAccountCount() + 1);
                B.AddCurrentAccount(AccountNo, ACHolderName, Mobile);
                break;

            // Add New Fixed Deposit
            case 3:
                cout << "Adding New Fixed Deposit\n";
                cout << "Enter Account No: ";
                cin >> AccountNo;
                cout << "Enter FD Number: ";
                cin >> FDID;
                cout << "Enter Initial Amount: ";
                cin >> InitialAmount;
                cout << "Enter Intrest Rate: ";
                cin >> IntrestRate;
                B.AddFixedDeposit(AccountNo, FDID, InitialAmount, IntrestRate);
                break;
        }
    }

    return 0;
}

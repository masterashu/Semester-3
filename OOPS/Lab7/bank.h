#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
   protected:
    string AccountNo;
    double Balance;
    string ACHolderName;
    string Mobile;

   public:
    // Getters & Setters
    string getMobile() {
        return this->Mobile;
    }
    void setMobile(string Mobile) {
        this->Mobile = Mobile;
    }
    string getACHolderName() {
        return this->ACHolderName;
    }
    void setACHolderName(string ACHolderName) {
        this->ACHolderName = ACHolderName;
    }
    double getBalance() {
        return this->Balance;
    }
    void setBalance(double Balance) {
        this->Balance = Balance;
    }
    string getAccountNo() {
        return this->AccountNo;
    }
    void setAccountNo(string AccountNo) {
        this->AccountNo = AccountNo;
    }
    // Constructors
    Account() {
        this->AccountNo = "";
        this->ACHolderName = "";
        this->Balance = 0.0;
        this->Mobile = "00000000";
    };
    Account(string AccountNo, string ACHolderName, string Mobile) {
        this->AccountNo = AccountNo;
        this->ACHolderName = ACHolderName;
        this->Balance = Balance;
        this->Mobile = Mobile;
    };
};

class SavingsAccount : public Account {
   protected:
    double MaxLimit;
    double MinimumBalance;

   public:
    SavingsAccount(string AccountNo, string ACHolderName, string Mobile) : Account(AccountNo, ACHolderName, Mobile) {
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
    double WithdrawLimit;
    double MinimumActiveBalance;
    char AccountCategory;

   public:
    CurrentAccount(string AccountNo, string ACHolderName, string Mobile) : Account(AccountNo, ACHolderName, Mobile) {
        this->WithdrawLimit = 1000;
        this->MinimumActiveBalance = 40;
        this->AccountCategory = 'c';
    }
    char getAccountCategory() {
        return this->AccountCategory;
    }
    void setAccountCategory(char AccountCategory) {
        this->AccountCategory = AccountCategory;
    }

    double getMinimumActiveBalance() {
        return this->MinimumActiveBalance;
    }
    void setMinimumActiveBalance(double MinimumActiveBalance) {
        this->MinimumActiveBalance = MinimumActiveBalance;
    }
    double getWithdrawLimit() {
        return this->WithdrawLimit;
    }
    void setWithdrawLimit(double WithdrawLimit) {
        this->WithdrawLimit = WithdrawLimit;
    }
};

class FixedDeposit : protected Account {
   private:
    void* FDAccount;
    char AccountType;
    string FDNumber;
    double InitialAmount;
    double IntrestRate;

   public:
    // Constructors
    FixedDeposit() {
        this->FDAccount = NULL;
        this->AccountType = 0;
        this->FDNumber = "";
        this->InitialAmount = 0;
        this->IntrestRate = 0;
    }
    FixedDeposit(void* account, char ACType, string FDNumber, double InitialAmount, double IntrestRate) {
        this->FDAccount = FDAccount;
        this->AccountType = AccountType;
        this->FDNumber = FDNumber;
        this->InitialAmount = InitialAmount;
        this->IntrestRate = IntrestRate;
    }

    // Getters & Setters
    double getIntrestRate() {
        return this->IntrestRate;
    }
    void setIntrestRate(double IntrestRate) {
        this->IntrestRate = IntrestRate;
    }
    double getInitialAmount() {
        return this->InitialAmount;
    }
    void setInitialAmount(double InitialAmount) {
        this->InitialAmount = InitialAmount;
    }

    string getFDNumber() {
        return this->FDNumber;
    }
    void setFDNumber(string FDNumber) {
        this->FDNumber = FDNumber;
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
    vector<FixedDeposit> FixedDeposits;

   public:
    void AddSavingsAccount(string AccountNo, string ACHolderName, string Mobile) {
        SavingsAccount AC(AccountNo, ACHolderName, Mobile);
        this->SavingsAccounts.push_back(AC);
    }
    void AddCurrentAccount(string AccountNo, string ACHolderName, string Mobile) {
        CurrentAccount AC(AccountNo, ACHolderName, Mobile);
        this->CurrentAccounts.push_back(AC);
    }
    void AddFixedDeposit(string AccountNo, string FDID, double InitialAmount, double IntrestRate) {
        void* account = NULL;
        for (int i = 0; i < this->SavingsAccounts.size(); i++) {
            if (AccountNo.compare(this->SavingsAccounts[i].getAccountNo()) == 0) {
                account = &(this->SavingsAccounts[i]);
            }
        }
        for (int i = 0; i < this->CurrentAccounts.size(); i++) {
            if (AccountNo.compare(this->CurrentAccounts[i].getAccountNo()) == 0) {
                account = &(this->CurrentAccounts[i]);
            }
        }
        if (account == NULL) {
            cout << "Account Not Found!\n";
            return;
        }
        FixedDeposit FD(account, 'A', FDID, InitialAmount, IntrestRate);
        this->FixedDeposits.push_back(FD);
    }
    // Constructor
    Bank() {
        this->Name = "";
        this->Branch = "";
        this->IFSC = "";
        this->AccountCount = 0;
        this->SavingsAccounts = vector<SavingsAccount>();
        this->CurrentAccounts = vector<CurrentAccount>();
        this->FixedDeposits = vector<FixedDeposit>();
    }

    Bank(string Name, string Branch, string IFSC) {
        this->Name = Name;
        this->Branch = Branch;
        this->IFSC = IFSC;
        this->AccountCount = 0;
        this->SavingsAccounts = vector<SavingsAccount>();
        this->CurrentAccounts = vector<CurrentAccount>();
        this->FixedDeposits = vector<FixedDeposit>();
    }
    int getAccountCount() {
        return this->AccountCount;
    }
    void setAccountCount(int AccountCount) {
        this->AccountCount = AccountCount;
    }
    // Getters & Setters
    vector<FixedDeposit> getFixedDeposits() {
        return this->FixedDeposits;
    }
    void setFixedDeposits(vector<FixedDeposit> FixedDeposits) {
        this->FixedDeposits = FixedDeposits;
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

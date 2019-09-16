class accounts{
    class Customer {
    private:
        char name[100];
        int age;
        char address[250];
        char aadhaar_no[17];

    public:
        Customer(char *customer_name, int customer_age, char *customer_address, char *customer_aadhaar_no) {
            strcpy(name, customer_name);
            age = customer_age;
            strcpy(address, customer_address);
            strcpy(aadhaar_no, customer_aadhaar_no);
        }
        char* get_name(){
            return name;
        }
        int get_age(){
            return age;
        }
        char* get_address(){
            return address;
        }
        char* get_aadhaar_no(){
            return aadhaar_no;
        }

        char* set_name(char *customer_name){
            strcpy(name, customer_name);
        }
        int set_age(int customer_age){
            age = customer_age;
        }
        char* set_address(char *customer_address){
            strcpy(address, customer_address);
        }
        char* set_aadhaar_no(char *customer_aadhaar_no){
            strcpy(aadhaar_no, customer_aadhaar_no);
        }
    };



    class BankAccount {
    private:
        int account_no;
        Customer *customer;
        double balance;
        char password[41];
        bool logged_in;

    public:
        BankAccount(int custommer_account_no, Customer *customer_detail) {
            account_no = custommer_account_no;
            strcpy(password, "PassWord");
            customer = customer_detail;
            balance = 0;
        }

        void log_in(char *customer_password){
            if(strcmp(password, customer_password) == 0){
                logged_in = true;
            }
        }

        void log_out(){
            logged_in = false;
        }

        double checkBalance(){
            if (logged_in){
                System.out.println("Current Balance: ", balance, "\n");
                return balance;
            }
            else {
                System.out.println("Not Logged in!\n");
                return 0;
            }
        }

        void deposit(double amount){
            if (logged_in){
                balance += amount;
                System.out.println("Current Balance: ", balance, "\n");

            }
            else {
                System.out.println("Not Logged in!\n");
            }
        }

        void widthdraw(double amount){
            if (logged_in){
                balance -= amount;
                System.out.println("Current Balance: ",balance,"\n");
            }
            else {
                System.out.println("Not Logged in!\n");
            }
        }

    };


    class Bank {
    private:
        char name[50];
        long no_of_accounts;
        
    public:
        Bank(char *bank_name) {
            strcpy(name, bank_name);
            no_of_accounts = 0;
        }

        BankAccount* createAccount(Customer customer){
            int account_no = generateBankAccountNo();
            return new BankAccount(account_no, &customer);
        }

        int generateBankAccountNo(){
            return ++no_of_accounts;
        }

        double calculateIntrest(BankAccount account, int time, double rate){
            account.log_in("PassWord");
            double balance = account.checkBalance();
            account.log_out();
            double intrest = (balance * rate * time) / 100;
            return intrest;
        }

    };

    class ATM {
    private:
        int id;
    public:
        ATM(int atm_id = 1){
            id = atm_id;
        };

        double checkBalance(BankAccount account, char *password){
            account.log_in(password);
            account.checkBalance();
            account.log_out();
        }

        void widthdraw(BankAccount account, char *password, double amount){
            account.log_in(password);
            account.widthdraw(amount);
            account.log_out();
        }
    };




    public static void main(int argc, char const *argv[])
    {
        Bank SBI("State Bank of India");
        ATM ATM1(1);

        Customer C1("Ashutosh Chauhan", 20, "Amroha", "919297361631");
        Customer C2("Palaash Agarwal", 29, "Agra", "919293361631");
        Customer C3("Raahul Singh", 21, "Dehradun", "919227361631");

        BankAccount *myAccount1 = SBI.createAccount(C1);
        BankAccount *myAccount2 = SBI.createAccount(C2);

        System.out.println("-----USING BANK ACCOUNT---------\n");

        System.out.println("Without Logging In: \n\n");

        myAccount1->deposit(10000);
        myAccount1->widthdraw(50);

        myAccount1->log_in("PassWord");
        System.out.println("\nAfter Logging In: \n\n");

        myAccount1->deposit(10000);
        myAccount1->widthdraw(50);

        myAccount1->log_out();

        System.out.println("\nAfter Logging Out: \n\n");

        myAccount1->deposit(10000);
        myAccount1->widthdraw(50);
        
        System.out.println("--------------------------------------\n\n");

        System.out.println("----------USING ATM-WRONG PASSWORD--------\n\n");

        ATM1.checkBalance(*myAccount1, "Password");
        ATM1.widthdraw(*myAccount1, "Password", 400);    

        System.out.println("\n--------USING ATM-CORRECT-PASSWORD--------\n\n");


        ATM1.checkBalance(*myAccount1, "PassWord");
        ATM1.widthdraw(*myAccount1, "PassWord", 100);    

        System.out.println("-----------------------------\n");
    }
}
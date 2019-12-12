#include <bits/stdc++.h>
#include <mysql-cppconn-8/jdbc/cppconn/driver.h>
#include <mysql-cppconn-8/jdbc/mysql_connection.h>
#include <mysql-cppconn-8/jdbc/mysql_driver.h>
#include <mysql-cppconn-8/mysql/jdbc.h>
#include <boost/scoped_ptr.hpp>
#define DEFAULT_URI "tcp://127.0.0.1"
#define USER "root"
#define PASS "A12b14CN"
#define DB "test"

using namespace std;

class Employee {
    string name;
    double base_pay;
    int hours_worked;

   public:
    int gethours_worked() {
        return this->hours_worked;
    }
    void sethours_worked(int hours_worked) {
        this->hours_worked = hours_worked;
    }
    double getbase_pay() {
        return this->base_pay;
    }
    void setbase_pay(double base_pay) {
        this->base_pay = base_pay;
    }
    string getname() {
        return this->name;
    }
    void setname(string name) {
        this->name = name;
    }
}

class Company {
   private:
    int min_work_time;             // In hours
    float overtime;                // In Percent
    int max_work_time;             // In Hours
    double minimum_wage;           // In Rupees per Hour
    double highest_pay;            // In Rupees
    float diwali_bonus;            // In Percentage
    double diwali_bonus_criteria;  // In Percentage

   public:
    Company() {
        this->min_work_time = 40;
        this->overtime = 50;
        this->max_work_time = 60;
        this->minimum_wage = 400;
    }

    Company(int min_work_time,
            float overtime,
            int max_work_time,
            double minimum_wage,
            float diwali_bonus,
            double diwali_bonus_criteria) {
        this->min_work_time = ((min_work_time <= 40) ? min_work_time : 40);
        this->overtime = ((overtime >= 50) ? overtime : 50);
        this->max_work_time = ((max_work_time <= 60) ? max_work_time : 60);
        this->minimum_wage = ((minimum_wage >= 400) ? minimum_wage : 400);
        this->diwali_bonus = diwali_bonus;
        this->diwali_bonus_criteria = diwali_bonus_criteria;
    }
    double get_diwali_bonus_criteria() { return this->diwali_bonus_criteria; }

    void set_diwali_bonus_criteria(double diwali_bonus_criteria) {
        this->diwali_bonus_criteria = diwali_bonus_criteria;
    }

    double get_minimum_wage() { return this->minimum_wage; }

    float get_diwali_bonus() { return this->diwali_bonus; }

    double get_highest_pay() { return this->highest_pay; }

    int get_max_work_time() { return this->max_work_time; }

    int get_min_work_time() { return this->min_work_time; }

    float get_overtime() { return this->overtime; }

    void set_overtime(float overtime) { this->overtime = overtime; }

    void set_diwali_bonus(float diwali_bonus) {
        this->diwali_bonus = diwali_bonus;
    }

    void set_highest_pay(double highest_pay) {
        this->highest_pay = highest_pay;
    }

    void set_minimum_wage(double minimum_wage) {
        this->minimum_wage = minimum_wage;
    }

    void set_max_work_time(int max_work_time) {
        this->max_work_time = max_work_time;
    }

    void set_min_work_time(int min_work_time) {
        this->min_work_time = min_work_time;
    }

    bool verify_data(double base_pay, int hours_worked) {
        return (base_pay > this->minimum_wage && hours_worked <= max_work_time);
    }

    double calculate_overtime(double base_pay, int hours_worked) {
        if (hours_worked >= min_work_time && hours_worked <= max_work_time) {
            return min_work_time * base_pay +
                   (hours_worked - min_work_time) *
                       (base_pay * (100 + this->overtime) / 100);
        }
        return 0;
    }

    double calculate_diwali_bonus(double base_pay, int hours_worked) {
        if (base_pay <=
            ((100 - diwali_bonus_criteria) / 100) * this->highest_pay) {
            if (hours_worked >= min_work_time &&
                hours_worked <= max_work_time) {
                return (hours_worked * (100 + this->diwali_bonus) * base_pay / 100);
            }
        }
        return 0;
    }
};

int main(int argc, char const* argv[]) {
    Company ABCompany(40, 50, 60, 400, 20, 30);

    const char* url = (argc > 1 ? argv[1] : DEFAULT_URI);
    const string user(argc >= 3 ? argv[2] : USER);
    const string pass(argc >= 4 ? argv[3] : PASS);
    const string database(argc >= 5 ? argv[4] : DB);
    try {
        sql::Driver* driver = sql::mysql::get_driver_instance();
        /* Using the Driver to create a connection */
        cout << "Creating to MySQL Server on " << url << " ..." << endl
             << endl;
        boost::scoped_ptr<sql::Connection> con(
            driver->connect(url, user, pass));
        con->setSchema(database);
        boost::scoped_ptr<sql::Statement> stmt(con->createStatement());
        boost::scoped_ptr<sql::ResultSet> res(stmt->executeQuery(
            "SELECT max(base_pay) as highest_pay from employee;"));
        res->next();
        ABCompany.set_highest_pay(res->getDouble("highest_pay"));
        res->close();
        int choice = 1;
        while (choice) {
            cout << "\nEnter 1 to show data\n";
            cout << "Enter 2 to calculate Overtime/\n";
            cout << "Enter 3 to calculate Diwali bonus/\n";
            cout << "Enter 0 to exit.\n";
            cin >> choice;
            system("clear");
            if (choice == 1) {
                boost::scoped_ptr<sql::ResultSet> response(
                    stmt->executeQuery("SELECT * FROM employee;"));
                cout << "Employee name" << '\t' << "employee_id" << '\t'
                     << "address"
                     << "\t\t"
                     << "designation" << '\t' << "base_pay" << '\t'
                     << "hours_worker" << endl;
                while (response->next()) {
                    double base_pay = response->getDouble("base_pay");
                    int hours_worked = response->getInt("hours_worked");
                    cout << response->getString("employee_name") << "\t\t";
                    if (!ABCompany.verify_data(base_pay, hours_worked)) {
                        cout << " Error: Either Base Pay is less than "
                             << ABCompany.get_minimum_wage()
                             << " or hours worked more than "
                             << ABCompany.get_max_work_time() << ".\n";
                    } else {
                        cout << response->getInt("employee_id") << "\t\t"
                             << response->getString("address") << "\t\t"
                             << response->getString("designation") << "\t\t"
                             << base_pay << "\t\t" << hours_worked << endl;
                    }
                }
            }
            if (choice == 2) {
                boost::scoped_ptr<sql::ResultSet> response(
                    stmt->executeQuery("SELECT * FROM employee;"));
                cout << "Employee name" << '\t' << "Overtime" << '\t' << endl;
                while (response->next()) {
                    double base_pay = response->getDouble("base_pay");
                    int hours_worked = response->getInt("hours_worked");
                    cout << response->getString("employee_name");
                    if (!ABCompany.verify_data(base_pay, hours_worked)) {
                        cout << " Error: Either Base Pay is less than "
                             << ABCompany.get_minimum_wage()
                             << " or hours worked more than "
                             << ABCompany.get_max_work_time() << ".\n";
                    } else {
                        cout << "\t\t"
                             << ABCompany.calculate_overtime(base_pay,
                                                             hours_worked)
                             << endl;
                    }
                }
            }
            if (choice == 3) {
                boost::scoped_ptr<sql::ResultSet> response(
                    stmt->executeQuery("SELECT * FROM employee;"));
                cout << "Employee name" << '\t' << "Diwali Bonus" << '\t'
                     << endl;
                while (response->next()) {
                    double base_pay = response->getDouble("base_pay");
                    int hours_worked = response->getInt("hours_worked");
                    cout << response->getString("employee_name");
                    if (!ABCompany.verify_data(base_pay, hours_worked)) {
                        cout << " Error: Either Base Pay is less than "
                             << ABCompany.get_minimum_wage()
                             << " or hours worked more than "
                             << ABCompany.get_max_work_time() << ".\n";
                    } else {
                        cout << "\t\t"
                             << ABCompany.calculate_diwali_bonus(base_pay,
                                                                 hours_worked)
                             << endl;
                    }
                }
            }
        }

    } catch (sql::SQLException& e) {
        /*
          The JDBC API throws three different exceptions:
        - sql::MethodNotImplementedException (derived from sql::SQLException)
        - sql::InvalidArgumentException (derived from sql::SQLException)
        - sql::SQLException (derived from std::runtime_error)
        */
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "("
             << "EXAMPLE_FUNCTION"
             << ") on line " << __LINE__ << endl;
        /* Use what() (derived from std::runtime_error) to fetch the error
         * message */
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        return EXIT_FAILURE;
    }
    cout << endl;
    return EXIT_SUCCESS;
    return 0;
}

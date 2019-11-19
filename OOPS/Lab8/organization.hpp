#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Date {
    int day, month, year;
};

class Person {
   protected:
    string firstName;
    string lastName;
    Date dateOfBirth;
    string mobile;

   public:
    string getmobile() {
        return this->mobile;
    }
    void setmobile(string mobile) {
        this->mobile = mobile;
    }
    Date getdateOfBirth() {
        return this->dateOfBirth;
    }
    void setdateOfBirth(Date dateOfBirth) {
        this->dateOfBirth = dateOfBirth;
    }
    string getlastName() {
        return this->lastName;
    }
    void setlastName(string lastName) {
        this->lastName = lastName;
    }
    string getfirstName() {
        return this->firstName;
    }
    string getName() {
        return this->firstName + ' ' + this->lastName;
    }
    void setfirstName(string firstName) {
        this->firstName = firstName;
    }
    // Constructor
    Person() {
        this->firstName = "";
        this->lastName = "";
        this->dateOfBirth = {1, 1, 2000};
        this->mobile = "0000000000";
    }
    Person(string firstName, string lastName, int day, int month, int year, string mobile) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->mobile = mobile;
        this->dateOfBirth = {day, month, year};
    }
};

class Employee : public Person {
   protected:
    string position;
    string type;  // Extra Information about position
   public:
    string getposition() {
        return this->position;
    }
    void setposition(string position) {
        this->position = position;
    }
    string gettype() {
        return this->type;
    }
    void settype(string type) {
        this->type = type;
    }
    Employee() : Person() {
        this->position = "";
        this->type = "";
    }
    Employee(string firstName, string lastName, int day, int month, int year, string mobile, string position, string type) : Person(firstName, lastName, day, month, year, mobile) {
        this->position = position;
        this->type = type;
    }
};

class Manager : public Employee {
   public:
    Manager() : Employee() {
        this->position = "Manager";
        this->type = "";
    }
    Manager(string firstName, string lastName, int day, int month, int year, string mobile, string type) : Employee(firstName, lastName, day, month, year, mobile, "Manager", type) {
    }
};

class VP : public Employee {
   public:
    VP() : Employee() {
        this->position = "VP";
        this->type = "";
    }
    VP(string firstName, string lastName, int day, int month, int year, string mobile, string type) : Employee(firstName, lastName, day, month, year, mobile, "VP", type) {
    }
};

class CEO : public Person {
   public:
    CEO() : Person() {
    }
    CEO(string firstName, string lastName, int day, int month, int year, string mobile) : Person(firstName, lastName, day, month, year, mobile) {
    }
};

class Department {
   private:
    string name;
    vector<Employee> employees;
    Manager manager;

   public:
    Manager getmanager() {
        return this->manager;
    }
    void setmanager(Manager manager) {
        this->manager = manager;
    }
    vector<Employee> getemployees() {
        return this->employees;
    }
    void setemployees(vector<Employee> employees) {
        this->employees = employees;
    }
    string getname() {
        return this->name;
    }
    void setname(string name) {
        this->name = name;
    }
    Department() {
        this->name = "";
        this->employees = vector<Employee>();
        this->manager = Manager();
    }
    Department(string name, Manager manager) {
        this->name = name;
        this->employees = vector<Employee>();
        this->manager = manager;
    }
    void AddEmployee(Employee employee) {
        this->employees.push_back(employee);
    }
};

class Organisation {
   private:
    string name;
    CEO ceo;
    vector<Department> departments;
    Manager manager;
    VP vp;

   public:
    VP getvp() {
        return this->vp;
    }
    void setvp(VP vp) {
        this->vp = vp;
    }
    Manager getmanager() {
        return this->manager;
    }
    void setmanager(Manager manager) {
        this->manager = manager;
    }
    vector<Department> getDepartments() {
        return this->departments;
    }
    void setDepartments(vector<Department> departments) {
        this->departments = departments;
    }
    CEO getCEO() {
        return this->ceo;
    }
    void setCEO(CEO ceo) {
        this->ceo = ceo;
    }
    string getName() {
        return this->name;
    }
    void setName(string name) {
        this->name = name;
    }
    Organisation() {
        this->name = "";
        this->ceo = CEO();
        this->manager = Manager();
        this->vp = VP();
    }
    Organisation(string name, CEO ceo, Manager manager, VP vp) {
        this->name = name;
        this->ceo = ceo;
        this->manager = manager;
        this->vp = vp;
    }
    void AddDepartment(Department department) {
        this->departments.push_back(department);
    }
    void print() {
        cout << "Organization Name: " << this->name << endl;
        cout << "Organization CEO: " << this->ceo.getName() << endl;
        cout << "General Manager: " << this->manager.getName() << endl;
        cout << "Vice President: " << this->vp.getName() << endl;
        cout << "-----------------------------------------\n";
        for (int i = 0; i < this->departments.size(); i++) {
            cout << "Department Name: " << this->departments[i].getname() << endl;
            cout << "-----------------------------------------\n";
            cout << this->departments[i].getname() << " Manager: " << this->departments[i].getmanager().getName() << endl;
            cout << "-----------------------------------------\n";
            cout << "Employees: \n";
            for (int j = 0; j < this->departments[i].getemployees().size(); j++) {
                cout << '\t' << this->departments[i].getemployees()[j].getName() << endl;
            }
            cout << "-----------------------------------------\n\n";
        }
    }
};

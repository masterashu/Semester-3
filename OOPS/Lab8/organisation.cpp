#include <iostream>
#include <string>
#include <vector>
#include "organization.hpp"


int main(){
    CEO ceo("Satya", "Nadella", 10, 4, 1979, "1234567890");
    Manager manager("Agnes", "Mirage", 10, 3, 1984, "01929837465", "Genearal");
    VP vp("Palaash", "Train", 10, 3, 1984, "01929837465", "");    
    Organisation Microsoft("Microsoft", ceo, manager, vp);
    Manager SWEnggManager("Nathan", "Dust Jr.", 10, 3, 1984, "01929837465", "SW Manager");

    Department SWEngg("SW Engineer", SWEnggManager);
    Employee emp01("Employee", "01", 10, 10, 2000, string("1234546"), SWEngg.getname(), "General");
    Employee emp02("Employee", "02", 10, 10, 2000, string("1234546"), SWEngg.getname(), "General");
    Employee emp03("Employee", "03", 10, 10, 2000, string("1234546"), SWEngg.getname(), "General");
    Employee emp04("Employee", "04", 10, 10, 2000, string("1234546"), SWEngg.getname(), "General");
    SWEngg.AddEmployee(emp01);
    SWEngg.AddEmployee(emp02);
    SWEngg.AddEmployee(emp03);
    SWEngg.AddEmployee(emp04);
    Microsoft.AddDepartment(SWEngg);

    Department HWDesign = Microsoft.getDepartments();
    Manager HWDesignManager("Tracy", "Cache", 10, 3, 1984, "01929837465", "HWDesign Manager");
    Employee emp11("Employee", "11", 10, 10, 2000, string("1234546"), SWEngg.getname(), "Fabric");
    Employee emp12("Employee", "12", 10, 10, 2000, string("1234546"), SWEngg.getname(), "Fabric");
    Employee emp13("Employee", "13", 10, 10, 2000, string("1234546"), SWEngg.getname(), "Design");
    Employee emp14("Employee", "14", 10, 10, 2000, string("1234546"), SWEngg.getname(), "Design");
    HWDesign.AddEmployee(emp11);
    HWDesign.AddEmployee(emp12);
    HWDesign.AddEmployee(emp13);
    HWDesign.AddEmployee(emp14);

    Manager FinanceManager("John", "Cobblestone", 10, 3, 1984, "01929837465", "Finance Manager");
    Department Finance("Finance", FinanceManager);
    Employee emp21("Employee", "21", 10, 10, 2000, string("1234546"), SWEngg.getname(), "General");
    Employee emp22("Employee", "22", 10, 10, 2000, string("1234546"), SWEngg.getname(), "General");
    Employee emp23("Employee", "23", 10, 10, 2000, string("1234546"), SWEngg.getname(), "General");
    Employee emp24("Employee", "24", 10, 10, 2000, string("1234546"), SWEngg.getname(), "General");
    Finance.AddEmployee(emp21);
    Finance.AddEmployee(emp22);
    Finance.AddEmployee(emp23);
    Finance.AddEmployee(emp24);
    Microsoft.AddDepartment(Finance);

    Manager HRManager("Rodricco", "Inferno", 10, 3, 1984, "01929837465", "HR Head");
    Department HR("Human Resources", HRManager);
    Employee emp31("Employee", "31", 10, 10, 2000, string("1234546"), SWEngg.getname(), "General");
    Employee emp32("Employee", "32", 10, 10, 2000, string("1234546"), SWEngg.getname(), "General");
    Employee emp33("Employee", "33", 10, 10, 2000, string("1234546"), SWEngg.getname(), "General");
    Employee emp34("Employee", "34", 10, 10, 2000, string("1234546"), SWEngg.getname(), "General");
    HR.AddEmployee(emp31);
    HR.AddEmployee(emp32);
    HR.AddEmployee(emp33);
    HR.AddEmployee(emp34);
    Microsoft.AddDepartment(HR);

    // Print Organisation
    Microsoft.print();
}

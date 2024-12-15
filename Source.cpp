#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
public:
    void getname(string n) {
        name = n;
    }
    void setId(int employeeId) {
        id = employeeId;
    }
    void displayInfo() {
        cout << "Name: " << name << "\nID: " << id << endl;
    }
    // virtual function for the salary calculations in derived classes
    virtual double calculatesalary() = 0;
};

class Manager : public Employee {
private:
    double baseSalary;
    float bonus;
public:
    Manager(double salary, float b) {
        baseSalary = salary;
        bonus = b;
    }
    // Calculating salary for Manager including the bonus
    double calculatesalary() override {
        return baseSalary + bonus;
    }
};

class Developer : public Employee {
private:
    double baseSalary;
    int overtimeHours;
    float hourlyRate;
public:
    Developer(double salary, int overtime, float rate) {
        baseSalary = salary;
        overtimeHours = overtime;
        hourlyRate = rate;
    }
    // Calculating salary for Developer including overtime pay
    double calculatesalary() override {
        return baseSalary + (overtimeHours * hourlyRate);
    }
};

class Intern : public Employee {
private:
    float comp;
public:
    Intern(float s) {
        comp = s;
    }
    // Calculating salary for Intern
    double calculatesalary() override {
        return comp;
    }
};

int main() {
    Employee* employees[3]; // Array of pointers to Employee
    // Input for Manager
    string name;
    int id;
    double managerSalary, managerBonus;
    cout << "Enter Manager's Name: ";
    getline(cin, name);
    cout << "Enter Manager's ID: ";
    cin >> id;
    cout << "Enter Manager's Base Salary: ";
    cin >> managerSalary;
    cout << "Enter Manager's Bonus: ";
    cin >> managerBonus;
    cin.ignore();

    Manager manager(managerSalary, managerBonus);
    employees[0] = &manager; // Assign the address of the manager object
    employees[0]->getname(name);
    employees[0]->setId(id);
    // Input for Developer
    double developerSalary;
    int overtimeHours;
    float hourlyRate;
    cout << "Enter Developer's Name: ";
    getline(cin, name);
    cout << "Enter Developer's ID: ";
    cin >> id;
    cout << "Enter Developer's Base Salary: ";
    cin >> developerSalary;
    cout << "Enter Developer's Overtime Hours: ";
    cin >> overtimeHours;
    cout << "Enter Developer's Hourly Rate for Overtime: ";
    cin >> hourlyRate;
    cin.ignore(); 
    Developer developer(developerSalary, overtimeHours, hourlyRate);
    employees[1] = &developer; // Assign the address of the developer object
    employees[1]->getname(name);
    employees[1]->setId(id);
    // Input for Intern
    float comp;
    cout << "Enter Intern's Name: ";
    getline(cin, name);
    cout << "Enter Intern's ID: ";
    cin >> id;
    cout << "Enter Intern's Compensation: ";
    cin >> comp;
    cin.ignore(); 
    Intern intern(comp);
    employees[2] = &intern; // Assign the address of the intern object
    employees[2]->getname(name);
    employees[2]->setId(id);
    // Displaying details and calculated salaries
    cout << "\nEmployee Details and Salaries:\n";
    for (int i = 0; i < 3; i++) {
        cout << endl;
        employees[i]->displayInfo();
        cout << "Calculated Salary: " << employees[i]->calculatesalary() << endl;
    }
    return 0;
}
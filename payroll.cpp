#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Employee {
private:
    int code;
    string name;
    string address;
    string phone;
    string designation;
    char grade;
    double basicSalary;
    double houseAllowance;
    double loan;
    
public:
    Employee() {
        code = 0;
        grade = 'A';
        basicSalary = 0;
        houseAllowance = 0;
        loan = 0;
    }

    void addEmployee() {
        cout << "\nEnter Employee Code: ";
        cin >> code;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Designation: ";
        getline(cin, designation);
        cout << "Enter Grade (A/B/C/D/E): ";
        cin >> grade;
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        cout << "Enter House Allowance: ";
        cin >> houseAllowance;
        cout << "Enter Loan (if any): ";
        cin >> loan;
    }

    void displayEmployee() {
        cout << "\nEmployee Details:" << endl;
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Designation: " << designation << endl;
        cout << "Grade: " << grade << endl;
        cout << "Basic Salary: $" << basicSalary << endl;
        cout << "House Allowance: $" << houseAllowance << endl;
        cout << "Loan: $" << loan << endl;
    }

    void generateSalarySlip() {
        int daysWorked, overtimeHours;
        cout << "\nEnter Days Worked: ";
        cin >> daysWorked;
        cout << "Enter Overtime Hours: ";
        cin >> overtimeHours;

        double overtimeRate = 100.0;  // $100 per overtime hour
        double overtimePay = overtimeHours * overtimeRate;
        double grossSalary = basicSalary + houseAllowance + overtimePay;
        double deductions = loan;
        double netSalary = grossSalary - deductions;

        cout << "\n========= SALARY SLIP =========" << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Grade: " << grade << endl;
        cout << "Days Worked: " << daysWorked << endl;
        cout << "Basic Salary: $" << basicSalary << endl;
        cout << "House Allowance: $" << houseAllowance << endl;
        cout << "Overtime Pay: $" << overtimePay << endl;
        cout << "Gross Salary: $" << grossSalary << endl;
        cout << "Loan Deduction: $" << deductions << endl;
        cout << "Net Salary: $" << netSalary << endl;
        cout << "=============================" << endl;
    }

    int getCode() { return code; }
    string getName() { return name; }  // Added getName() function
    void editEmployee();
};

void Employee::editEmployee() {
    cout << "\nEditing Employee: " << name << endl;
    cout << "Enter new details:" << endl;
    
    cin.ignore();
    cout << "Enter Name (current: " << name << "): ";
    getline(cin, name);
    cout << "Enter Address (current: " << address << "): ";
    getline(cin, address);
    cout << "Enter Phone (current: " << phone << "): ";
    getline(cin, phone);
    cout << "Enter Designation (current: " << designation << "): ";
    getline(cin, designation);
    cout << "Enter Grade (current: " << grade << "): ";
    cin >> grade;
    cout << "Enter Basic Salary (current: " << basicSalary << "): ";
    cin >> basicSalary;
    cout << "Enter House Allowance (current: " << houseAllowance << "): ";
    cin >> houseAllowance;
    cout << "Enter Loan (current: " << loan << "): ";
    cin >> loan;
}

class PayrollSystem {
private:
    vector<Employee> employees;

public:
    void addNewEmployee() {
        Employee emp;
        emp.addEmployee();
        employees.push_back(emp);
        cout << "\nEmployee added successfully!" << endl;
    }

    void displayEmployee() {
        int code;
        cout << "\nEnter Employee Code: ";
        cin >> code;

        for (Employee& emp : employees) {
            if (emp.getCode() == code) {
                emp.displayEmployee();
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }

    void listEmployees() {
        if (employees.empty()) {
            cout << "\nNo employees in the system." << endl;
            return;
        }

        cout << "\nList of All Employees:" << endl;
        cout << setw(5) << "Code" << setw(20) << "Name" << endl;
        cout << "------------------------" << endl;
        
        for (Employee& emp : employees) {
            cout << setw(5) << emp.getCode() << setw(20) << emp.getName() << endl;  // Fixed: Added emp.getName()
        }
    }

    void generateSalarySlip() {
        int code;
        cout << "\nEnter Employee Code: ";
        cin >> code;

        for (Employee& emp : employees) {
            if (emp.getCode() == code) {
                emp.generateSalarySlip();
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }

    void editEmployeeDetails() {
        int code;
        cout << "\nEnter Employee Code to Edit: ";
        cin >> code;

        for (Employee& emp : employees) {
            if (emp.getCode() == code) {
                emp.editEmployee();
                cout << "Employee details updated successfully!" << endl;
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }
};

int main() {
    PayrollSystem payroll;
    int choice;

    do {
        cout << "\n=== Payroll Management System ===" << endl;
        cout << "1: NEW EMPLOYEE" << endl;
        cout << "2: DISPLAY EMPLOYEE" << endl;
        cout << "3: LIST OF EMPLOYEES" << endl;
        cout << "4: SALARY SLIP" << endl;
        cout << "5: EDIT" << endl;
        cout << "0: QUIT" << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                payroll.addNewEmployee();
                break;
            case 2:
                payroll.displayEmployee();
                break;
            case 3:
                payroll.listEmployees();
                break;
            case 4:
                payroll.generateSalarySlip();
                break;
            case 5:
                payroll.editEmployeeDetails();
                break;
            case 0:
                cout << "Thank you for using the system!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
} 
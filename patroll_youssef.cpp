#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Employee {
private:
    struct Details {
        int code = 0;
        string name, address, phone, designation;
        char grade = 'A';
        double basicSalary = 0.0, houseAllowance = 0.0, loan = 0.0;
    } data;

public:
    Employee() = default;

    void inputDetails() {
        cout << "Employee Code: ";
        cin >> data.code;
        cin.ignore();
        cout << "Name: ";
        getline(cin, data.name);
        cout << "Address: ";
        getline(cin, data.address);
        cout << "Phone Number: ";
        getline(cin, data.phone);
        cout << "Job Title: ";
        getline(cin, data.designation);
        cout << "Employee Grade (A/B/C/D/E): ";
        cin >> data.grade;
        cout << "Salary Base: ";
        cin >> data.basicSalary;
        cout << "Allowance for Housing: ";
        cin >> data.houseAllowance;
        cout << "Current Loans: ";
        cin >> data.loan;
    }

    void outputDetails() const {
        cout << "\n--- Employee Information ---" << endl;
        cout << "ID: " << data.code << endl;
        cout << "Full Name: " << data.name << endl;
        cout << "Residential Address: " << data.address << endl;
        cout << "Contact No.: " << data.phone << endl;
        cout << "Current Position: " << data.designation << endl;
        cout << "Classification: " << data.grade << endl;
        cout << "Base Pay: $" << data.basicSalary << endl;
        cout << "Housing Funds: $" << data.houseAllowance << endl;
        cout << "Outstanding Loans: $" << data.loan << endl;
    }

    void createSalarySlip() const {
        int daysWorked, overtimeHours;
        cout << "Days Worked This Period: ";
        cin >> daysWorked;
        cout << "Overtime Hours Logged: ";
        cin >> overtimeHours;

        double overtimeRate = 100.0;
        double overtimePay = overtimeHours * overtimeRate;
        double grossSalary = data.basicSalary + data.houseAllowance + overtimePay;
        double netSalary = grossSalary - data.loan;

        cout << "\n=== Detailed Salary Slip ===" << endl;
        cout << "Employee: " << data.name << endl;
        cout << "Role: " << data.designation << endl;
        cout << "Tier: " << data.grade << endl;
        cout << "Period Worked: " << daysWorked << endl;
        cout << "Regular Pay: $" << data.basicSalary << endl;
        cout << "Additional Housing: $" << data.houseAllowance << endl;
        cout << "Overtime Compensation: $" << overtimePay << endl;
        cout << "Total Earnings: $" << grossSalary << endl;
        cout << "Deductions (Loans): $" << data.loan << endl;
        cout << "Take-home Pay: $" << netSalary << endl;
        cout << "================================" << endl;
    }

    void updateDetails();
    int getCode() const { return data.code; }
    string getName() const { return data.name; }
};

void Employee::updateDetails() {
    cout << "Updating Record For: " << data.name << endl;
    cout << "New Information Entry:" << endl;

    cin.ignore();
    cout << "New Name (leave blank to retain " << data.name << "): ";
    getline(cin, data.name);
    cout << "New Address (leave blank to retain " << data.address << "): ";
    getline(cin, data.address);
    cout << "New Phone (leave blank to retain " << data.phone << "): ";
    getline(cin, data.phone);
    cout << "New Designation (leave blank to retain " << data.designation << "): ";
    getline(cin, data.designation);
    cout << "New Grade (current: " << data.grade << "): ";
    cin >> data.grade;
    cout << "New Salary Base (current: " << data.basicSalary << "): ";
    cin >> data.basicSalary;
    cout << "New Housing Allowance (current: " << data.houseAllowance << "): ";
    cin >> data.houseAllowance;
    cout << "New Loan Amount (current: " << data.loan << "): ";
    cin >> data.loan;
}

class Payroll {
private:
    vector<Employee> staff;

public:
    void hireEmployee() {
        Employee newHire;
        newHire.inputDetails();
        staff.push_back(newHire);
        cout << "New Employee Registered Successfully!" << endl;
    }

    void showEmployee() const {
        int empCode;
        cout << "Lookup Employee ID: ";
        cin >> empCode;

        for (const auto& emp : staff) {
            if (emp.getCode() == empCode) {
                emp.outputDetails();
                return;
            }
        }
        cout << "No Record Found for Given ID!" << endl;
    }

    void printEmployeeList() const {
        if (staff.empty()) {
            cout << "The Employee Database is Currently Empty." << endl;
            return;
        }

        cout << "Complete Employee Directory:" << endl;
        cout << setw(5) << "ID" << setw(20) << "Employee Name" << endl;
        cout << "-----------------------------------" << endl;
        
        for (const auto& emp : staff) {
            cout << setw(5) << emp.getCode() << setw(20) << emp.getName() << endl;
        }
    }

    void produceSalarySlip() {
        int empCode;
        cout << "Employee ID for Salary Slip: ";
        cin >> empCode;

        for (auto& emp : staff) {
            if (emp.getCode() == empCode) {
                emp.createSalarySlip();
                return;
            }
        }
        cout << "Failed to Locate Employee with Given ID!" << endl;
    }

    void modifyEmployee() {
        int empCode;
        cout << "Employee ID for Record Update: ";
        cin >> empCode;

        for (auto& emp : staff) {
            if (emp.getCode() == empCode) {
                emp.updateDetails();
                cout << "Employee Information Updated Successfully!" << endl;
                return;
            }
        }
        cout << "No Matching Employee Found!" << endl;
    }
};

int main() {
    Payroll payroll;
    int option;

    do {
        cout << "=== Employee Payroll Management System ===" << endl;
        cout << "1: Register New Employee" << endl;
        cout << "2: View Employee Information" << endl;
        cout << "3: Display All Employees" << endl;
        cout << "4: Create Salary Slip" << endl;
        cout << "5: Update Employee Details" << endl;
        cout << "0: Close System" << endl;
        cout << "Please Choose an Option: ";
        cin >> option;

        switch (option) {
            case 1:
                payroll.hireEmployee();
                break;
            case 2:
                payroll.showEmployee();
                break;
            case 3:
                payroll.printEmployeeList();
                break;
            case 4:
                payroll.produceSalarySlip();
                break;
            case 5:
                payroll.modifyEmployee();
                break;
            case 0:
                cout << "System Shutdown Initiated. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid Selection. Try Again." << endl;
        }
    } while (option != 0);

    return 0;
}

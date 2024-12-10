#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Employee {
private:
    struct Info {
        int id = 0;
        string fullName, residentialAddress, contactNumber, role;
        char level = 'A';
        double salaryBase = 0.0, housingBenefit = 0.0, outstandingDebt = 0.0;
    } details;

public:
    Employee() = default;

    void captureData() {
        cout << "Enter Employee ID: ";
        cin >> details.id;
        cin.ignore();
        cout << "Full Name: ";
        getline(cin, details.fullName);
        cout << "Residence Address: ";
        getline(cin, details.residentialAddress);
        cout << "Contact Number: ";
        getline(cin, details.contactNumber);
        cout << "Role: ";
        getline(cin, details.role);
        cout << "Level (A/B/C/D/E): ";
        cin >> details.level;
        cout << "Base Salary: ";
        cin >> details.salaryBase;
        cout << "Housing Benefit: ";
        cin >> details.housingBenefit;
        cout << "Debt Amount: ";
        cin >> details.outstandingDebt;
    }

    void displayInfo() const {
        cout << "\n+++ Employee Record +++" << endl;
        cout << "Employee ID: " << details.id << endl;
        cout << "Name: " << details.fullName << endl;
        cout << "Address: " << details.residentialAddress << endl;
        cout << "Phone: " << details.contactNumber << endl;
        cout << "Position: " << details.role << endl;
        cout << "Classification Level: " << details.level << endl;
        cout << "Salary: $" << details.salaryBase << endl;
        cout << "Housing Allowance: $" << details.housingBenefit << endl;
        cout << "Debt: $" << details.outstandingDebt << endl;
    }

    void prepareSalaryDetails() const {
        int workDays, extraHours;
        cout << "Logged Work Days: ";
        cin >> workDays;
        cout << "Extra Work Hours: ";
        cin >> extraHours;

        double extraRate = 100.0;
        double extraPay = extraHours * extraRate;
        double totalIncome = details.salaryBase + details.housingBenefit + extraPay;
        double finalSalary = totalIncome - details.outstandingDebt;

        cout << "\n--- Detailed Pay Statement ---" << endl;
        cout << "Employee: " << details.fullName << endl;
        cout << "Role: " << details.role << endl;
        cout << "Pay Level: " << details.level << endl;
        cout << "Worked Days: " << workDays << endl;
        cout << "Regular Pay: $" << details.salaryBase << endl;
        cout << "Extra Pay for Overtime: $" << extraPay << endl;
        cout << "Total Pay Before Deductions: $" << totalIncome << endl;
        cout << "Deduction for Debts: $" << details.outstandingDebt << endl;
        cout << "Net Pay After Deductions: $" << finalSalary << endl;
        cout << "===================================" << endl;
    }

    void modifyData();
    int getID() const { return details.id; }
    string getFullName() const { return details.fullName; }
};

void Employee::modifyData() {
    cout << "Modify Record for Employee ID: " << details.id << " - " << details.fullName << endl;
    cout << "Update Data Below (leave blank to keep current value):" << endl;

    cin.ignore();
    cout << "New Full Name: ";
    getline(cin, details.fullName);
    cout << "New Address: ";
    getline(cin, details.residentialAddress);
    cout << "New Phone Number: ";
    getline(cin, details.contactNumber);
    cout << "New Role: ";
    getline(cin, details.role);
    cout << "Level: ";
    cin >> details.level;
    cout << "Base Salary: ";
    cin >> details.salaryBase;
    cout << "Housing Benefit: ";
    cin >> details.housingBenefit;
    cout << "Debt Amount: ";
    cin >> details.outstandingDebt;
}

class HRSystem {
private:
    vector<Employee> roster;

public:
    void enrollEmployee() {
        Employee newEmployee;
        newEmployee.captureData();
        roster.push_back(newEmployee);
        cout << "Employee Successfully Enrolled!" << endl;
    }

    void findEmployee() const {
        int id;
        cout << "Search Employee ID: ";
        cin >> id;

        for (const auto& e : roster) {
            if (e.getID() == id) {
                e.displayInfo();
                return;
            }
        }
        cout << "No Matching Employee Found." << endl;
    }

    void listAllEmployees() const {
        if (roster.empty()) {
            cout << "No Employees Found in the System." << endl;
            return;
        }

        cout << "Employee Roster:" << endl;
        cout << setw(5) << "ID" << setw(25) << "Name" << endl;
        cout << "--------------------------------------" << endl;

        for (const auto& e : roster) {
            cout << setw(5) << e.getID() << setw(25) << e.getFullName() << endl;
        }
    }

    void generatePayStatement() {
        int id;
        cout << "Employee ID for Pay Statement: ";
        cin >> id;

        for (auto& e : roster) {
            if (e.getID() == id) {
                e.prepareSalaryDetails();
                return;
            }
        }
        cout << "Employee Not Found for Given ID." << endl;
    }

    void reviseEmployeeRecord() {
        int id;
        cout << "Enter ID to Revise Employee Record: ";
        cin >> id;

        for (auto& e : roster) {
            if (e.getID() == id) {
                e.modifyData();
                cout << "Employee Record Updated Successfully!" << endl;
                return;
            }
        }
        cout << "Employee Record Not Found." << endl;
    }
};

int main() {
    HRSystem system;
    int choice;

    do {
        cout << "=== HR Management Interface ===" << endl;
        cout << "1: Register Employee" << endl;
        cout << "2: Access Employee Record" << endl;
        cout << "3: Show All Employees" << endl;
        cout << "4: Issue Pay Statement" << endl;
        cout << "5: Edit Employee Data" << endl;
        cout << "0: Exit Program" << endl;
        cout << "Select Operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.enrollEmployee();
                break;
            case 2:
                system.findEmployee();
                break;
            case 3:
                system.listAllEmployees();
                break;
            case 4:
                system.generatePayStatement();
                break;
            case 5:
                system.reviseEmployeeRecord();
                break;
            case 0:
                cout << "Exiting HR System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid Input. Please Choose Again." << endl;
        }
    } while (choice != 0);

    return 0;
}

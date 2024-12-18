#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

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
    Date joiningDate;
    
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
        cout << "Enter Joining Date (DD MM YYYY): ";
        cin >> joiningDate.day >> joiningDate.month >> joiningDate.year;
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
        cout << "Joining Date: " << joiningDate.day << "/" 
             << joiningDate.month << "/" << joiningDate.year << endl;
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

        double overtimeRate = 100.0;  // $100 per hour overtime
        double overtimePay = overtimeHours * overtimeRate;
        double grossSalary = basicSalary + houseAllowance + overtimePay;
        double deductions = loan;
        double netSalary = grossSalary - deductions;

        cout << "\n-------- SALARY SLIP --------" << endl;
        cout << "Employee Code: " << code << endl;
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Days Worked: " << daysWorked << endl;
        cout << "Overtime Hours: " << overtimeHours << endl;
        cout << "\nEarnings:" << endl;
        cout << "Basic Salary: $" << basicSalary << endl;
        cout << "House Allowance: $" << houseAllowance << endl;
        cout << "Overtime Pay: $" << overtimePay << endl;
        cout << "Gross Salary: $" << grossSalary << endl;
        cout << "\nDeductions:" << endl;
        cout << "Loan: $" << loan << endl;
        cout << "\nNet Salary: $" << netSalary << endl;
        cout << "---------------------------" << endl;
    }

    int getCode() { return code; }
    void editEmployee() {
        cin.ignore();
        cout << "\nEnter New Name: ";
        getline(cin, name);
        cout << "Enter New Address: ";
        getline(cin, address);
        cout << "Enter New Phone: ";
        getline(cin, phone);
        cout << "Enter New Designation: ";
        getline(cin, designation);
        cout << "Enter New Joining Date (DD MM YYYY): ";
        cin >> joiningDate.day >> joiningDate.month >> joiningDate.year;
        cout << "Enter New Grade (A/B/C/D/E): ";
        cin >> grade;
        cout << "Enter New Basic Salary: ";
        cin >> basicSalary;
        cout << "Enter New House Allowance: ";
        cin >> houseAllowance;
        cout << "Enter New Loan Amount: ";
        cin >> loan;
    }

    string getName() { return name; }
};

class PayrollSystem {
private:
    vector<Employee> employees;

public:
    void addNewEmployee() {
        Employee emp;
        emp.addEmployee();
        employees.push_back(emp);
        cout << "\nEmployee Added Successfully!" << endl;
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
        cout << "\nEmployee not found!" << endl;
    }

    void listEmployees() {
        if (employees.empty()) {
            cout << "\nNo employees in the system!" << endl;
            return;
        }

        cout << "\nList of All Employees:" << endl;
        cout << setw(10) << "Code" << setw(20) << "Name" << endl;
        cout << "--------------------------------" << endl;
        
        for (Employee& emp : employees) {
            cout << setw(10) << emp.getCode() << setw(20) << emp.getName() << endl;
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
        cout << "\nEmployee not found!" << endl;
    }

    void editEmployeeDetails() {
        int code;
        cout << "\nEnter Employee Code to Edit: ";
        cin >> code;

        for (Employee& emp : employees) {
            if (emp.getCode() == code) {
                emp.editEmployee();
                cout << "\nEmployee Details Updated Successfully!" << endl;
                return;
            }
        }
        cout << "\nEmployee not found!" << endl;
    }

    void deleteEmployee() {
        int code;
        cout << "\nEnter Employee Code to Delete: ";
        cin >> code;

        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->getCode() == code) {
                cout << "\nEmployee Found. Details:" << endl;
                it->displayEmployee();
                
                char confirm;
                cout << "\nAre you sure you want to delete this employee? (y/n): ";
                cin >> confirm;
                
                if (confirm == 'y' || confirm == 'Y') {
                    employees.erase(it);
                    cout << "\nEmployee Deleted Successfully!" << endl;
                } else {
                    cout << "\nDeletion Cancelled!" << endl;
                }
                return;
            }
        }
        cout << "\nEmployee not found!" << endl;
    }
};

int main() {
    PayrollSystem payroll;
    int choice;

    do {
        cout << "\n=== PAYROLL MANAGEMENT SYSTEM ===" << endl;
        cout << "1: NEW EMPLOYEE" << endl;
        cout << "2: DISPLAY EMPLOYEE" << endl;
        cout << "3: LIST OF EMPLOYEES" << endl;
        cout << "4: SALARY SLIP" << endl;
        cout << "5: EDIT" << endl;
        cout << "6: DELETE EMPLOYEE" << endl;
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
            case 6:
                payroll.deleteEmployee();
                break;
            case 0:
                cout << "\nThank you for using the system!" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
} 
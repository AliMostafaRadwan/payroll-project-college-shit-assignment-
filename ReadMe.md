# Payroll Management System Project in C++

## Features of the project:

1. **Addition of New Employee:** You can find this feature under the public category of class employee. The information contained in this feature are employee code number, name, address, phone number, joining date (day, month and year), designation, grade and loan. Besides these, this function also stores record related to employee's basic salary, house allowance, and many more.

2. **Modify Employee Record:** Payroll management system project in C++ asks for employee code from the user for this function to work. Modifications that can be made are the employee code number itself, joining date (day, month and year), name, address, phone number, designation, grade, house allowance and loan given to the employee. Employee's grade are categorized as A, B, C, D and E.

3. **Delete Employee Record:** You can simply delete an employee record from Payroll management system project by entering the employee code. A confirmation message is asked stating whether the user really wants to delete the record from the file.

4. **Print Employee Salary Slip:** This feature too asks for the employee code; the employee code has been used to unlock or perform operations in many features of this payroll management system project in C++. This function lists all the months of the year, and asks for date, employee name, designation and grade from the user. To print the salary slip, the user further needs to provide information such as number of days worked in the month by the employee and the number of hours worked over time. The slip enlists basic salary, allowance, deductions and net salary of the employee.

5. **Display a Employee Record:** Providing the employee code number, users can access all the provided information related to a particular employee via this function. The employee record information displayed are the ones provided while adding a new employee record.

6. **Display List of Employees:** Unlike the above function, this feature displays the record of all employees added in file. The records are displayed in a tabular pattern containing information such as code name of the employee, phone number, date of joining, designation, grade and salary.


## Header Files Used:

To keep the project simple, graphics has not been implemented in this project. Before you compile the C++ source code, make sure the following header files are there in your compiler library folder.

* `#include <iostream.h>`
* `#include <fstream.h>`
* `#include <process.h>`
* `#include <string.h>`
* `#include <stdlib.h>`
* `#include <stdio.h>`
* `#include <ctype.h>`
* `#include <conio.h>`
* `#include <dos.h>`

```
1: NEW EMPLOYEE
2: DISPLAY EMPLOYEE
3: LIST OF EMPLOYEES
4: SALARY SLIP
5: EDIT
0: QUIT
ENTER YOUR CHOICE :
```

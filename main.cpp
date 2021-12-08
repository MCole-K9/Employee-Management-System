#include "CRUD.h"
#include "Menu.h"

int main(int argc, char const *argv[])
{
    string choice;
    bool shouldRun = true;

    Employee *employee;
    string employeeType;
    
    InicializeFile(employee);

    while (shouldRun){

        choice = Menu();

        if (choice == "1A"){

            employeeType = "Administrator";
            Add(employee, employeeType);

        }
        else if (choice == "1B"){

            employeeType = "Teacher";
            Add(employee, employeeType);
        }
        else if (choice == "2A"){

            employeeType = "Administrator";
            UpdateEmployee(employee, employeeType);
        }
        else if (choice == "2B"){
            
            employeeType = "Teacher";
            UpdateEmployee(employee, employeeType);
        }
        else if (choice == "3A"){

            employeeType = "Administrator";
            DeleteEmployee(employee, employeeType);
        }
        else if (choice == "3B"){

            employeeType = "Teacher";
            DeleteEmployee(employee, employeeType);
        }
        else if (choice == "4A"){

            string employeeType = "Administrator";

            DisplayEmployee(employee, employeeType);
        }
        else if (choice == "4B"){

            string employeeType = "Teacher";

            DisplayEmployee(employee, employeeType);

        }
        else if (choice == "5A"){

            employee = new Administrator;

            float rateOfPay;
            float overtimeHours;

            cout << "Enter Rate of pay"<< endl;
            cin >> rateOfPay;

            cout << "Enter over time hours"<< endl;
            cin >> overtimeHours;

            employee->CalculateSalary(rateOfPay, overtimeHours);
           

        }
        else if (choice == "5B"){

            employee = new Teacher;

            float rateOfPay;
            int contactHours;

            cout << "Enter Rate of pay"<< endl;
            cin >> rateOfPay;

            cout << "Enter Contact time hours"<< endl;
            cin >> contactHours;

            employee->CalculateSalary(rateOfPay, contactHours);

        }
        else if (choice == "6"){
            shouldRun = false;
            cout << "\nThanks for using this Program";
        }   
    }
   
    return 0;
}


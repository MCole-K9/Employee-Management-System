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
        cout << choice;

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
            

        }
        else if (choice == "5B"){


        }
        else if (choice == "6"){
            shouldRun = false;
            cout << "Thanks for using the Program\n";
        }   
    }
   
    return 0;
}


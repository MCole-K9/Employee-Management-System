#include <iostream>
#include <string.h>

using namespace std;



string Menu(){

    int choice;

    cout << "Menu Options" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Search for Employee" << endl;
    cout << "3. Update Employee" << endl;
    cout << "4. Delete Employee" << endl;
    cout << "5. Display an Employee" << endl;
    cout << "6. Calculate Possibly Salary" << endl;
    cout << "7. Exit Program" << endl; 

    cin >> choice;

    if (choice <= 4){

        cout << "Select Type of Employee" << endl;
        cout << "A. Administrator" << endl;
        cout << "B. Teacher" << endl;

        char typeSelection;
        cin >> typeSelection;

        typeSelection = toupper(typeSelection);
        
        string x = to_string(choice) + typeSelection;
        return x ;

    }

    return to_string(choice);

    
    
}
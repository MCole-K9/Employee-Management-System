#include <iostream>
#include <string.h>

using namespace std;



string Menu(){

    int choice;

    cout << "Menu Options" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Update Employee" << endl;
    cout << "3. Delete Employee" << endl;
    cout << "4. Display an Employee" << endl;
    cout << "5. Calculate Possibly Salary" << endl;
    cout << "6. Exit Program" << endl; 

    cin >> choice;

    if (choice <= 5){

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
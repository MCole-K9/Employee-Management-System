#include <iostream>
#include <string.h>

using namespace std;



string Menu(){
    

    int choice;

    
    cout << "\nMenu Options" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Update Employee" << endl;
    cout << "3. Delete Employee" << endl;
    cout << "4. Display an Employee" << endl;
    cout << "5. Calculate Possibly Salary" << endl;
    cout << "6. Exit Program" << endl; 

    try{

        cin >> choice;
        
        if (choice <= 6 && choice >= 1){
            if (choice != 6){

                cout << "Select Type of Employee" << endl;
                cout << "A. Administrator" << endl;
                cout << "B. Teacher" << endl;

                char typeSelection;
                cin >> typeSelection;

                typeSelection = toupper(typeSelection);

                if (typeSelection == 'A' || typeSelection == 'B' )
                {
                    string x = to_string(choice) + typeSelection;
                    return x ;

                }else{

                    throw "Invalid Employee Type Selection\n";

                }
                
                
               

            }
        } 
        else{
            throw -1;
        }
        
    }catch(const char *){

        cout << "Invalid Employee Type Selection\n";

    }catch(int e){

        cerr << "Invalid Menu Option\n";
    }
    
   //If choice was equal to 6 it should hit this return statement 
   return to_string(choice);
    
}
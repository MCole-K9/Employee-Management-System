#include <iostream>
using namespace std;

struct EmployeeData
{
        int EmployeeId;
        string Name;
        float RatePerHour;
        string Currency;
};


EmployeeData Input(string empType, string mode){

        EmployeeData ed;
        cout<<empType;
        

        if (mode == "Add"){

                bool validEntry = false;
                while (!validEntry)
                {
                        try{

                                cout << "Enter Employee ID" << endl;
                                cin >> ed.EmployeeId;

                                if (empType == "Administrator"){
                                 
                                        if(ed.EmployeeId < 1000 || ed.EmployeeId > 1049){
                                        
                                                throw -1;
                                        }else{
                                                validEntry = true;
                                        }


                                }else if (empType == "Teacher"){

                                        if(ed.EmployeeId < 1050 || ed.EmployeeId > 1099){

                                                throw -2;
                                        }else{
                                                validEntry = true;
                                        }
                                }
                        }
                        catch(int e){
                                

                                cerr << "Invalid " << empType << " ID";
                                validEntry = false;
                                
                        }

                        

                }
        
                cout << "Enter First Name" << endl;
                string firstName;
                cin >> firstName;

                cout << "Enter Last Name" << endl;
                string lastName;
                cin >> lastName;
                // getline(cin, ed.Name);
                
                ed.Name = firstName + " " + lastName;

                cout << "Enter Rate per Hour" << endl;
                cin >> ed.RatePerHour;

                cout << "Enter the currency in which the Employee is paid " << endl;
                cin >> ed.Currency;

 

        }else if (mode == "Update"){

                cout << "Enter First Name" << endl;
                string firstName;
                cin >> firstName;

                cout << "Enter Last Name" << endl;
                string lastName;
                cin >> lastName;
                // getline(cin, ed.Name);
                
                ed.Name = firstName + " " + lastName;

                cout << "Enter Rate per Hour" << endl;
                cin >> ed.RatePerHour;

                cout << "Enter the currency in which the Employee is paid " << endl;
                cin >> ed.Currency;                

        }

    return ed;

}
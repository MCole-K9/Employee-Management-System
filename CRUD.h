#include "Teacher.h"
#include "Administrator.h"
#include "EmployeeData.h"
#include <fstream>

//Matthew Cole - 2017001245

void Add(Employee *employee, string employeeType){

    fstream fileObj;

    if (employeeType == "Administrator"){


        while (true){
            
            int workstationId;
            float overtimeHours;
            EmployeeData ed;
            
            ed = Input(employeeType, "Add");
            cout << "Enter Administrator's Work Station ID" << endl;
            cin >> workstationId;
            cout << "Enter Administrator's Over Time Hours" << endl;
            cin >> overtimeHours;

            employee = new Administrator(ed.EmployeeId, ed.Name, ed.RatePerHour, 0.0, ed.Currency, workstationId, overtimeHours);
            employee->CalculateSalary();

            try{

                fileObj.open("Administrator.dat", ios::out | ios::binary);

                if (fileObj.fail()){
                    
                    throw -1;
            
                }else{
                    fileObj.seekp((employee->getEmployeeId() - 1000) * sizeof(Administrator));
                    fileObj.write( reinterpret_cast <const char *>(employee), sizeof(Administrator));
                }

            }catch(int e){
                cerr << "Unable to open File\n";
            }


            cout << "Do you wish to add another "<< employeeType << " Record Y -Yes / N-No"<<endl;
            char ch;
            cin >> ch;
            ch = toupper(ch);
            if(ch != 'Y'){
                break;
            }
        }


    }else if(employeeType == "Teacher"){

        while (true){

                string specializedSubject;
                int contactHours;

                EmployeeData ed;
                ed = Input(employeeType, "Add");

                cout << "Enter Teacher's Specialzed Subject" << endl;
                cin >> specializedSubject;

                cout << "Enter Teacher's Contact Hours" << endl;
                cin >> contactHours;

                employee = new Teacher(ed.EmployeeId, ed.Name, ed.RatePerHour, 0.0, ed.Currency, specializedSubject, contactHours);
                employee->CalculateSalary();

                try{
                    fileObj.open("Teacher.dat", ios::out | ios::binary);

                    if (fileObj.fail()){

                        throw -1;

                    }else{

                        fileObj.seekp((employee->getEmployeeId() - 1050) * sizeof(Teacher));
                        fileObj.write(reinterpret_cast <const char *> (employee), sizeof(Teacher));  
                    }                    
                }catch(int e){

                    cerr << "Unable to open file\n";
                }

                cout << "Do you wish to add another "<< employeeType << " Record Y -Yes / N-No"<<endl;
                char ch;
                cin >> ch;

                ch = toupper(ch);

                if(ch != 'Y'){
                    break;
                }                
            }

       

                
    }

    fileObj.close();
}

void DisplayEmployee(Employee *employee, string employeeType){

    if (employeeType == "Administrator"){

        employee = new Administrator;
        try{

            fstream fileObj("Administrator.dat", ios::in | ios::binary); //declare a reference to the File
            
            int id;
        
            
            //prompt user for relevant details
            cout<<"Please enter details for employee to be displayed.\n";
            cout<<"Employee Id: ";
            cin>>id;
            
            if(id < 1000 || id > 1049)
            {
                throw "invalid id";
            }
            
            
            if(fileObj.fail()) //if we were unable to open file
            {
                throw -1;
            }
            else //if we were able to open file
            {
                fileObj.seekg((id - 1000) * sizeof(Administrator), ios::beg); //Go to starting position of record
                fileObj.read( reinterpret_cast <char *>(employee), sizeof(Administrator)); //read details from file into object
                
                employee->Display(); 
                
            }
            fileObj.close();
        }
        catch(int e)
        {
            cerr<<"Unable to open file"<<endl;
        }
        catch(char const *)
        {
            cerr<<"The Employee Id entered to be displayed is invalid!"<<endl;
        }
        catch(...)
        {
            cerr<<"Catch All statement in DisplayEmployee reached."<<endl;
        }

    }
    else if (employeeType == "Teacher"){

        employee = new Teacher;

        try{

            fstream fileObj("Teacher.dat", ios::in |ios::binary); //declare a reference to the File
            
            int id;
        
            
            //prompt user for relevant details
            cout<<"Please enter details for employee to be displayed.\n";
            cout<<"Employee Id: ";
            cin>>id;
            
            if(id < 1050 || id > 1099)
            {
                throw "invalid id";
            }
            
            
            if(fileObj.fail()) //if we were unable to open file
            {
                throw -1;
            }
            else //if we were able to open file
            {
                fileObj.seekg((id - 1050) * sizeof(Teacher)); //Go to starting position of record
                fileObj.read( reinterpret_cast <char *>(employee), sizeof(Teacher)); //read details from file into object
                
                employee->Display();
                
            }
            fileObj.close();
        }
        catch(int e)
        {
            cerr<<"Unable to open file"<<endl;
        }
        catch(char const *)
        {
            cerr<<"The Employee Id entered to be displayed is invalid!"<<endl;
        }
        catch(...)
        {
            cerr<<"Catch All statement in DisplayEmployee reached."<<endl;
        }

    }
}
void UpdateEmployee(Employee *employee, string employeeType){



    EmployeeData ed;

    if (employeeType == "Administrator"){

        try{

            fstream fileObj("Administrator.dat", ios::out | ios::binary); //declare a reference to the File
            
            int id;
        
            
            //prompt user for relevant details
            cout<<"Please enter details for employee you wish to update.\n";
            cout<<"Employee Id: ";
            cin>>id;
            
            if(id < 1000 || id > 1049)
            {
                throw "\ninvalid id";
            }

            int workstationId;
            float overtimeHours;
                
            ed = Input(employeeType, "Update");
            cout << "Enter Administrator's Work Station ID" << endl;
            cin >> workstationId;
            cout << "Enter Administrator's Over Time Hours" << endl;
            cin >> overtimeHours;
            employee = new Administrator(id, ed.Name, ed.RatePerHour, 0.0, ed.Currency, workstationId, overtimeHours);
            employee->CalculateSalary();
            
            
            if(fileObj.fail()) //if we were unable to open file
            {
                throw -1;
            }
            else //if we were able to open file
            {
                fileObj.seekp((id - 1000) * sizeof(Administrator), ios::beg); //Go to starting position of record
                fileObj.write( reinterpret_cast <char *>(employee), sizeof(Administrator)); //read details from file into object
                
            }
            fileObj.close();
        }
        catch(int e)
        {
            cerr<<"Unable to open file"<<endl;
        }
        catch(char const *)
        {
            cerr<<"The Employee Id entered to be Updated is invalid!"<<endl;
        }
        catch(...)
        {
            cerr<<"Catch All statement in Update reached."<<endl;
        }

    }
    else if (employeeType == "Teacher"){

        

        try{

            fstream fileObj("Teacher.dat", ios::in |ios::binary); //declare a reference to the File
            
            int id;
        
            
            //prompt user for relevant details
            cout<<"Please enter details for employee to be displayed.\n";
            cout<<"Employee Id: ";
            cin>>id;
            
            if(id < 1050 || id > 1099)
            {
                throw "invalid id";
            }
            
            string specializedSubject;
            int contactHours;

                
            ed = Input(employeeType, "Update");

            cout << "Enter Teacher's Specialzed Subject" << endl;
            cin >> specializedSubject;

            cout << "Enter Teacher's Contact Hours" << endl;
            cin >> contactHours;

            employee = new Teacher(id, ed.Name, ed.RatePerHour, 0.0, ed.Currency, specializedSubject, contactHours);
            employee->CalculateSalary();
            

            if(fileObj.fail()) //if we were unable to open file
            {
                throw -1;
            }
            else //if we were able to open file
            {
                fileObj.seekp((id - 1050) * sizeof(Teacher)); //Go to starting position of record
                fileObj.write( reinterpret_cast <char *>(employee), sizeof(Teacher)); //read details from file into object
                
            }
            fileObj.close();
        }
        catch(int e)
        {
            cerr<<"Unable to open file"<<endl;
        }
        catch(char const *)
        {
            cerr<<"The Employee Id entered to be updated is invalid!"<<endl;
        }
        catch(...)
        {
            cerr<<"Catch All statement in Add reached."<<endl;
        }

    }
}

void DeleteEmployee(Employee *employee, string employeeType){

    if (employeeType == "Administrator"){

        try{

            fstream fileObj("Administrator.dat", ios::out | ios::binary); //declare a reference to the File
            
            int id;
        
            
            cout<<"Please enter details for employee you wish to be Deleted.\n";
            cout<<"Employee Id: ";
            cin>>id;
            
            if(id < 1000 || id > 1049)
            {
                throw "invalid id";
            }
            employee = new Administrator;
            
            if(fileObj.fail()) //if we were unable to open file
            {
                throw -1;
            }
            else //if we were able to open file
            {
                fileObj.seekp((id - 1000) * sizeof(Administrator), ios::beg); //Go to starting position of record
                fileObj.write( reinterpret_cast <char *>(employee), sizeof(Administrator)); //read details from file into object
                
            }
            fileObj.close();
        }
        catch(int e)
        {
            cerr<<"Unable to open file"<<endl;
        }
        catch(char const *)
        {
            cerr<<"The Employee Id entered to be delete is invalid!"<<endl;
        }
        catch(...)
        {
            cerr<<"Catch All statement in DeleteEmployee reached."<<endl;
        }

    }
    else if (employeeType == "Teacher"){

        

        try{

            fstream fileObj("Teacher.dat", ios::in |ios::binary);
            
            int id;
        
            

            cout<<"Please enter details for employee to be deleted.\n";
            cout<<"Employee Id: ";
            cin>>id;
            
            if(id < 1050 || id > 1099)
            {
                throw "invalid id";
            }

            employee = new Teacher;
            

            if(fileObj.fail()) 
            {
                throw -1;
            }
            else //if we were able to open file
            {
                fileObj.seekp((id - 1050) * sizeof(Teacher)); //Go to starting position of record
                fileObj.write( reinterpret_cast <char *>(employee), sizeof(Teacher)); //read details from file into object
                
            }
            fileObj.close();
        }
        catch(int e)
        {
            cerr<<"Unable to open file"<<endl;
        }
        catch(char const *)
        {
            cerr<<"The Employee Id entered to be deleted is invalid!"<<endl;
        }
        catch(...)
        {
            cerr<<"Catch All statement in DeleteEmployee reached."<<endl;
        }

    } 
}

void InicializeFile(Employee *employee){

    int max = 50; 
            
    try
    {   fstream fileObj("Teacher.dat", ios::in|ios::binary);
        if (!fileObj.is_open()){

            fstream fileObj("Administrator.dat", ios::out|ios::binary); //declare a reference to file
            employee = new Administrator;
            
            if(fileObj.fail()) 
            { 
                throw -1; 
            }
            for(int i = 0; i <= max; i++)
            { 
                fileObj.seekp((i) * sizeof(Administrator));
                fileObj.write(reinterpret_cast <const char *> (employee), sizeof(Administrator));
            }
            fileObj.close();
        }
    }
    catch(int e)
    { 
    	cerr <<"Administrator File was not created! Error Code - "<< e<< endl;
    }

    try
    { 
    	fstream fileObj("Teacher.dat", ios::in|ios::binary);
        
        if (!fileObj.is_open()){

            fstream fileObj("Teacher.dat", ios::out|ios::binary);
            employee = new Teacher;
            
            if(fileObj.fail()) //if we unable to reference file
            { 
                throw -2; 
            }
            for(int i = 0; i <= max; i++) //loop through each record and store default data
            { 
                fileObj.seekp((i) * sizeof(Teacher)); //go to starting address of record
                fileObj.write(reinterpret_cast <const char *> (employee), sizeof(Teacher)); //write the default instance to address
            }
            fileObj.close();
        }



 
    }
    catch(int e)
    { 
    	cerr <<"Teacher File was not created! Error Code - "<< e<< endl;
    }
        
}
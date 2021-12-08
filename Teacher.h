#ifndef TEACHER_H  
#define TEACHER_H


#include "Employee.h"

class Teacher: public Employee{

    private:

        string SpecializedSubject;
        int ContactHours;

    public:
    
        Teacher():Employee(){
            
            SpecializedSubject = "";
            ContactHours = 0;
        }
        Teacher(int EmployeeId, string Name, float RatePerHour, float Salary, string Currency, string specializedSubject, int contactHours):Employee(EmployeeId, Name, RatePerHour, Salary, Currency){

            SpecializedSubject = specializedSubject;
            ContactHours = contactHours;
        
        }
        Teacher(Teacher &teacher):Employee(teacher.EmployeeId, teacher.Name, teacher.RatePerHour, teacher.Salary, teacher.Currency){

            SpecializedSubject = teacher.SpecializedSubject;
            ContactHours = teacher.ContactHours;
        }
        ~Teacher(){}

        void CalculateSalary(){

            Salary = ContactHours * RatePerHour;
        }
        void CalculateSalary(float rateOfPay, int contactHours){
            
            Salary = contactHours * rateOfPay;
            cout << "Possible Salary is $" << Salary << endl;
        }
        void CalculateSalary(float rateOfPay, float overtimeHours){

            Salary = rateOfPay * (40 + overtimeHours);
            cout << "Possible Salary is $" << Salary << endl;
        }
        void Display(){

            cout << "Name: " << Name << endl;
            cout << "Employee ID: " << EmployeeId << endl;
            cout << "Specialized Subject: " << SpecializedSubject << endl;
            cout << "Salary: " << "$" << Salary << " " << Currency << endl;
            cout << "Rate per Hour: " << "$" << RatePerHour << " " << Currency << endl;
            cout << "Contact Hours: " << ContactHours << "Hrs" << endl;
            cout << "\n\n\n";
        }

};

#endif
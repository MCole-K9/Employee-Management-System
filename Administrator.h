#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "Employee.h"

class Administrator: public Employee{

    private:

        int WorkstationId;
        float OvertimeHours;


    public:
        Administrator():Employee(){

            WorkstationId = 0;
            OvertimeHours = 0.0f;
        }
        Administrator(int EmployeeId, string Name, float RatePerHour, float Salary, string Currency, int workstationId, float overtimeHours):Employee(EmployeeId, Name, RatePerHour, Salary, Currency){

            WorkstationId = workstationId;
            OvertimeHours = overtimeHours;
        }
        Administrator(Administrator &administrator):Employee(administrator.EmployeeId, administrator.Name, administrator.RatePerHour ,administrator.Salary, administrator.Currency ){

            WorkstationId = administrator.WorkstationId;
            OvertimeHours = administrator.OvertimeHours;

        }
        ~Administrator(){}

        void setWorkstationId(int workstationId){
            WorkstationId = workstationId;
        }
        void setOvertimeHours(float overtimeHours){
            OvertimeHours = overtimeHours;
        }

        int getWorkstationId(){
            return WorkstationId;
        }

        float getOvertimeHours(){
            return OvertimeHours;
        }

        void CalculateSalary(){
            
            Salary = RatePerHour * (40 + OvertimeHours);
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
            cout << "Workstation ID: " << WorkstationId << endl;
            cout << "Salary: " << "$" << Salary << " " << Currency << endl;
            cout << "Rate per Hour: " << "$" << RatePerHour << " " << Currency << endl;
            cout << "Over Time Hours: " << OvertimeHours << "Hrs" << endl;
            cout << "\n\n\n";

        }
};



#endif
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee{
    
    protected:
        int EmployeeId;
        string Name;
        float RatePerHour;
        float Salary;
        string Currency;

    public:
        Employee(){

            EmployeeId = 0;
            Name = "";
            RatePerHour = 0.0f;
            Salary = 0.0f;
            Currency = "";
        }

        Employee(int employeeId, string name, float ratePerHour, float salary, string currency){

            EmployeeId = employeeId;
            Name = name;
            RatePerHour = ratePerHour;
            Salary = salary;
            Currency = currency;

        }

        Employee(Employee &employee){

            EmployeeId = employee.EmployeeId;
            Name = employee.Name;
            RatePerHour = employee.RatePerHour;
            Salary = employee.Salary;
            Currency = employee.Currency;
        }

        ~Employee(){}
        
        void setEmployeeId(int employeeId){
            EmployeeId = employeeId;
        }
        void setName(string name){
            Name = name;
        }
        void setRatePerHour(float ratePerHour){
            RatePerHour = ratePerHour;
        }
        void setSalary(float salary){
            Salary = salary;
        }
        void setCurrency(string currency){
            Currency = currency;
        }

        int getEmployeeId(){
            return EmployeeId;
        }
        string getName(){
            return Name;
        }
        float getRatePerHour(){
            return RatePerHour;
        }
        float getSalary(){
            return Salary;
        }
        string getCurrency(){
            return Currency;
        }

        virtual void CalculateSalary() = 0;

        virtual void CalculateSalary(float x, float y) = 0;

        virtual void CalculateSalary(float x, int y) = 0;

        virtual void Display() = 0;

        

};

#endif
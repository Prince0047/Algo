#include<iostream>
using namespace std;

// Abstract Class
class AbstractEmployee {
    virtual void AskForPromotion()=0;
};

// Signing the contract for the abstract class
class Employee : AbstractEmployee {

private:
    string Company;
    int age;

protected:
    string Name;

public:
    Employee(){};

    Employee(string name, string comp, int age){
        Name = name;
        Company = comp;
        Employee::age = age;
    }

    void introduce(){
        cout<<Name<<endl;
    }

    void AskForPromotion(){
        if(age>30){
            cout<<Name<<" got Promoted "<<endl;
        }
        else{
            cout<<Name<<" , sorry No Promotion."<<endl;
        }
    }


    // Getters and Setters

    // Name
    void setname(string name){
        Name = name; 
    }
    string getname(){
        return Name;
    }

    // Company
    void setCompany(string comp){
        Company = comp;
    }
    string getcompany(){
        return Company;
    }

    // Age
    void setage(int age){
        Employee::age = age;
    }
    int getage(){
        return age;
    }


    virtual void Work(){
        cout<<Name<<" is working on something, I don't know what."<<endl;
    }
};

/* Inhereting Base Class Employee
   by default inheritence is private 
   =>> Developer class object cannot access Employee methods directly in main function.
*/
class Developer : public Employee {

public:

    string FavProgrammingLang;

    Developer(string name, string comp, int age, string FavPL)
        : Employee(name,comp,age)
    {
        FavProgrammingLang = FavPL;
    }

    void FixBug(){
        cout<<Name<<" fixed the bugs of "<<FavProgrammingLang<<" while working in "<<getcompany()<<endl;
    }
};

class Teacher : public Employee {

public:
    string Subject;

    Teacher(string name, string company, int age, string subject)
    : Employee(name, company, age) 
    {
        Subject = subject;
    }

    void PrepareLesson() {
        cout<<Name<<" is preparing "<<Subject<<" lesson"<<endl;
    }

    void Work(){
        cout<<Name<<" is evaluating the test papers of "<<Subject<<endl;
    }
};

int main(){



     Developer dev("Bhadana", "google", 35, "Python");
    Teacher teach = Teacher("jack", "Cool School", 35, "History");

    dev.Work();
    teach.Work();

    Employee* d = &dev;
    Employee* t = &teach;

/* Before making Work in Employee a virtual Funtion 
   Output is Work in Employee             */

    d->Work();
    t->Work();


/* After making Work() in Employee a virtual Function 
   Output is Work in latest classes  */
    d->Work();
    t->Work();


/* 
   Polymorphism is considered one of the important features of Object-Oriented Programming. 
   Polymorphism allows us to perform a single action in different ways. 
   In other words, polymorphism allows you to define one interface and have multiple implementations 
*/

    return 0;
}

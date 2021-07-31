#include<iostream>
using namespace std;

// Abstract Class
class AbstractEmployee {
    virtual void AskForPromotion()=0;
};

// Signing the contract for the abstract class
class Employee : AbstractEmployee {
public:
    string Name;
    string Company;
    int age;

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
};

int main(){

    // Creating class object
    Employee emp1;
    emp1.Name = "Sonu";
    emp1.Company = "Yamaha";
    emp1.age = 32; 

    emp1.introduce();

    Employee emp2("Prince","amazon",25);
    emp2.introduce();


    emp1.AskForPromotion();
    emp2.AskForPromotion();

    return 0;
}

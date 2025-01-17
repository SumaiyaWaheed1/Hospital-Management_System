using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/person.hh"

person::person()
{
    id = -1;
}
void person::addPerson(int minAge, int maxAge)
{
     // getting basic details of the person from the user side;
        cout << "\nEnter name: \nFirst name:"<<endl;
        getline(cin >> ws, firstName);
        cout << "\nLast name:"<<endl;
        getline(cin, lastName);
        cout << "\nEnter age: "<<endl;
        cin >> age;
        while (age <= 0)
            cout << "Please enter correct age \nEnter again!"<<endl, cin >> age;
        if (category != 2)
        {
            while(age <minAge || age > maxAge){

                if (age < minAge)
                    cout << "Sorry, person should be at least " << minAge << " years old to be registered as a " << cat << endl;
                else if (age > maxAge)
                    cout << "Sorry, we can't register a person older than " << maxAge << " years as a " << cat << endl;
                cout << "\nEnter age: "<<endl;
                cin >> age;
           }
        }
        cout << "\nGender (M = Male || F = Female):"<<endl;
        cin >> gender;
        while (gender != 'M' && gender != 'F')
            cout << "M or F?\n", cin >> gender;
        cout << "\nEnter mobile number : "<<endl;
        cin >> mobNumber;
        cout << "\nEnter address : "<<endl;
        cin >> address;
        return;
}
void person::printDetails()
{
    if (id == -1)
        return;
    cout << "\nDetails:\n";
    cout << "ID              : " << id << endl;
    cout << "Full Name       : " << firstName << " " << lastName << endl;
    cout << "Gender          : " << gender << endl;
    cout << "Age             : " << age << endl;
    cout << "Mobile          : " << mobNumber << endl;
    cout << "Address         : " << address <<endl;
    return;
}
void person::printDetailsFromHistory()
{
    if (id == -1)
        return;
    cout << "\nHistory Details :\n";
    cout << "Full Name       : " << firstName << " " << lastName << "\n";
    cout << "Gender          : " << gender << "\n";
    cout << "Age             : " << age << "\n";
    cout << "Mobile          : " << mobNumber << "\n";
    cout << "Address         : " << address <<endl;
    return;
}
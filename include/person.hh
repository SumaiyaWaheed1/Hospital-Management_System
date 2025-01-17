#ifndef PERSON
#define PERSON
using namespace std;
#include <string>


class person 
{
protected:
    int id;
    string firstName, lastName;
    char gender;
    int age;
    int mobNumber;
    string address;
    string cat;
    int category;
    //category: 1:doctor; 2:patient; 3:nurse;

public:
    person();
    virtual void fillMap() = 0;
    virtual void saveMap() = 0;
    virtual void addPerson(int minAge = 0, int maxAge = 1000);
    virtual void printDetails();
    virtual void printDetailsFromHistory();
    virtual void getDetails() = 0;
    virtual void removePerson() = 0;
};
#endif // !PERSON

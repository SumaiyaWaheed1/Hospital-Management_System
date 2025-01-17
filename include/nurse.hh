#ifndef NURSE
#define NURSE
using namespace std;
#include <string>

#include "./person.hh"

class nurse : public person
{
private:
    string type;

public:
    nurse();
    nurse(int id, string fname, string lname,char g,int a, int mn, string add,string t);    
    void fillMap();
    void saveMap();
    void addPerson();
    void printDetails();
    void printDetailsFromHistory();
    void getDetails();
    void removePerson();
};
#endif // !NURSE
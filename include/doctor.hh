#ifndef DOCTOR
#define DOCTOR
using namespace std;
#include <string>

#include "./person.hh"

class appointment;
class doctor : public person
{
protected:
    string type;
    int appointmentsBooked;
    friend class appointment;
    friend class DoctorBST;
    friend class emergencypriorityqueue;
    friend class emergencyOPD;

public:
    bool isavailable; // keeep track if the doctor is available , used in OPD 
    doctor();
    doctor(int id, string fname, string lname,char g,int a, int mn, string add,string t,int ab);
    void fillMap();
    void saveMap();
    void addPerson();
    void printDetails();    
    void printDetailsFromHistory();
    void getDetails();
    void removePerson();
};
#endif // !DOCTOR
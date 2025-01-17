#ifndef PATIENT
#define PATIENT
using namespace std;

#include "./person.hh"

class appointment;
class patient : public person
{
private:
    int height; //in cms;
    int weight; //in pounds;
    bool hospitalized;
    bool discharged;
    bool alive;
    friend class appointment;

public:
    patient();
    patient(int id, string fname, string lname,char g,int a, int mn, string add,int h,int w,bool wh,bool sa);
    void fillMap();
    void saveMap();
    void addPerson();
    void printDetails();
    void printDetailsFromHistory();
    void getDetails();
    void hospitalize();
    void reportADeath();
    void removePerson();
};
#endif // !PATIENT
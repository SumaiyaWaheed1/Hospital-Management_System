#ifndef AMBULANCE
#define AMBULANCE
using namespace std;
#include <string>

class ambulance
{
private:
    int id;
    string vrn; //vehicle registration number;
    bool idle;
    string address;

public:
    ambulance();
    ambulance(int id, string vrn,bool i);
    void fillMap();
    void saveMap();
    void addAmbulance();
    void printDetails();
    void printDetailsFromHistory();
    void getDetails(int rec = 0);
    void send();
    void reportArrival();
    void removeAmbulance();
};
#endif // !AMBULANCE
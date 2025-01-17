using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/patient.hh"
#include "./../include/hospital.hh"

patient::patient()
{
    id = -1;
    hospitalized = 0;
    alive = 1;
    cat = "patient";
    category = 2;
    discharged = 0;
}
patient::patient(int id, string fname, string lname,char g,int a, int mn, string add,int h,int w,bool wh,bool sa)
{
    this->id = id;
    hospitalized = wh;
    alive = sa;
    cat = "patient";
    category = 2;
    discharged = 0;
    firstName=fname;
    lastName=lname;
    gender=g;
    age=a;
    mobNumber=mn;
    address=add;
    height=h;
    weight=w;
}
void patient::fillMap()
{
    fstream f;
        f.open("patients.dat", ios::binary|ios::in);
        int id=1;
        while (!f.eof()){
            f.read(reinterpret_cast<char*>(this),sizeof(patient));
            hospital :: patientsList[id++]= *this;
        }
        f.close();
        return;
}
void patient::saveMap()
{
     fstream f;
        f.open("temp.dat", ios::binary|ios::out);
        for (auto i : hospital::patientsList){
            *this=i.second;
            f.write(reinterpret_cast<char*>(this),sizeof(patient));
        }
        f.close();
        remove("patients.dat");
        rename("temp.dat", "patients.dat");
        return;
}



void patient::addPerson()
{
    // getting the basic details of the patient from the user side;
    person::addPerson(0, 200);
    // getting patient-specific details;
    cout << "\nEnter the height of the patient (in cms):" << endl;
    cin >> height;
    cout << "\nEnter the weight of the patient (in pounds):" << endl;
    cin >> weight;

    char tt;
    cout << "\nIs the patient being hospitalized? (Y = Yes || N = No)" << endl;
    cin >> tt;
    while (tt != 'Y' && tt != 'N')
        cout << "Y or N?\n", cin >> tt;
    hospitalized = (tt == 'Y');

    // Find the maximum ID in the unordered_map and increment it
    int maxId = 0;
    for (const auto &entry : hospital::patientsList)
    {
        if (entry.first > maxId)
        {
            maxId = entry.first;
        }
    }

    id = maxId + 1;

    hospital::patientsList[id] = *this;

    // creating a fstream object to read/write from/to files;
    fstream f;
    // creating a record in patientsHistory.csv;
    f.open("patients.dat", ios::binary | ios::app);

    if (!f.is_open())
    {
        cerr << "Error: Could not open file for writing." << endl;
        return;
    }
    f.write(reinterpret_cast<char *>(this), sizeof(patient));

    if (!f.write(reinterpret_cast<char *>(this), sizeof(patient)))
    {
        cerr << "Error: Failed to write to file." << endl;
        f.close(); // Close the file before returning
        return;
    }

    f.close();

    if (f.fail())
    {
        cerr << "Error: Failed to close file properly." << endl;
    }

    cout << endl
         << firstName << " " << lastName << " is registered successfully!" << endl;
    cout << "Their ID is: " << id << endl;
    return;
}

void patient::printDetailsFromHistory(){
    for (auto &entry : hospital::patientsList)
    {
        patient& currentPatient = entry.second;
        currentPatient.printDetails();

    }
} 

void patient :: printDetails(){
        if (id == -1)
            return;
        person::printDetails();
        cout << "Height (cms)    : " << height << endl;
        cout << "Weight (pounds) : " << weight << endl;
        cout << "Was Hospitalized? " << ((hospitalized) ? "Y" : "N") << endl;
        cout << "Alive?          : " << ((alive) ? "Y" : "N") << endl;
        if(hospitalized==1){
            cout<< "Discharged? "<<((discharged)? "Y" : "N")<<endl; 
        }
        return;
    }

void patient::getDetails()
{
    //Filter by name;
        cout<<endl;
        string reqFName, reqLName;
        cout << "Enter first name:"<<endl;
        getline(cin >> ws, reqFName);
        cout << "\nEnter last name:"<<endl;
        getline(cin, reqLName);
        for (auto i : hospital::patientsList)
        {
            if (i.second.firstName == reqFName && i.second.lastName == reqLName){
                cout << " Matching record found!"<<endl;
                i.second.printDetails();
            }
                
        }
        return;
}

void patient::hospitalize()
{
     int reqId=0;
        cout << "\nSearch for the patient."<<endl;
        getDetails();
        cout<<"\nEnter id of patient you want to hospitalize: "<<endl;
        cin>>reqId;
        if (hospital::patientsList.find(reqId) != hospital::patientsList.end())
            *this = hospital::patientsList[reqId];
        if (id == -1)
            return;
        hospital::patientsList[this->id].hospitalized = 1;
        cout<<endl<<firstName<<" "<<lastName<<" hospitalized"<<endl;
}
void patient::reportADeath()
{
    int reqId=0;
        cout << "\nSearch for the patient.\n";
        getDetails();
        cout<<"\nEnter id of patient you want to report dead: "<<endl;
            cin>>reqId;
            if (hospital::patientsList.find(reqId) != hospital::patientsList.end())
                *this = hospital::patientsList[reqId];
        if (id == -1)
            return;
        hospital::patientsList[id].alive = 0;
        printDetails();
        hospital::patientsList.erase(id);
        cout << firstName << " " << lastName << " reported dead, we hope their soul rests in peace, amen!"<<endl;
        return;
}
void patient::removePerson()
{
    int reqId=0;
        cout << "\nSearch for the patient you want to discharge."<<endl;
        getDetails();
        cout<<"\nEnter id of patient you want to discharge: "<<endl;
        cin>>reqId;
        if (hospital::patientsList.find(reqId) != hospital::patientsList.end())
            *this = hospital::patientsList[reqId];
        if (id == -1)
            return;
        if (!hospitalized){
            cout << "\nPatient wasn't hospitalized, can't be discharged!"<<endl;
            return;
        }
        
        hospital::patientsList[this->id].discharged = 1;
        hospital::patientsList.erase(id);
        cout << firstName << " " << lastName << " discharged!"<<endl;
        return;
}


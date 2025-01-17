using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

#include "./../include/global.hh"
#include "./../include/doctor.hh"
#include "./../include/hospital.hh"

doctor::doctor()
{
    id = -1;
    type = "";
    appointmentsBooked = 0;
    cat = "doctor";
    category = 1;
    isavailable = true;
}
doctor::doctor(int id, string fname, string lname, char g, int a, int mn, string add, string t, int ab)
{
    this->id = id;
    type = t;
    appointmentsBooked = ab;
    cat = "doctor";
    category = 1;
    isavailable = true;
    firstName = fname;
    lastName = lname;
    gender = g;
    address = add;
    age = a;
    mobNumber = mn;
}

void doctor::fillMap()
{
    cout << "fill 1" << endl;
    fstream f;
    f.open("doctors.dat", ios::binary | ios::in);
    int id = 1;
    cout << "fill 2" << endl;

    while (f.read(reinterpret_cast<char *>(this), sizeof(doctor)))
    {
        cout << "chalja yarr" << endl;
        hospital::doctorsList.insert({id++, *this});
        cout << "Chalgayaa" << endl;
    }

    if (f.fail() && !f.eof())
    {
        cerr << "Error reading from file!" << endl;
    }

    f.close();
    return;
}

/*void doctor::fillMap()
{
    cout<<"Filled 1";
    fstream f;
    cout<<"Filled 2";
    f.open("doctors.dat", ios::binary | ios::in);
    int id = 1;
    cout<<"Filled 3";
    while (!f.eof())
    {
        f.read(reinterpret_cast<char *>(this), sizeof(doctor));
        hospital::doctorsList.insert({id++, *this});
    }
    f.close();
    cout<<"Filled 4";
    return;
} origional fill mapp /**/

/*void doctor::fillMap()
{
    fstream f;
    cout<<"Filled 1";
    f.open("doctors.dat", ios::binary | ios::in);
    int id = 1;
    while (!f.eof())
    {
        f.read(reinterpret_cast<char *>(this), sizeof(doctor));
        hospital::doctorsList[id++] = *this;
        hospital::doctorTree.insert(*this);
    }
     cout<<"Filled 2";
    f.close();
     cout<<"Filled 3";
    return;
}*/

/*void doctor::fillMap()
{
    fstream f;
    f.open("doctors.dat", ios::binary | ios::in);

    if (!f.is_open())
    {
        cerr << "Error opening file 'doctors.dat'" << endl;
        return;
    }

    int id = 1;
    while (f.read(reinterpret_cast<char *>(this), sizeof(doctor)))
    {
        hospital::doctorsList[id++] = *this;
    }

    f.close();
    return;
}*/

/*void doctor::fillMap()
{
    fstream f;
    f.open("doctors.dat", ios::binary | ios::in);
    int id = 1;

    if (!f.is_open()) {
        cerr << "Error opening file 'doctors.dat'" << endl;
        return;
    }

    doctor tempDoctor; // Temporary object to read data into

    while (f.read(reinterpret_cast<char *>(&tempDoctor), sizeof(doctor)))
    {
        hospital::doctorsList[id++] = tempDoctor;
        hospital::doctorTree.insert(tempDoctor);
    }

    f.close();
    return;
}*/

void doctor::saveMap()
{
    fstream f;
    f.open("temp.dat", ios::binary | ios::out);
    for (auto i : hospital::doctorsList)
    {
        *this = i.second;
        f.write(reinterpret_cast<char *>(this), sizeof(doctor));
    }

    f.close();
    remove("doctors.dat");
    rename("temp.dat", "doctors.dat");
    return;
}

void doctor::addPerson()
{
    if (hospital::doctorsList.size() == hospital::doctorsLimit)
    {
        cout << "\n\nDoctors limit reached, can't add more!" << endl
             << endl;
        return;
    }

    // 18 and 65 are the age limits for registration of a new doctor;
    person::addPerson(18, 65);

    cout << "\nEnter the type of the doctor:" << endl;
    getline(cin >> ws, type);

    // Find the maximum ID in the unordered_map and increment it
    int maxId = 0;
    for (const auto &entry : hospital::doctorsList)
    {
        if (entry.first > maxId)
        {
            maxId = entry.first;
        }
    }

    id = maxId + 1;

    hospital::doctorsList[id] = *this;
    hospital::doctorTree.insert(*this);

    fstream f;
    f.open("doctors.dat", ios::binary | ios::app);

    if (!f.is_open())
    {
        cerr << "Error: Could not open file for writing." << endl;
        return;
    }
    f.write(reinterpret_cast<char *>(this), sizeof(doctor));

    if (!f.write(reinterpret_cast<char *>(this), sizeof(doctor)))
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
         << "Dr. " << firstName << " " << lastName << " registered successfully!" << endl
         << "Their ID is: " << this->id << endl;
}

void doctor::printDetails()
{
    if (id == -1)
        return;
    person::printDetails();
    cout << "Type            : " << type << endl;
    cout << "Appointments    : " << appointmentsBooked << "/8 (appointments booked today)" << endl;
    cout << "Availibility     : " ;
    if(isavailable==1){
        cout<<"Y"<<endl;
    }
    else{
        cout<<"N"<<endl;
    }
}

void doctor::printDetailsFromHistory()
{
    for (auto &entry : hospital::doctorsList)
    {
        doctor &currentDoctor = entry.second;
        currentDoctor.printDetails();
    }
}
void doctor::getDetails()
{
    int opt = 0;
    cout << "\nOPTIONS:\n[1]: Filter by Name\n[2]: Filter by Type\n[3]: Filter by ID" << endl
         << endl;
    cin >> opt;
    while (opt != 1 && opt != 2 && opt != 3)
        cout << "option 1 , 2 or 3 ?" << endl, cin >> opt;
    // 1: Filter by name;
    if (opt == 1)
    {
        string reqFName, reqLName;
        cout << "First Name:" << endl;
        getline(cin >> ws, reqFName);
        cout << "\nLast Name:" << endl;
        getline(cin, reqLName);
        for (auto i : hospital::doctorsList)
        {
            if (i.second.firstName == reqFName && i.second.lastName == reqLName)
            {
                cout << " Matching record found!" << endl;
                i.second.printDetails();
            }
        }
    }
    // 2: Filter by type;
    else if (opt == 2)
    {
        string specialization;
        cout << "Enter the specialization to search for: ";
        cin.ignore();
        getline(cin, specialization);

        hospital::doctorTree.Search(specialization);
    }
    // 3 : Filter by id;
    if (opt == 3)
    {
        int reqId;
        cout << "\nEnter ID:\n";
        cin >> reqId;

        auto it = hospital::doctorsList.find(reqId);
        if (it != hospital::doctorsList.end())
        {
            doctor &requestedDoctor = it->second;
            cout << "Matching record found!\n";
            requestedDoctor.printDetails();
        }
        else
        {
            cout << "\nNo matching record found!\n";
        }
    }
}

void doctor::removePerson()
{
    int reqId = 0;
    cout << "\nSearch for the doctor you want to remove." << endl;
    getDetails();
    cout << "\nEnter the id of the doctor you want to remove: " << endl;
    cin >> reqId;
    if (hospital::doctorsList.find(reqId) != hospital::doctorsList.end())
        *this = hospital::doctorsList[reqId];

    if (this->id == -1)
        return;
    if (this->appointmentsBooked > 0)
    {
        cout << "\nSelected doctor has appointments booked for today, can't be removed." << endl;
        return;
    }
    hospital::doctorsList.erase(id);
}
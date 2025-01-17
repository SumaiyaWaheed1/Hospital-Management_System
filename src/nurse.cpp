using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/nurse.hh"
#include "./../include/hospital.hh"

nurse::nurse()
{
    id = -1;
    type = "";
    cat = "nurse";
    category = 3;
}
nurse::nurse(int id, string fname, string lname,char g,int a, int mn, string add,string t)
{
    this->id=id;
    type = t;
    cat = "nurse";
    category = 3;
    firstName=fname;
    lastName=lname;
    gender=g;
    address=add;
    age=a;
    mobNumber=mn;
}
void nurse::fillMap()
{
     fstream f;
        f.open("nurses.dat",ios::binary| ios::in);
        int id=1;
        while(!f.eof()){
            f.read(reinterpret_cast<char*>(this),sizeof(nurse));
            hospital::nursesList[id++] = *this;
        }
        f.close();
        return;
}
void nurse::saveMap()
{
    fstream f;
        f.open("temp.dat", ios::binary|ios::out);
        for (auto i : hospital::nursesList){
            *this=i.second;
            f.write(reinterpret_cast<char*>(this),sizeof(nurse));
        }
            
        f.close();
        remove("doctors.dat");
        rename("temp.dat", "doctors.dat");
        return;
}


void nurse::addPerson()
{
    if (hospital::nursesList.size() == hospital::nursesLimit)
    {
        cout << "\n\nNurses limit reached, can't add more!" << endl;
        return;
    }

    // 18 and 65 are the age limits for registration of a new nurse;
    person::addPerson(18, 65);

    cout << "\nEnter the type of the nurse: \n";
    getline(cin >> ws, type);

    // Find the maximum ID in the unordered_map and increment it
    int maxId = 0;
    for (const auto &entry : hospital::nursesList)
    {
        if (entry.first > maxId)
        {
            maxId = entry.first;
        }
    }

    id = maxId + 1;

    hospital::nursesList[id] = *this;

    // creating a fstream object to read/write from/to files;
    fstream f;
    // creating a record in nurses.dat;
    f.open("nurses.dat", ios::binary | ios::app);

    if (!f.is_open())
    {
        cerr << "Error: Could not open file for writing." << endl;
        return;
    }
    f.write(reinterpret_cast<char *>(this), sizeof(nurse));

    if (!f.write(reinterpret_cast<char *>(this), sizeof(nurse)))
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

    cout << "\n"
         << firstName << " " << lastName << " registered successfully!" << endl;
    cout << "Their ID is: " << id << endl;

    return;
}

void nurse::printDetails()
{
    if (id == -1)
        return;
    person::printDetails();
    cout << "Type            : " << type << "\n";
    return;
}

void nurse::printDetailsFromHistory(){
    for (auto &entry : hospital::nursesList)
    {
        nurse& currentNurse = entry.second;
        currentNurse.printDetails();

    }
} 
void nurse::getDetails()
{
     int opt = 0;
        cout << "\nOPTIONS:\n[1]: Filter by Name\n[2]: Filter by Type\n[3]: Filter by ID"<<endl<<endl;
        cin >> opt;
        while (opt != 1 && opt != 2 && opt != 3) 
            cout << "option 1 , 2 or 3 ?\n", cin >> opt;
        // 1: Filter by name;
        if (opt == 1)
        {
            string reqFName, reqLName;
            cout << "First Name:"<<endl;
            getline(cin >> ws, reqFName);
            cout << "\nLast Name:"<<endl;
            getline(cin, reqLName);
            for (auto i : hospital::nursesList)
            {
                if (i.second.firstName == reqFName && i.second.lastName == reqLName){
                    cout << " Matching record found!"<<endl;
                    i.second.printDetails();
                }
                    
            }
        }
        // 2: Filter by type;
        else if (opt == 2)
        {
            string reqType;
            cout << "Enter the type of nurse required:"<<endl;
            getline(cin >> ws, reqType);
            for (auto i : hospital::nursesList)
            {
                if (i.second.type == reqType){
                    cout << " Matching record found!"<<endl;
                    i.second.printDetails();
                }
            }   
        }

        if (opt == 3)
    {
        int reqId;
        cout << "\nEnter ID:\n";
        cin >> reqId;

        auto it = hospital::nursesList.find(reqId);
        if (it != hospital::nursesList.end())
        {
            nurse &requestednurse = it->second;
            cout << "Matching record found!\n";
            requestednurse.printDetails();
        }
        else
        {
            cout << "\nNo matching record found!\n";
        }
    }
}

void nurse::removePerson()
{
    int reqId=0;
        cout << "\nSearch for the nurse you want to remove."<<endl;
        getDetails();
        cout<<"\nEnter the id of the nurse you want to remove: "<<endl;
        cin >> reqId;
        if (hospital::nursesList.find(reqId) != hospital::nursesList.end())
            *this = hospital::nursesList[reqId];
        hospital::nursesList.erase(this->id);

}
using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/graph.hh"
#include "./../include/ambulance.hh"
#include "./../include/hospital.hh"

ambulance::ambulance()
{
    id = -1;
    idle = true;
}
ambulance::ambulance(int id, string vrn, bool i)
{
    this->id = id;
    idle = i;
    this->vrn = vrn;
    address = " ";
}
void ambulance::fillMap()
{
    fstream f;
    f.open("ambulances.dat", ios::binary | ios::in);
    int id = 1;
    while (!f.eof())
    {
        f.read(reinterpret_cast<char *>(this), sizeof(ambulance));
        hospital::ambulancesList.insert({id++, *this});
    }
    f.close();
    return;
}
void ambulance::saveMap()
{
    fstream f;
    f.open("temp.dat", ios::binary | ios::out);
    for (auto i : hospital::ambulancesList)
    {
        *this = i.second;
        f.write(reinterpret_cast<char *>(this), sizeof(ambulance));
    }

    f.close();
    remove("ambulances.dat");
    rename("temp.dat", "ambulances.dat");
    return;
}
void ambulance::addAmbulance()
{
    if (hospital::ambulancesList.size() == hospital::ambulancesLimit)
    {
        cout << "\n\nAmbulances limit reached, can't add more!\n\n";
        return;
    }
    // getting the basic details of the ambulance from the user side;
    cout << "\nEnter Vehicle Registration Number of the ambulance:\n";
    getline(cin >> ws, vrn);
    int maxid;
    if (!hospital::ambulancesList.empty())
    {
        maxid = 0;
        for (const auto &pair : hospital::ambulancesList)
        {
            if (pair.first > maxid)
            {
                maxid = pair.first;
            }
        }
        id = maxid+1;
    }
    else
    {
        id = 1;
    }
    hospital ::ambulancesList[id] = *this;

    // creating a fstream object to read/write from/to files;
    fstream f;
    // creating a record in ambulances.dat;
    f.open("ambulances.dat", ios::binary | ios::app);
    f.write(reinterpret_cast<char *>(this), sizeof(ambulance));
    f.close();

    cout << "Ambulance added successfully!\n Its ID is: " << id << "\n";
}
void ambulance::printDetails()
{
    if (id == -1)
        return;
    cout << "Details:\n";
    cout << "ID              : " << id << "\n";
    cout << "Reg Number      : " << vrn << "\n";
    cout << "Idle?           : " << ((idle) ? "Y" : "N") << "\n";
    if (!idle)
    {
        cout << "Going to Address: " << address << endl;
    }
    return;
}

void ambulance::printDetailsFromHistory()
{
    for (auto &entry : hospital::ambulancesList)
    {
        ambulance &currentAmbulance = entry.second;
        currentAmbulance.printDetails();
    }
}
void ambulance::getDetails(int rec)
{
    int opt = 0;
    cout << "\nOPTIONS:\n[1]: Filter by ID\n[2]: Filter by Vehicle Reg. Number\n\n";
    cin >> opt;
    while (opt != 1 && opt != 2)
        cout << "option 1 or 2?\n", cin >> opt;
    // 1: Filter by ID;
    if (opt == 1)
    {
        int reqId;
        cout << "\nEnter ID:\n";
        cin >> reqId;
        if (hospital::ambulancesList.find(reqId) != hospital::ambulancesList.end())
            *this = hospital::ambulancesList[reqId];
        else
            cout << "\nNo matching record found!\n";
    }
    // 2: Filter by vehicle reg. number;
    else if (opt == 2)
    {
        string reqVRN;
        cout << "Enter the vehicle reg. number of ambulance required:\n";
        getline(cin >> ws, reqVRN);
        for (auto i : hospital::ambulancesList)
        {
            if (i.second.vrn == reqVRN)
            {
                *this = i.second;
                return;
            }
        }
        
        cout << "\nNo matching record found!\n";
    }
    return;
}

void ambulance::send()
{

    //picking an idle ambulance;
    bool gotOne = 0;
    for (auto i : hospital::ambulancesList)
    {
        if (i.second.idle)
        {
            *this = i.second;
            gotOne = 1;
            break;
        }
    }
    if (!gotOne)
    {
        cout << "No, idle ambulance found!"
             << "\n";
        return;
    }

    this->idle = 0;

    cout << "Enter destination location:\n";
    cin >> address;

    // updating status of ambulance;
    hospital::ambulancesList[id] = *this;

    cout << "Ambulance ("<<id <<") dispatched successfully!" << endl;
    string source = "Hospital";
    pair<vector<string>, int> result = citygraph.dijkstra(source, address);

    // Print the result
    cout << "Shortest Path from Hospital to " << address << ": ";
    for (string &node : result.first)
    {
        if (node == address)
        {
            cout << node;
            return;
        }
        cout << node << " ,";
    }
    cout << "\nDistance: " << result.second << endl;
    return;
}
void ambulance::reportArrival()
{
    getDetails();
    // updating status of ambulance;
    hospital::ambulancesList[id].idle = 1;
    hospital::ambulancesList[id].address = " ";
    cout << "\nStatus updated successfully!" << endl;
    return;
}
void ambulance::removeAmbulance()
{
    cout << "\nSearch for the ambulance you want to remove.\n";
    getDetails();
    if (id == -1)
        return;
    if (!idle)
    {
        cout << "\nSorry, the ambulance you selected to remove is NOT currently idle.\nOnly idlers can be removed.\n";
        return;
    }
    hospital::ambulancesList.erase(id);
}
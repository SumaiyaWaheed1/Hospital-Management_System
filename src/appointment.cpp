using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/appointment.hh"
#include "./../include/hospital.hh"

appointment::appointment()
{
    id = -1;
    D.id = -1;
    P.id = -1;
}
appointment::~appointment()
{
    id = -1;
    D.id = -1;
    P.id = -1;
    return;
}
void appointment::fillMap()
{
    ifstream f;
    f.open("appointments.dat", ios::binary | ios::in);
    int id = 1;
    while (!f.eof())
    {
        f.read(reinterpret_cast<char *>(this), sizeof(appointment));
        hospital::appointmentsList.insert({id++, *this});
    }
    f.close();
    return;
}
void appointment::saveMap()
{
    fstream f;
    f.open("appointments.dat", ios::binary | ios::out);
    for (auto i : hospital::appointmentsList)
    {
        *this = i.second;
        f.write(reinterpret_cast<char *>(this), sizeof(appointment));
    }
    f.close();
    remove("appointments.dat");
    rename("temp.dat", "appointments.dat");
    return;
}
void appointment::printDetails()
{
    if (id == -1)
        return;
    cout << "\n\n\nAppointment Details:\nID                 : " << id << endl
         << "Patient's Name     : " + P.firstName + " " + P.lastName + "(ID = " << P.id << ")" << endl
         << "Doctor's Name      : " + D.firstName + " " + D.lastName + "(ID = " << D.id << ")" << endl
         << "Time (24 Hr format): " << hh << ":00 Hrs to " << hh + 1 << ":00 Hrs" << endl;
    return;
}
void appointment::book()
{
    int PreqId, DreqId = 0;
    if (hospital::appointmentsList.size() >= 8 * hospital::doctorsList.size())
    {
        cout << "\n\nSorry, no doctor is available for appointment today!" << endl;
        return;
    }
    cout << "\n\nIs the patient already registered (Y : Yes || N : No)?" << endl;
    char ans;
    cin >> ans;
    while (ans != 'Y' && ans != 'N')
    {
        cout << "Y or N?" << endl;
        cin >> ans;
    }
    if (ans == 'N')
    {
        cout << "Register the patient:" << endl;
        P.addPerson();
    }
    else
    {
        cout << "Search for the required patient:" << endl
             << endl;
        ans = 'Y';
        while (ans == 'Y')
        {
            P.getDetails();
            cout << "Enter ID of patient you want: " << endl;
            cin >> PreqId;
            if (hospital::patientsList.find(PreqId) != hospital::patientsList.end())
            {
                P = hospital::patientsList[PreqId];
                ans = 'K';
            }
            else
            {
                cout << "ERROR" << endl;
                cout << "Register the patient:" << endl;
                P.addPerson();
            }

            if (P.id == -1)
            {
                cout << "Patient not registered" << endl;
                return;
            }
        }
    }
    cout << "\n\nNow, search for the required doctor:" << endl;
    ans = 'Y';
    while (ans == 'Y')
    {
        D.getDetails();
        cout << "\nEnter the id of the doctor you want to book appointment with: " << endl;
        cin >> DreqId;
        if (hospital::doctorsList.find(DreqId) != hospital::doctorsList.end())
        {
            D = hospital::doctorsList[DreqId];
            ans = 'K';
        }
        if (D.id == -1)
        {
            cout << "Doctor not found" << endl;
            return;
        }
        else if (D.appointmentsBooked >= 8)
        {
            cout << "Sorry, selected doctor has no free slot left for the day!" << endl;
            cout << "Search for a different doctor? (Y : Yes || N : No)?" << endl;
            cin >> ans;
            while (ans != 'Y' && ans != 'N')
            {
                cout << "Y or N?\n";
                cin >> ans;
            }
        }
    }
    if (ans == 'N')
    {
        return;
    }

    int maxId = 0;
    for (const auto &entry : hospital::appointmentsList)
    {
        if (entry.first > maxId)
        {
            maxId = entry.first;
        }
    }

    id = maxId + 1;
    //appointments start at 9 s0 added appointment time is 9+;
    hh = 9 + D.appointmentsBooked;
    hospital::appointmentsList[id] = *this;

    hospital::doctorsList[D.id].appointmentsBooked++;
    cout << "\nAppointment booked successfully!" << endl;
    printDetails();
    return;
}
void appointment::getDetails()
{
    int reqId = 0;
    cout << "\nEnter appointment ID:\n";
    cin >> reqId;
    ;
    if (hospital::appointmentsList.find(reqId) == hospital::appointmentsList.end())
    {
        cout << "\nInvalid appointment ID!\n";
        reqId = -1;
        return;
    }
    *this = hospital::appointmentsList[reqId];
    return;
}
#include <iostream>
#include <fstream>
#include <string>
#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits
using namespace std;

#include "./src/global.cpp"
#include "./src/hospital.cpp"
#include "./src/person.cpp"
#include "./src/appointment.cpp"
#include "./src/patient.cpp"
#include "./src/doctor.cpp"
#include "./src/nurse.cpp"
#include "./src/ambulance.cpp"
#include "./src/graph.cpp"
#include "./src/OPD.cpp"
#include "./src/doctorbst.cpp"



void appointmentsMenu();
void patientsMenu();
void doctorsMenu();
void nursesMenu();
void ambulancesMenu();
void OPDmenu();

void appointmentsMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/APPOINTMENTS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Book an appointment\n";
        cout << "[02] : Get appointment details\n";
        cout << "[03] : Show all appointments\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            appointment a;
            a.book();
        }
        else if (purpose == 2)
        {
            appointment a;
            a.getDetails();
            a.printDetails();
        }
        else if (purpose == 3)
        {
            hospital::printAppointments();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}
void patientsMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/PATIENTS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Register a new patient\n";
        cout << "[02] : Get patient details\n";
        cout << "[03] : Hospitalize a registered patient\n";
        cout << "[04] : Report a patient's death\n";
        cout << "[05] : Discharge a patient or their body\n";
        cout << "[06] : Get details of all registered patients\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            patient p;
            p.addPerson();
        }
        else if (purpose == 2)
        {
            patient p;
            p.getDetails();
        }
        else if (purpose == 3)
        {
            patient p;
            p.hospitalize();
        }
        else if (purpose == 4)
        {
            patient p;
            p.reportADeath();
        }
        else if (purpose == 5)
        {
            patient p;
            p.removePerson();
        }
        else if (purpose == 6)
        {
            hospital::printPatients();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void doctorsMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/DOCTORS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Register a new doctor\n";
        cout << "[02] : Get doctor details\n";
        cout << "[03] : Remove a doctor\n";
        cout << "[04] : Get details of all registered doctors\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            doctor d;
            d.addPerson();
        }
        else if (purpose == 2)
        {
            doctor d;
            d.getDetails();
        }
        else if (purpose == 3)
        {
            doctor d;
            d.removePerson();
        }
        else if (purpose == 4)
        {
            hospital::printDoctors();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void nursesMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/NURSES\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Register a new nurse\n";
        cout << "[02] : Get nurse details\n";
        cout << "[03] : Remove a nurse\n";
        cout << "[04] : Get details of all registered nurses\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            nurse n;
            n.addPerson();
        }
        else if (purpose == 2)
        {
            nurse n;
            n.getDetails();
        }
        else if (purpose == 3)
        {
            nurse n;
            n.removePerson();
        }
       
        else if (purpose == 4)
        {
            hospital::printNurses();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void ambulancesMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/AMBULANCES\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Add an ambulance\n";
        cout << "[02] : Send an ambulance\n";
        cout << "[03] : Get ambulance details\n";
        cout << "[04] : Report ambulance arrival\n";
        cout << "[05] : Remove an ambulance\n";
        cout << "[06] : Get details of all registered ambulances\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            ambulance a;
            a.addAmbulance();
        }
        else if (purpose == 2)
        {
            ambulance a;
            a.send();
        }
        else if (purpose == 3)
        {
            ambulance a;
            a.getDetails(1);
            a.printDetails();
        }
        else if (purpose == 4)
        {
            ambulance a;
            a.reportArrival();
        }
        else if (purpose == 5)
        {
            ambulance a;
            a.removeAmbulance();
        }
        else if (purpose == 6)
        {
            hospital::printAmbulances();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void OPDmenu()
{
    bool exit = false;
    emergencyOPD OPDpatient;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/OPD\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Emergency Patient\n";
        cout << "[02] : Patient being treated\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;
        
        if (purpose == 1)
        {
            string n1;
            int level;
            cout<<"Enter name of the patient : "<<endl;
            fflush(stdin);
            getline(cin,n1);
            cout<<"Enter the level of emergency on a scale of 1 - 10 "<<endl;
            cin>>level;
            
            OPDpatient.addemergencypatient(n1,level);
            //OPDpatient.processnext();

        }
        else if(purpose == 2)
        {
            OPDpatient.processnext();

        }
        else if(purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
}

int main()
{
    hospital h;
    initializeCityGraph();
    fstream f;
    f.open("appointments.dat", ios::binary|ios::in);
    int dd, mm, yyyy;
    cout << "\nPlease Enter Today's Date (DD-MM-YYYY) :\n\nEnter Day: ";
    cin >> dd;
    while (dd < 1 || dd > 31)
    {
        cout << "Invalid Day! Please enter a valid day: ";
        cin >> dd;
        
    }
    cout << "Enter Month: ";
    cin >> mm;
    while (mm < 1 || mm > 12)
    {
        cout << "Invalid Month! Please enter a valid month: ";
        cin >> mm;
    }
    cout << "Enter Year (YYYY): ";
    cin >> yyyy;
    yyyymmdd = yyyy * 10000 + mm * 100 + dd;
    
    

    while (1)
    {
        int category = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect a category:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : APPOINTMENTS\n";
        cout << "[02] : PATIENTS\n";
        cout << "[03] : DOCTORS\n";
        cout << "[04] : NURSES\n";
        cout << "[05] : OPD\n";
        cout << "[06] : AMBULANCE\n\n";
        cout << "[-1] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> category;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";
        if (category == -1)
        {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "\nShutting Down System...\n";
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            break;
        }
        else if (category == 1)
        {
            appointmentsMenu();
        }
        else if (category == 2)
        {
            patientsMenu();
        }
        else if (category == 3)
        {
            doctorsMenu();
        }
        else if (category == 4)
        {
            nursesMenu();
        }
        else if(category == 5)
        {
            OPDmenu();
        }
        else if (category == 6)
        {
            ambulancesMenu();
        }
        else
        {
            cout << "\nInvalid Choice!\n";
        }

        cout << endl;
    }
    // saving data inside maps by overwriting it on the files
    {
        doctor d1;
        patient p;
        nurse n;
        appointment a2;
        d1.saveMap();
        p.saveMap();
        n.saveMap();
        a2.saveMap();
    }

    return 0;
}

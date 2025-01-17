using namespace std;
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <unordered_map>


#include "./../include/doctor.hh"
#include "./../include/patient.hh"
#include "./../include/nurse.hh"
#include "./../include/ambulance.hh"
#include "./../include/appointment.hh"
#include "./../include/hospital.hh"
#include "./../include/doctorbst.hh"


//defining already declared static members in the global scope;
DoctorBST hospital::doctorTree;


//defining already declared static members in the global scope;

unordered_map<int, doctor> hospital::doctorsList;
unordered_map<int, patient> hospital::patientsList;
unordered_map<int, nurse> hospital::nursesList;
unordered_map<int, appointment> hospital::appointmentsList;
unordered_map<int, ambulance> hospital::ambulancesList;

const int hospital::doctorsLimit = 30;
const int hospital::nursesLimit = 50;
const int hospital::ambulancesLimit = 10;
const int hospital::appointmentsLimit = 240; //per day;


//defining already declared methods;
hospital::hospital(){
    doctor d1(1,"Imran","Khan",'M',43,15673930,"15, M. A. Jinnah Road,Kharadar, Saddar, Karachi,Pakistan","Cardiologist",2);
    doctor d2(2,"Isabella","Cullen",'F',28,82663939,"A-25,ST-4,PECHS ,Karachi,Pakistan","Physician",4);
    doctor d3(3,"Ali","Majeed",'M',40,19483487,"B-10, Garden West,Karachi,Pakistan","Cardiologist",1);
    doctor d4(4,"Rukhsana","Farhat",'F',55,78829302,"A-1, National Complex, Rshid Minhas Road,Karachi,Pakistan","Psychatrist",0);
    doctor d5(5,"Sana","Jaffar",'F',29,23809172,"E-9/2, Popular street, DHA Phase VII,Karachi,Pakistan","Neurologist",0);
    doctor d6(6,"Akram","Khan",'M',31,87291686,"B-378, Lion street, FB Area,Karachi,Pakistan","OPD",0);
    
    nurse n1(1,"Mariam","Sohail",'F',30,78348399,"C-9, Farhan Tower, Gulistan e Johar, Karachi,Pakistan","Neurology");
    nurse n2(2,"Naveed","Khan",'M',35,88499291,"112, St-12, Lyari, Karachi,Pakistan","General");
    nurse n3(3,"Farhana","Baig",'F',42,94840238,"405, Sky Apartments, Saddar, Karachi,Pakistan","General");
    patient p1(1,"Aima","Shaheer",'F',34,23934881,"41, Falak Apartments, Gulistan e Johar, Karachi,Pakistan",160,110,1,1);
    patient p2(2,"Farhan","Malik",'M',59,63748720,"B-29, Khayaban e Rahat, DHA Phase VI, Karachi,Pakistan",180,150,0,1);
    patient p3(3,"Sameer","Niaz",'M',21,47384392,"A-10, G Allana Road Kharadar, Karachi,Pakistan",159,110,1,0);
    ambulance a1(1,"ARN-425",1);
    hospital::doctorsList.insert({1, d1});
    hospital::doctorsList.insert({2, d2});
    hospital::doctorsList.insert({3, d3});
    hospital::doctorsList.insert({4, d4});
    hospital::doctorsList.insert({5, d5});
    hospital::doctorsList.insert({6, d6});
    hospital::nursesList.insert({1, n1});
    hospital::nursesList.insert({2, n2});
    hospital::nursesList.insert({3, n3});
    hospital::patientsList.insert({1, p1});
    hospital::patientsList.insert({2, p2});
    hospital::patientsList.insert({3, p3});
    hospital::ambulancesList.insert({1,a1});
    for (auto &it : hospital::doctorsList)
    {
        doctorTree.insert(it.second);
    }


}
void hospital::printDoctors()
{
    doctor d;
    d.printDetailsFromHistory();
}
void hospital::printPatients()
{
    patient p;
    p.printDetailsFromHistory();
}
void hospital::printNurses()
{
    nurse n;
    n.printDetailsFromHistory();
}
void hospital::printAppointments()
{
    for (auto i: appointmentsList)
    {
        i.second.printDetails();
    }
}
void hospital::printAmbulances()
{
    for (auto i : ambulancesList)
        i.second.printDetails(), cout << "\n";
    return;
}
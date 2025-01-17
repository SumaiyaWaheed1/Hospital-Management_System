#ifndef HOSPITAL
#define HOSPITAL
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include "./doctor.hh"
#include "./patient.hh"
#include "./nurse.hh"
#include "./ambulance.hh"
#include "./appointment.hh"
#include "./graph.hh"
#include "./OPD.hh"
#include "./doctorbst.hh"

class hospital
{
protected:
    //map<id, object>
    static unordered_map<int, doctor> doctorsList;
    static unordered_map<int, patient> patientsList;
    static unordered_map<int, nurse> nursesList;
    static unordered_map<int, appointment> appointmentsList;
    static unordered_map<int, ambulance> ambulancesList;

    static const int doctorsLimit;
    static const int nursesLimit;
    static const int ambulancesLimit;
    static const int appointmentsLimit;



    friend class doctor;
    friend class patient;
    friend class nurse;
    friend class ambulance;
    friend class appointment;
    friend class emergencyOPD;
    friend class graph;
    friend class emergencypriorityqueue;

public: 
    hospital();
    static DoctorBST doctorTree;
    static void printDoctors();
    static void printPatients();
    static void printNurses();
    static void printAppointments();
    static void printAmbulances();
};

#endif // !HOSPITAL
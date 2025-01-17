#ifndef OPD
#define OPD
using namespace std;
#include<iostream>
#include<queue>
#include<string>

#include "./patient.hh"
#include "./doctor.hh"
#include "./nurse.hh"
#include "./hospital.hh"

class emergencypatient
{
  public:   
     string name;
     int emergencylevel;    
};

class emergencypriorityqueue
{
     public:
     vector<emergencypatient> emergencyqueue;
     void heapifyup(int index);
     void heapifydown(int index);
     void push(const emergencypatient& pat);
     void pop();
     const emergencypatient& top()const;
     bool empty()const;
     size_t size()const;

};

class emergencyOPD
{
    private:
    

    friend class doctor;
    friend class nurse;
    friend class patient;
    friend class person;

    public:
     emergencypriorityqueue emergencyqueue;

     void addemergencypatient(string name,int elevel);
     void processnext();



};
#endif // OPD
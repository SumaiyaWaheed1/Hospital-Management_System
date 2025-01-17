#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#include "./../include/global.hh"
#include "./../include/doctor.hh"
#include "./../include/patient.hh"
#include "./../include/nurse.hh"
#include "./../include/OPD.hh"
#include "./../include/hospital.hh"

void emergencypriorityqueue ::heapifyup(int index)
{
    while (index > 0)
    {
        int parentIndex = (index - 1) / 2;
        if (emergencyqueue[index].emergencylevel > emergencyqueue[parentIndex].emergencylevel)
        {
            swap(emergencyqueue[index], emergencyqueue[parentIndex]);
            index = parentIndex;
        }
        else
        {
            break;
        }
    }
}

void emergencypriorityqueue :: heapifydown(int index)
{
    int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int highestPriority = index;

        if (leftChild < emergencyqueue.size() && emergencyqueue[leftChild].emergencylevel > emergencyqueue[highestPriority].emergencylevel) {
            highestPriority = leftChild;
        }

        if (rightChild < emergencyqueue.size() && emergencyqueue[rightChild].emergencylevel > emergencyqueue[highestPriority].emergencylevel) {
            highestPriority = rightChild;
        }

        if (highestPriority != index) {
            swap(emergencyqueue[index], emergencyqueue[highestPriority]);
            heapifydown(highestPriority);
        }
}

void emergencypriorityqueue :: push(const emergencypatient& pat)
{
    emergencyqueue.push_back(pat);
        heapifyup(emergencyqueue.size() - 1);
}


void emergencypriorityqueue :: pop()
{
    if(!empty())
    {
        swap(emergencyqueue[0],emergencyqueue.back());
        emergencyqueue.pop_back();
        heapifydown(0);
    }
}

bool emergencypriorityqueue :: empty()const
{
    return emergencyqueue.empty();

}
const emergencypatient& emergencypriorityqueue:: top() const
{
    if (!empty()) 
    {
            return emergencyqueue[0];
        
     }
  throw out_of_range("Priority queue is empty.");
}

size_t emergencypriorityqueue :: size()const
{
    return emergencyqueue.size();

}

void emergencyOPD ::addemergencypatient(string n1, int elevel)
{
    emergencypatient epatient;
    epatient.name = n1;
    epatient.emergencylevel = elevel;
    emergencyqueue.push(epatient);
    cout << "Emergency case registered succesfully." << endl;
    auto it = find_if(hospital::doctorsList.begin(), hospital::doctorsList.end(), [](const auto &doctorPair)
            { return (doctorPair.second.isavailable && doctorPair.second.type == "OPD"); });
        doctor currentdoctor = it->second;
        cout << "Available Doctor: ";
        currentdoctor.printDetails();
        currentdoctor.isavailable=false;

    return;
}

void emergencyOPD ::processnext()
{
    auto it = hospital ::doctorsList.end();
    if (!emergencyqueue.empty())
    {

        emergencypatient nextpatient = emergencyqueue.top();
        emergencyqueue.pop();
        cout << "Processing emergency case for patient : " << nextpatient.name << endl;
        cout << "Emergency Level : " << nextpatient.emergencylevel << endl;

        auto it = find_if(hospital::doctorsList.begin(), hospital::doctorsList.end(), [](const auto &doctorPair)
            { return (doctorPair.second.isavailable && doctorPair.second.type == "OPD"); });
        doctor currentdoctor = it->second;
        currentdoctor.isavailable=true;
        cout <<"Dr."<<currentdoctor.firstName <<" is now available for next patient."<<endl;
       
    }
    else
    {
        cout << "No emergency cases currently " << endl;
    }
    return;
}
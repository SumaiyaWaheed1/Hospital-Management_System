using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include<map>
#include<list>

#include "./../include/global.hh"
#include "./../include/doctor.hh"
#include "./../include/hospital.hh"
#include "./../include/person.hh"
#include "./../include/doctorbst.hh"

DoctorBST :: DoctorBST()
{ }
void DoctorBST::insert(const doctor& d) 
{
    root = insertRecursive(root, d);
}

DoctorBST::Node* DoctorBST::insertRecursive(Node* node, const doctor& d )
{
    if (node == NULL) 
    {
        Node* newNode = new Node;
        newNode->doctors.push_back(d);
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    // Compare based on specialization
    if (d.type < node->doctors.front().type) {
        node->left = insertRecursive(node->left, d);
    } else if (d.type > node->doctors.front().type) {
        node->right = insertRecursive(node->right, d);
    } else {
        // Specialization is the same, insert into the list
        node->doctors.push_back(d);
    }

    return node;
}


void DoctorBST:: Search(const string& specialization) const
{
    Node* current = root;
    while (current != NULL) 
    {
        // Compare based on specialization
        if (specialization < current->doctors.front().type) 
        {
            current = current->left;
        } else if (specialization > current->doctors.front().type) 
        {
            current = current->right;
        } else 
        {
            // Specialization matches, return the vector of doctors
            for ( auto d : current->doctors) {
                d.printDetails();
                cout << "----------------------\n"; 
                
            }
            return;
        }
    }
    cout<<"Not found!"<<endl;

}
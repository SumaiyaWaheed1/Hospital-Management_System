#ifndef DOCTORBST_H
#define DOCTORBST_H

#include "./doctor.hh"
#include <list>

class DoctorBST {
public:
    struct Node {
        std::list<doctor> doctors; // Use a list to store doctors with the same specialization
        Node* left;
        Node* right;
    };

    Node* root;

public:
    DoctorBST();
    void insert(const doctor& doctor);
    Node* insertRecursive(Node* node, const doctor& d );
    void Search(const std::string& specialization) const;
};

#endif // DOCTORBST_H
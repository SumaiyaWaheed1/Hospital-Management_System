using namespace std;
#include<string>

#include "./../include/global.hh"
#include "./../include/graph.hh"

int yyyymmdd;
Graph citygraph;

void initializeCityGraph() {
    citygraph.addVertex("Hospital", {{"GulshanIqbal", 3}, {"Clifton", 10}, {"FB Area", 6}});
    citygraph.addVertex("GulshanIqbal", {{"Hospital", 3}, {"NorthNazimabad", 11}, {"DHA", 15}, {"Guru Mandir", 14}, {"FB Area", 8}, {"Korangi", 11}});
    citygraph.addVertex("NorthNazimabad", {{"FB Area", 9}, {"GulshanIqbal", 11}});
    citygraph.addVertex("Clifton", {{"Hospital", 10}, {"DHA", 2},{"Bahadurabad", 12}});
    citygraph.addVertex("FB Area", {{"Hospital", 6}, {"PECHS", 10},{"GulshanIqbal", 8}, {"NorthNazimabad", 9}});
    citygraph.addVertex("DHA", {{"Clifton", 2}, {"GulshanIqbal", 15},{"Korangi", 5},{"Saddar", 8}});
    citygraph.addVertex("Bahadurabad", {{"PECHS", 2}, {"Clifton", 12}});
    citygraph.addVertex("PECHS", {{"FB Area", 10},{"Bahadurabad", 2}});
    citygraph.addVertex("Korangi", {{"GulshanIqbal", 11}, {"DHA", 5},{"Saddar", 13},{"Guru Mandir", 9}});
    citygraph.addVertex("Guru Mandir", {{"GulshanIqbal", 14},{"Korangi", 9}});
    citygraph.addVertex("Saddar", {{"DHA", 8},{"Korangi", 13}});

}


#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <string>
using namespace std;


class Graph {
public:
    Graph();
    unordered_map<string, unordered_map<string, int>> vertices;
    void addVertex(const string &name, const unordered_map<string, int> &edges);
    pair<vector<string>, int> dijkstra(const string &start, const string &end);


};

#endif // GRAPH_H

#include "./../include/graph.hh"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

Graph::Graph() {}

void Graph::addVertex(const string &name, const unordered_map<string, int> &edges)
{
    vertices[name] = edges;
}

pair<vector<string>, int> Graph:: dijkstra(const string &source, const string &target)
{
    unordered_map<string, bool> visited;
    unordered_map<string, int> distance;
    unordered_map<string, string> previous;

    // Initialize distances and previous vertices
    for (const auto &vertex : vertices)
    {
        visited[vertex.first] = false;
        distance[vertex.first] = numeric_limits<int>::max();
        previous[vertex.first] = "";
    }
    // Distance from the source to itself is 0
    distance[source] = 0;

    while (!visited[target])
    {
        // Find the vertex with the minimum distance
        string selectedNode;
        int minDistance = numeric_limits<int>::max();

        for (const auto &vertex : vertices)
        {
            if (!visited[vertex.first] && distance[vertex.first] < minDistance)
            {
                minDistance = distance[vertex.first];
                selectedNode = vertex.first;
            }
        }

        // Mark the selected node as visited
        visited[selectedNode] = true;

        // Update distances and previous nodes for neighbors of the selected node
        for (const auto &neighbor : vertices[selectedNode])
        {
            if (!visited[neighbor.first])
            {
                int alt = distance[selectedNode] + neighbor.second;
                if (alt < distance[neighbor.first])
                {
                    distance[neighbor.first] = alt;
                    previous[neighbor.first] = selectedNode;
                }
            }
        }

    }

    // Reconstruct the path
    vector<string> path;
    for (string vertex = target; !vertex.empty(); vertex = previous[vertex])
    {
        path.push_back(vertex);
    }

    reverse(path.begin(), path.end());
    return make_pair(path, distance[target]);
}





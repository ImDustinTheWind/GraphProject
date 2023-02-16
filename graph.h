/**********************************************
Name: Dustin Sherer
Coding Final Project
Purpose: Assignment designed to better understand the
    graph data structure through building one.
**********************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include "data.h"

class Graph {

public:

    Graph();
    ~Graph();

    //basic methods
    bool addVertex(int, std::string*);
    bool addEdge(int, int, bool);
    bool removeVertex(int);
    bool removeEdge(int, int, bool);
    bool isEmpty();
    int getNumVerticies();
    int getNumEdges();
    int getNumVertEdges(int);
    void getVertData(int, std::string&);
    std::vector<int> getListVerticies();
    std::vector<int> getListVertEdges(int);
    std::vector<int> depthFirstTraversal(int);
    std::vector<int> breadthFirstTraversal(int);
    bool clearGraph();

private:

    bool edgeExists(int, int);
    void depthFirstTraversal(int, std::vector<int>&, std::map<int, bool>&);
    void breadthFirstTraversal(int, std::vector<int>&, std::map<int, bool>&, std::queue<int>&);

    std::map<int, Vertex, std::less<int>> graphVerts;
    int edgeCount = 0;

};

#endif //GRAPH_H
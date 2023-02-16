/**********************************************
Name: Dustin Sherer
Coding Final Project
Purpose: Assignment designed to better understand the
    graph data structure through building one.
**********************************************/

#ifndef GRAPH_DATA_H
#define GRAPH_DATA_H

#include <list>
#include <string>

struct Vertex {
    std::string data = "";
    std::list<int> edges;
};

#endif //GRAPH_DATA_Hedges
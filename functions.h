/**********************************************
Name: Dustin Sherer
Coding Final Project
Purpose: Assignment designed to better understand the
    graph data structure through building one.
**********************************************/

#ifndef GRAPH_FUNCTIONS_H
#define GRAPH_FUNCTIONS_H

#define RANDOM_STR_SIZE 9
#define MAX_RANDOM_INT 250

#include <iostream>
#include <list>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

#include "graph.h"

//status functions
void checkGraphStatus(Graph&);
void checkEdges(Graph&);

//print functions
void printVector(const std::vector<int>&);

//data generators
int getRandomInt();
std::string getRandomString();

#endif //GRAPH_FUNCTIONS_H
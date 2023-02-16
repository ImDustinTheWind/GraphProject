/**********************************************
Name: Dustin Sherer
Coding Final Project
Purpose: Assignment designed to better understand the
    graph data structure through building one.
**********************************************/

#include "functions.h"




//**********************************************************
// print status
//**********************************************************
void checkGraphStatus(Graph& graph) {
    std::cout << "\n\n***Checking Graph Status***";
    // check isEmpty
    std::cout << "\nChecking if graph empty...";
    if (graph.isEmpty()) {
        std::cout << "graph IS Empty.";
    }
    else { std::cout << "graph IS NOT Empty."; }

    // check number of vertices
    std::cout << "\nNumber of vertices..." << graph.getNumVerticies();

    // check number of edges
    std::cout << "\nNumber of edges..." << graph.getNumEdges();

    //print graph
    std::cout << "\nID numbers in graph...";
    printVector(graph.getListVerticies());
}

void checkEdges(Graph& graph) {
    std::cout << "\n***Checking Edges***\n";
    std::vector<int> current = graph.getListVerticies();
    for (auto& vert : graph.getListVerticies()) {
        std::cout << "Vertex [" << vert << "] | edges: " << graph.getNumVertEdges(vert) << " | ";
        printVector(graph.getListVertEdges(vert));
    }
}

//**********************************************************
// print functions 
//**********************************************************
void printVector(const std::vector<int>& vectors) {
    std::cout << "IDs : [ ";
    for (auto& elem : vectors) {
        std::cout << elem << " ";
    }
    std::cout << "]\n";
}

//**********************************************************
// random data generators 
//**********************************************************
int getRandomInt() {
//     srand(time(NULL));
    int randomInt = rand() % MAX_RANDOM_INT + 1;
    return randomInt;
}
std::string getRandomString() {
    char randomStr[RANDOM_STR_SIZE];
    for (int j = 0; j < RANDOM_STR_SIZE - 1; j++) {
        randomStr[j] = rand() % 2 ? (rand() % (26)) + 'A' : (rand() % (26)) + 'a';
    }
    randomStr[RANDOM_STR_SIZE - 1] = '\0';

    return randomStr;
}
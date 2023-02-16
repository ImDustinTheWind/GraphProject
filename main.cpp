/**********************************************
Name: Dustin Sherer
Coding Final Project
Purpose: Assignment designed to better understand the
    graph data structure through building one.
**********************************************/

#include "main.h"

int main() {
    std::cout << "Welcome to the Final Countdown!\n";
    srand(time(NULL));//seed random numbers

    Graph graph1;

    std::cout << "\nStatus check on empty graph...";
    checkGraphStatus(graph1);

    //**********************************************************
    // test addVertex()
    //**********************************************************
    int tempInt = getRandomInt();
    std::string tempString = getRandomString();
    graph1.addVertex(tempInt, &tempString);
    std::cout << "\nStatus check after addVertex()...";
    checkGraphStatus(graph1);

    //**********************************************************
    // test removeVertex()
    //**********************************************************
    std::cout << "Removing Vertex...";
    if (graph1.removeVertex(tempInt)) {
        std::cout << "vertex removed\n";
    }
    else { std::cout << "vertex not-removed\n"; }
    checkGraphStatus(graph1);

    //**********************************************************
    // test multiple addVertex()
    //**********************************************************
    std::cout << "\n\nTesting Add Vertex...\n";
    bool addVert = false;
    for (int i = 0; i < 10; i++) {
        bool addVert = false;
        tempInt = getRandomInt() * -1;
        tempString = getRandomString();
        std::cout << "\nadding vertex [" << tempInt << "] [" << tempString << "]...";
        addVert = graph1.addVertex(tempInt, &tempString);
        if (addVert) {
            std::cout << "Success";
        }
        else { std::cout << "Fail"; }
    }
    for (int i = 0; i < 5; i++) {
        bool addVert = false;
        tempInt = getRandomInt();
        tempString = "";
        std::cout << "\nadding vertex [" << tempInt << "] [" << tempString << "]...";
        addVert = graph1.addVertex(tempInt, &tempString);
        if (addVert) {
            std::cout << "Success";
        }
        else { std::cout << "Fail"; }
    }
    for (int i = 0; i < 350; i++) {
        bool addVert = false;
        tempInt = getRandomInt();
        tempString = getRandomString();
        std::cout << "\nadding vertex [" << tempInt << "] [" << tempString << "]...";
        addVert = graph1.addVertex(tempInt, &tempString);
        if (addVert) {
            std::cout << "Success";
        }
        else { std::cout << "Fail"; }
    }
    checkGraphStatus(graph1);

    //**********************************************************
    // test multiple removeVertex()
    //**********************************************************
    std::cout << "\n\nTesting Remove Vertex...\n";
    for (int i = 0; i < 50; i++) {
        bool isRemoved = false;
        tempInt = getRandomInt();
        std::cout << "\nremoving id: [" << tempInt << "]...";
        isRemoved = graph1.removeVertex(tempInt);
        if (isRemoved) {
            std::cout << "Success";
        }
        else { std::cout << "Fail"; }
    }
    checkGraphStatus(graph1);

    //**********************************************************
    // test multiple addEdge()
    //**********************************************************
    std::cout << "\n\nTesting Add Edge...\n";
    int addEdgeSuccess = 0;
    bool isAdded = false;
    for (int j = -20; j < 0; j++) {
        isAdded = false;
        int tempInt1 = getRandomInt() * -1;
        int tempInt2 = getRandomInt() * -1;
        std::cout << "\nadding edge [" << tempInt1 << "] -> [" << tempInt2 << "] : ";
        isAdded = graph1.addEdge(tempInt1, tempInt2, true);
        if (isAdded) {
            std::cout << "Success";
            addEdgeSuccess++;
        }
        else { std::cout << "Fail"; }
    }
    for (int i = 0; i < 350; i++) {
        isAdded = false;
        int tempInt1 = getRandomInt();
        int tempInt2 = getRandomInt();
        std::cout << "\nadding edge [" << tempInt1 << "] -> [" << tempInt2 << "] : ";
        isAdded = graph1.addEdge(tempInt1, tempInt2, true);
        if (isAdded) {
            std::cout << "Success";
            addEdgeSuccess++;
        }
        else { std::cout << "Fail"; }
    }
    std::cout << "\nNumber of addEdge() Successes: " << addEdgeSuccess;
    std::cout << "\n\nadding edge to duplicate vert...";
    std::cout << "[" << 51 << "] -> [" << 51 << "] : ";
    isAdded = graph1.addEdge(51, 51, true);
    if (isAdded) {
        std::cout << "Success";
    }
    else { std::cout << "Fail"; }
    std::cout << "\n\n";
    checkEdges(graph1);
    checkGraphStatus(graph1);

    //**********************************************************
    // test multiple removeEdge()
    //**********************************************************
    std::cout << "\n\nTesting Remove Edge...\n";
    int removeEdgeSuccess = 0;
    std::vector<int> removeFrom = graph1.getListVerticies();
    for (auto& vert : removeFrom) {
        for (int i = 0; i < 1; i++) {
            bool isRemoved = false;
            int tempInt = getRandomInt();
            std::cout << "\nremoving edge: [" << vert << "] -> [" << tempInt << "] : ";
            isRemoved = graph1.removeEdge(vert, tempInt, true);
            if (isRemoved) {
                std::cout << "Success";
                removeEdgeSuccess++;
            }
            else { std::cout << "Fail"; }
        }
    }
    std::cout << "\nNumber of removeEdge() Successes: " << removeEdgeSuccess;
    std::cout << "\n\n";
    checkEdges(graph1);
    checkGraphStatus(graph1);

    //**********************************************************
    // test depthFirstTraversal()
    //**********************************************************
    std::cout << "\n\nTesting Depth-First Traversal...\n";
    for (auto& vert : graph1.getListVerticies()) {
        std::vector<int> visitOrder;
        std::cout << "start point (" << vert << ") :";
        visitOrder = graph1.depthFirstTraversal(vert);
        printVector(visitOrder);
    }
    std::cout << "\n\n";
    checkEdges(graph1);
    checkGraphStatus(graph1);

    //**********************************************************
    // test breadthFirstTraversal()
    //**********************************************************
    std::cout << "\n\nTesting Breadth-First Traversal...\n";
    for (auto& vert : graph1.getListVerticies()) {
        std::vector<int> visitOrder;
        std::cout << "start point (" << vert << ") :";
        visitOrder = graph1.breadthFirstTraversal(vert);
        printVector(visitOrder);
    }
    std::cout << "\n\n";
    checkEdges(graph1);
    checkGraphStatus(graph1);

    //**********************************************************
    // test random operations - stress testing
    //**********************************************************
    Graph graph2;
    srand(time(nullptr)); //seed random numbers
    int addVrtCnt = 0;
    int addEdgCnt = 0;
    int rmvVrtCnt = 0;
    int rmvEdgCnt = 0;
    int successCnt = 0;
    std::cout << "\n=====STRESS TEST=====\n" << std::endl << std::endl;

    for (int k = 0; k < 1500; k++) {
        int whichMethod = rand();
        int tempIntStress = 0;
        std::string tempStrStress = "";
        bool success = false;
        bool bidirect = (rand() % 2 == 0);

        if (whichMethod % 5 == 0) { //addEdge
            for (int i = 0; i < 5; i++) {
                int tempInt1 = getRandomInt();
                int tempInt2 = getRandomInt();
                std::cout << "\nadding edge [" << tempInt1 << "] -> [" << tempInt2 << "] : ";
                success = graph2.addEdge(tempInt1, tempInt2, bidirect);
                if (success) {
                    std::cout << "Success";
                }
                else { std::cout << "Fail"; }
                addEdgCnt++;
            }
        }
        else if (whichMethod % 4 == 0) { //removeVertex
            tempInt = getRandomInt();
            std::cout << "\nremoving id: [" << tempInt << "]...";
            success = graph2.removeVertex(tempInt);
            if (success) {
                std::cout << "Success";
            }
            else { std::cout << "Fail"; }
            rmvVrtCnt++;
        }
        else if (whichMethod % 3 == 0) { //removeEdge
            int tempInt1 = getRandomInt();
            int tempInt2 = getRandomInt();
            std::cout << "\nremoving edge: [" << tempInt1 << "] -> [" << tempInt2 << "] : ";
            success = graph2.removeEdge(tempInt1, tempInt, bidirect);
            if (success) {
                std::cout << "Success";
            }
            else { std::cout << "Fail"; }
            rmvEdgCnt++;
        }
        else { //addVertex
            for (int i = 0; i < 5; i++) {
                tempInt = getRandomInt();
                tempString = getRandomString();
                std::cout << "\nadding vertex [" << tempInt << "] [" << tempString << "]...";
                success = graph2.addVertex(tempInt, &tempString);
                if (success) {
                    std::cout << "Success";
                }
                else { std::cout << "Fail"; }
                addVrtCnt++;
            }
        }
        if (success) {
            successCnt++;
        }
        if (k % 50 == 0) {
            checkGraphStatus(graph2);
            std::cout << "\nOperation Counts | Add-Vertex:" << addVrtCnt << " | Add-Edge:" << addEdgCnt
                << " | Remove-Vertex:" << rmvVrtCnt << " | Remove-Edge: " << rmvEdgCnt << std::endl;
            std::cout << "Total Successful Operations: " << successCnt << std::endl;
        }

    }
    checkGraphStatus(graph2);
    std::cout << "\nOperation Counts | Add-Vertex:" << addVrtCnt << " | Add-Edge:" << addEdgCnt
        << " | Remove-Vertex:" << rmvVrtCnt << " | Remove-Edge: " << rmvEdgCnt << std::endl;
    std::cout << "Total Successful Operations: " << successCnt << std::endl;
    checkEdges(graph2);
}
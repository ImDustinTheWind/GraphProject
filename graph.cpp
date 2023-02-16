/**********************************************
Name: Dustin Sherer
Coding Final Project
Purpose: Assignment designed to better understand the
    graph data structure through building one.
**********************************************/

#include "graph.h"

Graph::Graph() {

}

Graph::~Graph() {
    clearGraph();
}

bool Graph::addVertex(int id, std::string* data) {
    bool isSuccess = false;
    if (id > 0 && *data != "") {
        int beforeSize = graphVerts.size();
        Vertex newVert;
        newVert.data = *data;
        graphVerts.insert(std::pair<int, Vertex>(id, newVert));
        if (beforeSize < graphVerts.size()) {
            isSuccess = true;
        }
    }
    return isSuccess;
}

bool Graph::addEdge(int id1, int id2, bool bidirectional) {
    bool isSuccess = false;
    std::map<int, Vertex, std::less<int>>::iterator it1 = graphVerts.find(id1);
    std::map<int, Vertex, std::less<int>>::iterator it2 = graphVerts.find(id2);
    if ((id1 != id2) && (it1 != graphVerts.end()) && (it2 != graphVerts.end()) && (!edgeExists(id1, id2))) {
        graphVerts[id1].edges.push_back(id2);
        if (bidirectional) { graphVerts[id2].edges.push_back(id1); }
        edgeCount++;
        isSuccess = true;
    }
    return isSuccess;
}

bool Graph::removeVertex(int id) {
    bool isSuccess = false;
    if (id > 0) {
        std::map<int, Vertex, std::less<int>>::iterator it = graphVerts.find(id);
        if (it != graphVerts.end()) {
            graphVerts.erase(it);
            isSuccess = true;
        }
    }
    return isSuccess;
}

bool Graph::removeEdge(int id1, int id2, bool bidirectional) {
    bool isSuccess = false;
    std::map<int, Vertex, std::less<int>>::iterator it1 = graphVerts.find(id1);
    std::map<int, Vertex, std::less<int>>::iterator it2 = graphVerts.find(id2);
    if ((id1 != id2) && (it1 != graphVerts.end()) && (it2 != graphVerts.end())) {
        int beforeSize = graphVerts[id1].edges.size();
        graphVerts[id1].edges.remove(id2);
        if (beforeSize > graphVerts[id1].edges.size()) {
            if (bidirectional) { graphVerts[id2].edges.remove(id1); }
            edgeCount--;
            isSuccess = true;
        }
    }
    return isSuccess;
}

bool Graph::isEmpty() {
    return graphVerts.empty();
}

int Graph::getNumVerticies() {
    return graphVerts.size();
}

int Graph::getNumEdges() {;
    return edgeCount;
}

int Graph::getNumVertEdges(int id) {
    int numEdges = 0;
    std::map<int, Vertex, std::less<int>>::iterator it = graphVerts.find(id);
    if (it != graphVerts.end()) {
        for (auto& eds : graphVerts[id].edges) {
            numEdges++;
        }
    }
    return numEdges;
}

void Graph::getVertData(int id, std::string& data) {
    std::map<int, Vertex, std::less<int>>::iterator it = graphVerts.find(id);
    if (it != graphVerts.end()) {
        data = graphVerts[id].data;
    }
}

std::vector<int> Graph::getListVerticies() {
    std::vector<int> vertList;
    for (auto& vertex : graphVerts) {
        vertList.push_back(vertex.first);
    }
    return vertList;
}

std::vector<int> Graph::getListVertEdges(int id) {
    std::vector<int> edgeList;
    std::map<int, Vertex, std::less<int>>::iterator it = graphVerts.find(id);
    if (it != graphVerts.end()) {
        for (auto& edge : graphVerts[id].edges) {
            edgeList.push_back(edge);
        }
    }
    return edgeList;
}

bool Graph::edgeExists(int id1, int id2) {
    bool exists = false;
    std::vector<int> edgeWith2 = getListVertEdges(id1);
    for (auto edge : edgeWith2) {
        if (id2 == edge) {
            exists = true;
        }
    }
    return exists;
}

std::vector<int> Graph::depthFirstTraversal(int startID) {
    std::vector<int> visitOrder;
    std::map<int, bool> visited;
    for (auto vert : graphVerts) {
        visited.insert(std::pair<int, bool>(vert.first, false));
    }
    depthFirstTraversal(startID, visitOrder, visited);
    return visitOrder;
}

void Graph::depthFirstTraversal(int startID, std::vector<int>& visitOrder, std::map<int, bool>& visited) {
    visited.at(startID) = true;
    visitOrder.push_back(startID);
    graphVerts[startID].edges.sort();

    if (!graphVerts[startID].edges.empty()) {
        for (auto edge : graphVerts[startID].edges) {
            if (!visited.at(edge)) {
                depthFirstTraversal(edge, visitOrder, visited);
            }
        }
    }
}

std::vector<int> Graph::breadthFirstTraversal(int startID) {
    std::vector<int> visitOrder;
    std::map<int, bool> touched;
    std::queue<int> discoverQueue;
    for (auto vert : graphVerts) {
        touched.insert(std::pair<int, bool>(vert.first, false));
    }
    breadthFirstTraversal(startID, visitOrder, touched, discoverQueue);
    return visitOrder;
}

void Graph::breadthFirstTraversal(int startID, std::vector<int>& visitOrder, 
    std::map<int, bool>& touched, std::queue<int>& discoverQueue) {
    touched.at(startID) = true;
    visitOrder.push_back(startID);
    graphVerts[startID].edges.sort();

    if (!graphVerts[startID].edges.empty()) {
        for (auto edge : graphVerts[startID].edges) {
            if (!touched.at(edge)) {
                touched.at(edge) = true;
                discoverQueue.push(edge);
            }
        }
        if (!discoverQueue.empty()) {
            startID = discoverQueue.front();
            discoverQueue.pop();
            breadthFirstTraversal(startID, visitOrder, touched, discoverQueue);
        }
    }
}

bool Graph::clearGraph() {
    graphVerts.clear();
    return isEmpty();
}


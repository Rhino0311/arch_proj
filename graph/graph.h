/***********************************************************
Name: Tomas Vasquez, Benjamin Swann, Jesus Rivera III
Assignment: Final Project
Purpose: This program opens 3 diff files based on user input from command line (conducts basic file validation checks), 
and conducts graph operations based on if they are weighted or not and writes original contents to a file. The file operations: 
Breath First Search, Depth First Search, add a vertex, delete a vertex, conduct checks for duplicates(edges or vertex), check 
to delete an existing node, and checks connectivity and provides a list of items not connected.
Notes: Operations: Breath First Search, Depth First Search, add/ delete (vertex/edge) and write to file (example.txt).
***********************************************************/

#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include "data.h"

using namespace std;
class Graph 
{ 
private:
    int size;                              // No. of vertices 
    bool directionalUnweighted; 
    bool weighted;
     
    std::list<Node> *adj;                       // Pointer to an array containing adjacency lists
    bool *vertices;
    int findWeight(int row, int col);
    int numEdgeCount;                         //edge count
    int numVertexCount;                      // vertex count

public: 
    Graph(int, bool);                           // Constructor 
    ~Graph();                                   // Destructor 
    bool addEdge(int v, int w, int weight=0);   // Add w to v’s list. Unweighted defaults to zero
    bool addVertice(int);   
    void BFS(int s, bool hasLables);                            // BFS traversal from a given source s
    void DFSUtil(int v, bool visited[], bool hasLables);
    void DFS(int v, bool hasLables);                            // DFS traversal of vertices reachable from v   
    void print(bool hasLables);
    bool removeEdge(int, int); 
    bool removeVertex(int);
    int numVertex();      
    int numEdges();
    void listDisconnected(bool hasLables);  
    bool isConnected(); 
    void display(bool hasLables);  
    char conversion (int x);  


    
}; 


#endif

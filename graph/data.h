/***********************************************************
Name: Tomas Vasquez, Benjamin Swann, Jesus Rivera III
Assignment: Final Project
Purpose: This program opens 3 diff files based on user input from command line (conducts basic file validation checks), 
and conducts graph operations based on if they are weighted or not and writes original contents to a file. The file operations: 
Breath First Search, Depth First Search, add a vertex, delete a vertex, conduct checks for duplicates(edges or vertex), check 
to delete an existing node, and checks connectivity and provides a list of items not connected.
Notes: Operations: Breath First Search, Depth First Search, add/ delete (vertex/edge) and write to file (example.txt).
***********************************************************/

#ifndef DATA_H
#define DATA_H

#include <string>
using std::string;


struct Node {
    int name;
    int weight;
    Node(int n, int w)
    {name=n; weight = w;}
};

#endif /* DATA_H */

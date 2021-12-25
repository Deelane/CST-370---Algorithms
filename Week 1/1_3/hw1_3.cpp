/*
Title: hw1_3.cpp
Abstract: This program converts a directed graph data from a user into a corresponding adjacency list format
Author: Delaney N.
ID: 1117
Date: 11/1/21
*/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main()
{
    int vertices;
    cin >> vertices;
    //vertex count less than 50 per the prompt
    while (vertices > 50)
    {
        cout << "Number of vertices must be less than or equal to 50\n";
        cin >> vertices;
    }
    
    //this is never even used
    int edges;
    cin >> edges;
    
    //adjacency list
    //I would have liked to use a binary tree instead of list<int> for sorted insertions but I am still learning c++
    unordered_map<int, list<int>> adjacencyList;
    for (int i = 0; i < edges; i++)
    {
        //Vertex 1 
        int input1; 
        cin >> input1;
        while (input1 > vertices || input1 < 0)
        {
            cout << "Vertex does not exist.\n";
            cin >> input1;
        }
        
        //Vertex 2 
        int input2; 
        cin >> input2;
        while (input2 > vertices || input2 < 0)
        {
            cout << "Vertex does not exist.\n";
            cin >> input2;
        }
        
        //key is already there
        if (adjacencyList.count(input1) > 0)
        {
            //append vertex to existing list
            adjacencyList[input1].push_back(input2);
        }
        else
        {
            //create new list for vertex
            adjacencyList.insert({input1, {input2}});
        }
    }
    
    cout << "\n";
    
    //for all vertices
    for (int i = 0; i < vertices; i++)
    {
        cout << i;
        //vertex has connections
        if (adjacencyList.count(i) > 0)
        {
            //this operation can take up a lot of processing power, I would have liked to use binary trees for sorted insertion to avoid having to use sort()
            adjacencyList.at(i).sort();
            //iterate through list of vertex connections
            for (int vertex: adjacencyList.at(i))
            {
                cout << "->" << vertex;
            }
        }
	cout << "\n";
    }
}

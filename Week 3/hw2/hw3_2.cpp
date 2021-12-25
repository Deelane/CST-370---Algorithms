/*
Title: hw3_2.cpp
Abstract: This program reads an input graph data from a user. Then, it presents a path for the travelling salesman problem (TSP). 
Author: Delaney N.
ID: 1117
Date: 11/17/21
*/
#include <iostream> 
#include <unordered_map>
#include <list>
#include <bits/stdc++.h>

using namespace std; 

//store all permutations of an int array
void permute(int arr[], int l, int r, list<vector<int>>& permutations) 
{ 
	// Base case 
	if (l == r)
	{
	    vector<int> permutation;
	    for (int i = 0, size = r + 1; i < size; i++)
	    {
	        permutation.push_back(arr[i]);
	    }
        permutations.push_back(permutation);
	}
	else
	{
		for (int i = l; i <= r; i++) 
		{
			swap(arr[l], arr[i]);
			permute(arr, l+1, r, permutations);
			swap(arr[l], arr[i]); 
		} 
	} 
} 


// Driver Code 
int main() 
{ 
    
    static unordered_map<string, int> map;
    static int vertices;
    static int edges;
    static int root;
    static list<vector<int>> permutations;
	static string path = "";
	static int lowestCost = -1;
	
	//vertices
    cin >> vertices;
    while (vertices > 15 || vertices < 0)
    {
        cout << "Number of vertices must be non negative and cannot exceed 15" << endl;
        cin >> vertices;
    }
    
    //edges
    cin >> edges;
    while (edges < 0)
    {
        cout << "Number of edges cannot be negative" << endl;
        cin >> edges;
    }
    
    //map insertion
    for (int i = 0; i < edges; i++)
    {
        string vertexA;
        string vertexB;
        int cost;
        cin >> vertexA >> vertexB >> cost;
        map.insert({vertexA + vertexB, cost});
    }
    
    //root
    cin >> root;
    while (root > vertices || root < 0)
    {
    	cout << "Root must be non negative and exist within V" << endl;
	    cin >> root;
    }
    
    //array of vertices
	int arr[vertices];
	for (int i = 0; i < vertices; i++)
	{
		arr[i] = i;
	}
	
	//generate permutations and store them
	permute(arr, 0, vertices-1, permutations); 
	
	//iterate over all permutations
	for (vector<int> permutation: permutations)
	{
		bool hasPath = true;
		int currentCost = 0;
		string currentPath = "";
		
		//construct a possible path from the root and current permutation 
		vector<int> possiblePath;
		//add root to start
		possiblePath.push_back(root);
		//iterate over current permutation and add all non root values to possible path
		for (int i: permutation)
		{
			if (i != root)
			{
				possiblePath.push_back(i);
			}
		}
		//add root to end
		possiblePath.push_back(root);
		
		//construct vertex pairs from every adjacent pair of vertices in possiblePath and check the map to see if there exists an edge between them
	    for (int i = 0, size = possiblePath.size() - 1; i < size; i++)
	    {
	        string pair = to_string(possiblePath[i]) + to_string(possiblePath[i+1]);
	        //there exists an edge between the vertices
	        if (map.count(pair) > 0)
	        {
	        	currentCost += map.at(pair);
	        	currentPath += to_string(possiblePath[i]) + "->";
	        }
	        //no edge exists between the 2 vertices so a path is impossible
	        else
	        {
	        	hasPath = false;
	        	break;
	        }
	    }
	    
	    //there is a path for the traveling salesman
	    if (hasPath)
	    {
	    	//we found a new shortest path
	    	if (currentCost < lowestCost || lowestCost == -1)
	    	{
	    		//update cost
	    		lowestCost = currentCost;
        		//add the root to the end
        		currentPath += to_string(possiblePath[possiblePath.size() - 1]);
				//update path
				path = currentPath;
	    	}

	    }
	}
	
	cout << "Path:" << path << endl << "Cost:" << lowestCost << endl;
	return 0; 
}
//0, 1, 2, 3
//0
//0, 1, 2, 3, 0
//size = 5
//iterate from 0 to size - 1 
//0, 1, 2, 3
//2
//2, 0, 1, 3, 2

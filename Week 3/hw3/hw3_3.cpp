#include <iostream> 
#include <list>
#include <bits/stdc++.h>

using namespace std; 
int Count = 0; //Capital to avoid conflicts with std Count

void dfs(int vertex, list<int> adjList[], int mark[])
{
    //iterate over all vertices adjacent to current vertex
    for (int i: adjList[vertex])
    {
        //vertex is unvisited
        if (mark[i] == 0)
        {
            //increment Count
            ++Count;
            //update mark array
            mark[i] = Count;
            //run search on new vertex
            dfs(i, adjList, mark);
        }
    }
    return;
}

// Driver Code 
int main() 
{ 
    static int vertices;
    static int edges;

	//vertices
    cin >> vertices;
    while (vertices < 0)
    {
        cout << "Number of vertices must be non negative" << endl;
        cin >> vertices;
    }
    
    //edges
    cin >> edges;
    while (edges < 0)
    {
        cout << "Number of edges cannot be negative" << endl;
        cin >> edges;
    }

    //adjacency list for better data manipulation
	list<int> adjacencyList[vertices];
	//initialize a list for each vertex
	for (int i = 0; i < vertices; i++)
	{
        adjacencyList[i] = {};
	}
    for(int i = 0; i < edges; i++)
    {
        int vertex1;
        int vertex2;
        cin >> vertex1;
        while (vertex1 < 0 || vertex1 > vertices - 1)
        {
            cout << "Vertex must be non negative and exist within V" << endl;
            cin >> vertex1;
        }
        cin >> vertex2;
        while (vertex2 < 0 || vertex2 > vertices - 1)
        {
            cout << "Vertex must be non negative and exist within V" << endl;
            cin >> vertex2;
        }
        adjacencyList[vertex1].push_back(vertex2);
    }
    
    //DFS
    //mark array
	int mark[vertices];
	for (int i = 0; i < vertices; i++)
	{
	    mark[i] = 0;
	}
	//iterate over all vertices in mark array
    for (int i = 0; i < vertices; i++)
    {
        //vertex has not been visited
        if (mark[i] == 0)
        {
            ++Count;
            mark[i] = Count;
            //run a depth first search
            dfs(i, adjacencyList, mark);
        }
    }
    //iterate over finished mark array
    for (int i = 0; i < vertices; i++)
    {
        cout << "Mark[" << i << "]:" << mark[i] << endl;
    }
	return 0; 
}

/*
Title: hw4_3.cpp
Abstract: This program conducts a topological sort based on Kahn's algorithm. 
Author: Delaney N.
ID: 1117
Date: 11/26/21
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

int main() 
{
    static int vertices;
    static int edges;
	//vertices
    std::cin >> vertices;
    while (vertices < 0)
    {
        std::cout << "Number of vertices cannot be negative" << std::endl;
        std::cin >> vertices;
    }
    
    //edges
    std::cin >> edges;
    while (edges < 0)
    {
        std::cout << "Number of edges cannot be negative" << std::endl;
        std::cin >> edges;
    }
    
    //TODO fix this so it shows in degree and not out degree
    std::unordered_map<int, std::vector<int>> map;
    //array for holding in degrees for each vertex
    //index represents the vertex and the value represents the in-degree
    int arr[vertices];
    //initialize to 0
    for (int i = 0; i < vertices; i++)
    {
        arr[i] = 0;
    }
    
    //edges from user input
    for (int i = 0; i < edges; i++)
    {
        //get vertexes from user
        int vertex1;
        int vertex2;
        std::cin >> vertex1;
        while (vertex1 < 0 || vertex1 > vertices - 1)
        {
            std::cout << "Vertex must be non negative and exist within V" << std::endl;
            std::cin >> vertex1;
        }
        std::cin >> vertex2;
        while (vertex2 < 0 || vertex2 > vertices - 1)
        {
            std::cout << "Vertex must be non negative and exist within V" << std::endl;
            std::cin >> vertex2;
        }
        
        //increment the in-degree for the given vertex
        ++arr[vertex2];
        
        //map already contains key
        if (map.find(vertex1) != map.end())
        {
            //add vertex to vector
            map[vertex1].push_back(vertex2);
        }
        //map does not contain key
        else
        {
            //insert key and a vector with vertex2
            map.insert({vertex1, {vertex2}});
        }
    }
    
    for (int i = 0; i < vertices; i++)
    {
        std::cout << "In-degree[" << i << "]:" << arr[i] << std::endl;
    }
    
    //Topographical sort
    std::string output = "Order:";
    //queue for holding our vertices with 0 in degree
    std::queue<int> queue;
    //sum of in-degrees
    for (int i = 0; i < vertices; i++)
    {
        //found an in-degree of 0
        if (arr[i] == 0)
        {
            //push corresponding vertex to queue
            queue.push(i);
            //so vertex is ignored when we come back 
            arr[i] = -1;
        }
    }
    
    //we didnt find a vertex with an in degree of 0 so graph is not a DAG
    if (queue.size() == 0)
    {
        std::cout << "No Order:" << std::endl;
        return 0;
    }
    
    while (queue.size() > 0)
    {
        //pop the front vertex
        int vertex = queue.front();
        queue.pop();
        //retrieve its list of connections 
        std::vector<int> connections = map[vertex];
        //iterate over list of connections
        for (int i = 0, size = connections.size(); i < size; i++)
        {
            //connections[i] is a connected vertex and also the index of said vertex's in-degree in arr
            --arr[connections[i]];
        }
        //add vertex to output
        output += std::to_string(vertex) + "->";
        
        //look for new 0 in-degree vertices to be enqueued
        for (int i = 0; i < vertices; i++)
        {
            //found an in-degree of 0
            if (arr[i] == 0)
            {
                //push corresponding vertex to queue
                queue.push(i);
                arr[i] = -1;
            }
        }
    }
    
    //remove last arrow
    output = output.substr(0, output.length() - 2);
    std::cout << output << std::endl;
    return 0;
}

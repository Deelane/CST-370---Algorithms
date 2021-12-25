/*
Title: hw6_2.cpp
Abstract: 
    This program implements Floyd's algorithm to display all-pairs' shortest paths in a directed graph. 
    Any negative cost indicates no connection.
Author: Delaney N.
ID: 1117
Date: 12/11/21
*/

#include <iostream>

int main()
{
    int vertices;
    std::cin >> vertices;
    while (vertices > 25 || vertices < 0)
    {
        std::cout << "Vertices must be less than 26 and non-negative.\n";
        std::cin >> vertices;
    }
    
    int matrix[vertices][vertices];
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            //any negative input will be treated as an infinite connection length
            std::cin >> matrix[i][j];
        }
    }
    
    //Floyd's algorithm
    //Iterate over the entire matrix for each vertex to check for multi-path connections
    //Update each vertex's lowest cost connection as we go
    for (int k = 0; k < vertices; k++)
    {
        for(int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                int current = matrix[i][j];
                int connectionA = matrix[i][k];
                int connectionB = matrix[k][j];

                //no valid path
                if (current < 0 && (connectionA < 0 || connectionB < 0))
                {
                    //no work to be done, move to next iteration
                    continue;
                }
                //current value is negative but there is a connecting path through AB
                else if (current < 0 && (connectionA >= 0 && connectionB >= 0))
                {
                    matrix[i][j] = connectionA + connectionB;
                }
                //there are 2 valid connections to compare
                else if (current >= 0 && (connectionA >= 0 && connectionB >= 0))
                {
                    matrix[i][j] = std::min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
                //else only the current value is valid
            }
        }
    }
    
    //Print matrix
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
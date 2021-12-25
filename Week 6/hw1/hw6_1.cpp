/*
Title: hw6_1.cpp
Abstract: This program uses dynamic programming to collect the maximum number of coins on an n x m board 
Author: Delaney N.
ID: 1117
Date: 12/11/21
*/

#include <iostream>
#include <stack>
#include <vector>

int main()
{
    int rows;
    int cols;
    std::cin >> rows;
    while (rows > 25 || rows < 0)
    {
        std::cout << "Rows must be non-negative and under 26\n";
        std::cin >> rows;
    }
    std::cin >> cols;
    while (cols > 25 || cols < 0)
    {
        std::cout << "Columns must be non-negative and under 26\n";
        std::cin >> cols;
    }
    
    int matrix[rows][cols];
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int coin;
            std::cin >> coin;
            while (coin < 0 || coin > 1)
            {
                std::cout << "Input must be 0 or 1";
                std::cin >> coin;
            }
            matrix[i][j] = coin;
        }
    }
    
    
    //Compute largest amount of coins that can be collected at any row,col
    int row;
    int col;
    
    //calculate the top row first
    for (col = 1; col < cols; col++)
    {
        //matrix[row][col] will always be either 1 or 0 when we first check it, representing 1 coin or no coins
        matrix[0][col] = matrix[0][col] + matrix[0][col-1];
    }

    //calculate the remaining rows
    for (row = 1; row < rows; row++)
    {
        //calculate the first column first
        matrix[row][0] = matrix[row][0] + matrix[row-1][0];
        //calculate the remaining rows and columns
        for (col = 1; col < cols; col++)
        {
            //new value is the greater value between one row up and one column left
            matrix[row][col] = std::max(matrix[row-1][col], matrix[row][col-1]) + matrix[row][col];
        }
    }
    
    //Backtrack to find path
    std::stack<std::vector<int>> path; 
    //always start from bottom right corner
    row = rows - 1;
    col = cols - 1;
    std::vector<int> pair;
    pair.push_back(row);
    pair.push_back(col);
    path.push(pair);
    
    //if either row or col reaches 0, we just copy the remaining values
    while (row >= 0 && col >= 0)
    {
        //we reached the top row, so all we can do is go left
        if (row == 0)
        {

            //set row value once
            pair[0] = row;
            //add remaining col values 
            while (col > 0)
            {
                //go left a column
                col--;
                pair[1] = col;
                //add to path
                path.push(pair);
            }
            //break since we are done
            break;
        }
        //we reached the left row, so all we can do is go up
        else if (col == 0)
        {
            //set col value once 
            pair[1] = col;
            //add remaining row values
            while (row > 0)
            {
                row--;
                pair[0] = row;
                //add to path
                path.push(pair);
            }
            //break since we are done
            break;
        }
        //we are not on a border
        //greater value is above
        else if (matrix[row-1][col] > matrix[row][col-1])
        {
            row--;
        }
        //greater value is left or the values are equal
        else
        {
            col--;
        }
        //update pair and push to path stack
        pair[0] = row;
        pair[1] = col;
        path.push(pair); 
    }
    
    //Print path
    std::string output = "Path:";
    while (!path.empty())
    {
        pair = path.top();
        //add 1 to row and col for visual purposes
        row = pair[0] + 1;
        col = pair[1] + 1;
        output += "(" + std::to_string(row) + "," + std::to_string(col) + ")";
        path.pop();
        //if the previous operation didn't clear the stack
        if (!path.empty())
        {
            output += "->";
        }
    }
    std::cout << "Max coins:" + std::to_string(matrix[rows-1][cols-1]) << std::endl;
    std::cout << output << std::endl;
}
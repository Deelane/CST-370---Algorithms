/*
Title: hw5_1.cpp
Abstract: This program allows the user to conduct heap operations.
Author: Delaney N.
ID: 1117
Date: 12/5/21
*/

#include <iostream> 
#include <algorithm>
#include <vector>

void constructHeap(std::vector<int>& arr);
void deleteMax(std::vector<int>& arr);
void insert(std::vector<int>& arr, int val);
void displayMax(std::vector<int>& arr);
void display(std::vector<int>& arr);

// Driver Code 
int main() 
{
    //array length
    static int length;
    std::cin >> length;
    while (length < 0)
    {
        std::cout << "Length cannot be negative" << std::endl;
        std::cin >> length;
    }
    
    //construct array
    std::vector<int> arr;
    arr.push_back(0);
    for(int i = 0; i < length; i++)
    {
        int val;
        std::cin >> val;
        arr.push_back(val);
    }
    
    static int numCommands;
    std::cin >> numCommands;
    while (numCommands < 0)
    {
        std::cout << "Number of numCommands cannot be negative" << std::endl;
        std::cin >> numCommands;
    }
    
    //check if array is heap
    //iterate over all parent values and check if they are larger than their children
    bool heap = true;
    std::string heapMessage = "This is a heap.";
    for (int i = 1, bound = length/2; i <= bound; i++)
    {
        //there are 2 children to check, arr[2i] and arr[2i+1]
        if ((2*i + 1) <= length)
        {
            if (arr[i] < std::max(arr[2*i], arr[2*i+1]))
            {
                heap = false;
                heapMessage = "This is NOT a heap.";
                break;
            }
        }
        //there is only 1 child (the last child)
        else
        {
            if (arr[i] < arr[2*i])
            {
                heap = false;
                heapMessage = "This is NOT a heap.";
            }
        }
    }
    //constructHeap
    if (!heap)
    {
        constructHeap(arr);
    }
    
    //flush newline out of buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    //discard characters until newline is found
    
    //Construct array of commands
    std::string commands[numCommands];
    for (int i = 0; i < numCommands; i++)
    {
        std::getline(std::cin, commands[i]);
    }
    
    //Execute commands
    std::cout << heapMessage << std::endl;
    for (std::string command: commands)
    {
        //normally i would have mapped the commands but since there aren't many i'm just using a long if else chain
        if (command == "deleteMax")
        {
            deleteMax(arr);
        }
        else if (command.substr(0, 6) == "insert")
        {
            //parse the int value
            int val = stoi(command.substr(7, command.length() - 7));
            insert(arr, val);
        }
        else if (command == "display")
        {
            display(arr);
        }
        else if (command == "displayMax")
        {
            displayMax(arr);
        }
        else
        {
            std::cout << "Invalid command" << std::endl;
        }
    }
}

void constructHeap(std::vector<int>& arr)
{
    int length = arr.size() - 1;
    
    //iterate from last parent node down to root
    for (int i = length/2; i >= 1; i--)
    {
        int k = i;
        int parentValue = arr[k];
        bool heap = false;
        //heapify each parent node
        //2*k <= length to ensure we don't go out of bounds
        //parentvalue will continuously be bubbled down while heap is false
        while(!heap && 2*k <= length)
        {
            int j = 2*k;
            //there are 2 children
            if (j < length)
            {
                //compare the 2 children
                if (arr[j] < arr[j+1])
                {
                    //2nd child was larger, so replace the index
                    j = j+1;
                }
            }
            if (parentValue >= arr[j])
            {
                heap = true;
            }
            else
            {
                //swap the values of the parent and larger child value
                arr[k] = arr[j];
                //update the index k to the index of the child value
                k = j;
                //bubble down the parent value
                arr[k] = parentValue;
            }
        }
    }
}
void deleteMax(std::vector<int>& arr)
{
    int length = arr.size() - 1;
    
    //replace root with last leaf
    arr[1] = arr[length];
    //delete the last leaf
    arr.pop_back();
    
    //update length to match new array size
    length = length - 1;
    
    //heapify the root
    int k = 1;
    int parentValue = arr[k];
    bool heap = false;
    //bubble down the new root until it is heapified
    //2*k <= length to ensure we don't go out of bounds
    while(!heap && 2*k <= length)
    {
        int j = 2*k;
        //there are 2 children
        if (j < length)
        {
            //compare the 2 children
            if (arr[j] < arr[j+1])
            {
                //2nd child was larger, so replace the index
                j = j+1;
            }
        }
        if (parentValue >= arr[j])
        {
            heap = true;
        }
        else
        {
            //swap the values of the parent and larger child value
            arr[k] = arr[j];
            //update the index k to the index of the child value
            k = j;
            //bubble down the parent value
            arr[k] = parentValue;
        }
    }
}

void insert(std::vector<int>& arr, int val)
{
    //heapify the new value
    //insert val
    arr.push_back(val);
    //k is now the new size of the array
    int k = arr.size() - 1;
    //while the value we inserted is greater than its parent value
    while (val > arr[k/2] && k > 1)
    {
        //swap parent and child
        arr[k] = arr[k/2];
        arr[k/2] = val;
        //update k
        k = k/2;
    }
}

void displayMax(std::vector<int>& arr)
{
    if (arr.size() >= 2)
    {
        std::cout << arr[1] << std::endl;
    }
    else
    {
        std::cout << "Heap has no values";
    }
}
void display(std::vector<int>& arr)
{
    for (int i = 1, size = arr.size(); i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
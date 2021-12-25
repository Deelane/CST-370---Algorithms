/*
Title: hw4_1.cpp
Abstract: This program partitions an array into negatives and positives.
Author: Delaney N.
ID: 1117
Date: 11/23/21
*/

#include <iostream> 

// Driver Code 
int main() 
{ 
    static int length;
    std::cin >> length;
    while (length < 0)
    {
        std::cout << "Length cannot be negative" << std::endl;
        std::cin >> length;
    }
    
    int arr1[length];
    int arr2[length];
    for (int i = 0; i < length; i++)
    {
        int input;
        std::cin >> input; 
        arr1[i] = arr2[i] = input;
    }
    
    //partition arr1 using first approach
    int i = 0; 
    int j = length - 1;
    
    while (i <= j)
    {
        int l = arr1[i];
        int r = arr1[j];
        //increment i until l is a positive number
        while (l < 0)
        {
            ++i;
            l = arr1[i];
        }
        //decrement j until js is a negative number
        while (r >= 0)
        {
            --j;
            r = arr1[j];
        }
        //if i and j didn't cross
        if (i <= j)
        {
           //swap the values
            arr1[i] = r;
            arr1[j] = l; 
        }

    }
    
    //partition arr2 using second approach
    i = j = 0;
    //move i and j until our starting point is a postiive number
    while (arr2[i] < 0)
    {
        ++i;
        ++j;
    }
    
    while (i < length && j < length)
    {
        int l = arr2[i];
        int r = arr2[j];
        //increment i until l is a positive number
        while (l < 0 && i < length)
        {
            ++i;
            l = arr2[i];
        }
        //decrement j until js is a negative number
        while (r >= 0 && j < length)
        {
            ++j;
            r = arr2[j];
        }
        //if j has still not reached the end
        if (j < length - 1)
        {
           //swap the values
            arr2[i] = r;
            arr2[j] = l; 
        }

    }
    
    for (int i: arr1)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i: arr2)
    {
        std::cout << i << " ";
    }
	return 0; 
}

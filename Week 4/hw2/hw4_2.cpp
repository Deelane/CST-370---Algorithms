/*
Title: hw4_2.cpp
Abstract: This program displays the biggest number in an array with n integer numbers using a divide-and-conquer technique.
Author: Delaney N.
ID: 1117
Date: 11/26/21
*/

#include <iostream>

// Sum the array arr from start index to end index
int find_max(int arr[ ], int start, int end);

int main() 
{
    static int length;
    std::cin >> length;
    while (length <= 0)
    {
        std::cout << "Length cannot be 0 or negative" << std::endl;
        std::cin >> length;
    }
    
    int arr[length];
    for (int i = 0; i < length; i++)
    {
        std::cin >> arr[i]; 
    }
    
    int max = find_max(arr, 0, length - 1);
    std::cout << max << std::endl;
    
    return 0;
}

//find the greatest value using divide and conquer
int find_max(int arr[], int start, int end)
{
    //if there are 2 values in the subarray
    if (end - start == 1) 
    {
        return (arr[start] > arr[end]) ? arr[start] : arr[end];
    }
    //if an array of size 1 is passed
    else if (end - start == 0)
    {
        return arr[start];
    }
    else 
    {
        //find max in left subarray
        int leftMax = find_max(arr, start, (start+end)/2);
        //find max in right subarray
        int rightMax = find_max(arr, (start+end)/2+1, end);
        return (leftMax > rightMax) ? leftMax : rightMax;
    }
}
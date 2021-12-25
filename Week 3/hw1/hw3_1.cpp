/*
Title: hw3_1.cpp
Abstract: This program reads the number of input values from a user and then the input values themselves. After that, the numbers are displayed in ascending order. Consecutive numbers are displayed using a shorter representation. For example, if there are three numbers such as 51, 52, and 53 in the input values, they are displayed as 51–53 to save space.
Author: Delaney N.
ID: 1117
Date: 11/9/21
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //size
    int size;
    cin >> size;
    if (size < 1)
    {
        cout << "Size must be greater than 0" << endl;
        cin >> size;
    }
    //input array
    int input[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }
    
    //sort array
    sort(input, input + size);
    
    
    for (int i = 0; i < size; i++)
    {
        if (i < size - 1 && input[i+1] == input[i] + 1)
        {
            int count = 1;
            ++i;
            while (i < size - 1 && input[i+1] == input[i] + 1)
            {
                ++count;
                ++i;
            }
            cout << input[i - count] << "-" << input[i] << " ";
        }
        else
        {
            cout << input[i] << " ";
        }
    }
}
//27, 51, 52, 53, 75, 77
//0,  1,  2,  3,  4,  5

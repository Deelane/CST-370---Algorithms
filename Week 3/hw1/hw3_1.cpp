/*
Title: hw2_3.cpp
Abstract: This program checks if an input string is a palindrome or not.
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
/*
Title: hw0_2.cpp
Abstract: This program reads five integer numbers from a user and displays the min, max, and median values on the screen.
Author: Delaney N.
ID: 1117
Date: 10/26/21
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int input [5];
    int length = sizeof(input) / 4;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }
    //sort array once
    sort(input, input + length);
    
    //find the median
    int median;
    //odd array length
    if (length % 2 != 0)
    {
        median = input[length/2];
    }
    else
    {
        median = (input[(length - 1) / 2] + input[length / 2]) / 2;
    }
    cout << "MIN:" << input[0] << "\n";
    cout << "MAX:" << input[length - 1] << "\n";
    cout << "MEDIAN:" << median << "\n";

}

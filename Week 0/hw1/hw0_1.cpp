/*
Title: hw0_1.cpp
Abstract: This program calculates the sum and difference of two numbers.
Author: Delaney N.
ID: 1117
Date: 10/26/21
*/
#include <iostream>
using namespace std;

int main()
{
    int input1, input2;
    cin >> input1 >> input2;
    cout << "SUM:" << input1 + input2 << "\n";
    if (input1 < input2)
    {
        cout << "DIFF:" << input2 - input1 << "\n";
    }
    else
    {
        cout << "DIFF:" << input1 - input2 << "\n";
    }
}

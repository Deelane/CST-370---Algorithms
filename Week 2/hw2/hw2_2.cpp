/*
Title: hw2_2.cpp
Abstract: This program reads the number of elements in a set, prints the elements of the set, and then prints all possible decimal numbers, corresponding binary numbers, and subsets one by one.
Author: Delaney N.
ID: 1117
Date: 11/8/21
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void toBinary(int number, int bitsArray[], int arraySize)
{
    //initialize to 0s 
    for (int i = 0; i < arraySize; i++)
    {
        bitsArray[i] = 0;
    }
    for (int i = arraySize - 1; number > 0; i--)
    {
        bitsArray[i] = number % 2; 
        number /= 2;
    }
}

int main()
{
    //user input
    int setSize;
    cin >> setSize;
    while (setSize < 0 || setSize > 9)
    {
        cout << "Set size must be non negative and less than 10\n";
        cin >> setSize;
    }
    
    //input is 0
    if (setSize == 0)
    {
        cout << "0:0:EMPTY";
        return 0;
    }
    
    string set[setSize];
    for (int i = 0; i < setSize; i++)
    {
        cin >> set[i];
    }

    for (int i = 0, limit = pow(2, setSize); i < limit; i++)
    {
        int bits[setSize];
        toBinary(i, bits, setSize);
        cout << i << ":";
        string result = "";
        for (int j = 0; j < setSize; j++)
        {
            cout << bits[j];
            if (bits[j] == 1)
            {
                //append corresponding string to result
                result += set[j] + " ";
            }
        }
        if (result == "")
        {
            result = "EMPTY";
        }
        cout << ":" << result << "\n";
    }
}

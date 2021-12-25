/*
Title: hw1_1.cpp
Abstract: This program reads input numbers from a user and displays the closest distance between two numbers among all input numbers.
Author: Delaney N.
ID: 1117
Date: 11/1/21
*/
#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <vector>

using namespace std;

int main()
{
    int length;
    cin >> length;
    //input less than 500 per the prompt
    while (length >= 500)
    {
        cout << "Length must be less than 500\n";
        cin >> length;
    }
    int input[length];
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }
    
    //sort for easy pair comparisons
    sort(input, input + length);
    //store closest pairs
    list<int> pairs;
    //current shortest distance
    int shortestDistance = abs(input[0] - input[1]);
    //hold current closest pair
    vector<int> closestPair;
    closestPair.push_back(input[0]);
    closestPair.push_back(input[1]);
    
    //hold all the current closest pairs
    list<vector<int>> currentClosestPairs;
    //insert starting pair
    currentClosestPairs.push_back(closestPair);

    //iterate over all pairs
    for (int i = 1; i < length - 1; i++)
    {
        //new shortest distance
        if (abs(input[i] - input[i+1]) < shortestDistance)
        {
            shortestDistance = abs(input[i] - input[i + 1]);
            closestPair.clear();
            closestPair.push_back(input[i]);
            closestPair.push_back(input[i+1]);
            currentClosestPairs.clear();
            currentClosestPairs.push_back(closestPair);
        }
        //same distance as current shortest
        else if(abs(input[i] - input[i+1]) == shortestDistance)
        {
            closestPair.clear();
            closestPair.push_back(input[i]);
            closestPair.push_back(input[i+1]);
            currentClosestPairs.push_back(closestPair);
        }
        //else it is a larger distance than shortest
    }
    
    cout << "\nMin Distance:" << shortestDistance << "\n";
    for (auto pair: currentClosestPairs)
    {
        cout << "Pair:" << pair[0] << " " << pair[1] << "\n";
    }
}

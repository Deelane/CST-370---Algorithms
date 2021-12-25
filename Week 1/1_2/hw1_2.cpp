/*
Title: hw1_2.cpp
Abstract: This program reads input numbers from a user and displays the number(s) that occurs most frequently among all the input numbers.
Author: Delaney N.
ID: 1117
Date: 11/1/21
*/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

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
    
    //store closest pairs
    unordered_map<int, int> map;
    for (int i = 0; i < length; i++)
    {
        //map already contains key
        if (map.count(input[i]) > 0)
        {
            //find current value and increment
            int temp = map.at(input[i]);
            temp++;
            //insert incremented value
            map[input[i]] = temp;
        }
        //map does not contain key
        else
        {
            map.insert({input[i], 1});
        }
    }
    
    //most frequent number count
    int mostFrequent = 0;
    //most frequent numbers
    list<int> numbers;
    for (pair<int, int> element: map)
    {

        //new most frequent number
        if (element.second > mostFrequent)
        {
            mostFrequent = element.second;
            //clear list of numbers and add this element
            numbers.clear();
            numbers.push_back(element.first);
        }
        //same frequency
        else if (element.second == mostFrequent)
        {
            //add to numbers list
            numbers.push_back(element.first);
        }
        //else it is not the most frequent 
    }
    
    //sort descending
    numbers.sort();
    numbers.reverse();
    
    cout << "\nFrequency:" << mostFrequent << "\n";
    cout << "Number:";
    for (int number: numbers)
    {
        cout << number << " ";
    }
    cout << "\n";
}

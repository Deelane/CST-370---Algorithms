/*
Title: hw2_1.cpp
Abstract: This program reads two timestamps of two events from a user and displays the difference between the two timestamps.
Author: Delaney N.
ID: 1117
Date: 11/8/21
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input1;
    string input2;
    cin >> input1 >> input2;
    
    int time1 = 0;
    int time2 = 0;
    
    //convert to seconds
    time1 += stoi(input1.substr(0, 2))*60*60;
    time1 += stoi(input1.substr(3, 2))*60;
    time1 += stoi(input1.substr(6, 2));
    time2 += stoi(input2.substr(0, 2))*60*60;
    time2 += stoi(input2.substr(3, 2))*60;
    time2 += stoi(input2.substr(6, 2));

    int difference = 0;
    
    //overflow handling
    int overflow = 0;
    if (time1 > time2)
    {
        overflow = 86400 - time1; //subtract seconds in a 24 hour day from time1
        difference = time2 + overflow;
    }
    
    else
    {
        difference = abs(time1 - time2);
    }
    //calculate hours
    int hours = 0;
    while (hours < 23 && difference >= 3600)
    {
        difference -= 3600;
        hours++;
    }
    //calculate minutes
    int minutes = 0;
    while (minutes < 60 && difference >= 60)
    {
        difference -= 60;
        minutes++;
    }
    //only seconds remain

    string hoursString = to_string(hours);
    string minutesString = to_string(minutes);
    string secondsString = to_string(difference);
    
    if (hours < 10)
    {
        hoursString = "0" + hoursString;
    }
    if (minutes < 10)
    {
        minutesString = "0" + minutesString;
    }
    if (difference < 10)
    {
        secondsString = "0" + secondsString;
    }

    cout << hoursString << ":" << minutesString << ":" << secondsString << "\n";
}

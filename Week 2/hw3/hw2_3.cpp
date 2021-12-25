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

bool isPalindrome(string s, int start, int end)
{
    if (start == end)
    {
        return true;
    }
    //don't bother checking the rest of the chars if they are not equal here
    else if (s[start] != s[end])
    {
        return false;
    }
    else
    {
        isPalindrome(s, start + 1, end - 1);
    }
    return true;
}

int main()
{
    //user input
    string unparsedInput;
    getline(cin, unparsedInput);
    string input;
    for (char& c: unparsedInput)
    {
        if (isalnum(c))
        {
            input += toupper(c);
        }
    }

    if (input.size() % 2 == 0)
    {
        cout << "FALSE\n";
        return 0;
    }
    
    if (isPalindrome(input, 0, input.size() - 1))
    {
        cout << "TRUE\n";
    }
    else
    {
        cout << "FALSE\n";
    }
}

/*

Created by: Hans Jaeger
Created on: 2024/06/07
Description:  Below is the solution to a leetcode problem regarding whether a string is a Palindrome (can be read both forwards and backwards).

*/

#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        // Check Whether the string is empty
        if (s.empty())
        {
            return true;
        }
        // Remove any whitespace and non-alphanumeric characters
        s.erase(std::remove_if(s.begin(), s.end(),
                               [](char c)
                               // Check whether is is a
                               { return !std::isalnum(c) && !std::isspace(c); }),
                s.end());
        // Now convert the string to lowercase
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c)
                       { return std::tolower(c); });

        // Two pointers from the front and back

        // Back Pointer:
        int l = s.size() - 1;
        char *back = &s[l];

        // Front Pointer:
        char *front = &s[0];

        while (*back == *front)
        {
            cout << "Back: " << *back << endl;
            cout << "Front: " << *front << endl;
            back--;
            front++;
            if (front > back)
            {
                return true;
            }
        }
        return false;
    }
};

/*

Check if string is empty

Input: s = "Was it a car or a cat I saw?"
Input: s = "tabacat"


Output: true

*/
int main()
{
    Solution s;
    bool f = s.isPalindrome("Was it a car or a cat I saw?");
    cout << f << endl;
}

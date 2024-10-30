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
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            // Check for whether to skip whitespaces
            // This function just checks whether it is an integer or an alphabetical number.

            while (!isalnum(s[l]) && l < r)
            {
                // The function takes an a character and transforms it into either a 0 or 1.
                l++;
            }
            while (!isalnum(s[r]) && l < r)
            {
                r--;
            }
            // We need a check whether the words match:
            if (tolower(s[r]) != tolower(s[l]))
            {
                return false;
            }
            l++;
            cout << s[l] << endl;
            r--;
            cout << s[r] << endl;
        }
        return true;
    }
};

int main()
{
    Solution s;
    bool f = s.isPalindrome("tab a cat");
    cout << f << endl;
}

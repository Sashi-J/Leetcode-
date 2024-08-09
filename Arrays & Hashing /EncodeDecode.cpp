/*

Created by: Hans Jaeger
Created on: 2024/05/29
Description: This is encoding a list of strings into one string and then decode the single string into the a list of strings.
Both functions are O(n) and must be stateless.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        // Since it has to be a stateless function we must then use some type of delimeter within the string.
        string s;
        for (auto const &it : strs)
        {
            s.append(to_string(it.size()) + "#" + it);
        }
        return s;
    }

    vector<string> decode(string s)
    {
        int i = 0;
        int j;
        int length;
        vector<string> r;
        while (i < s.size())
        {
            j = i;
            while (s[j] != '#')
            {
                j += 1;
            }

            length = stoi(s.substr(j - 1, 1)); // Grab the length number indicated by the encoded delimeter format. We then transform that digit into the length

            string str = s.substr(j + 1, length);
            r.push_back(str);
            i = j + 1 + length; // Begins at the length of the string representation of the encoded string
            // AKA it begins at 4 for the encoded string 4#hans or
        }
        return r;
    }
};
int main()
{
    vector<string> strs = {"Hans", "me", ":", "!@#$%^&*()"};

    Solution sol;
    string res = sol.encode(strs);
    cout << "SINGLE STRING IS: " << res;
    cout << endl;
    vector<string> result = sol.decode(res);

    if (!result.empty())
    {
        for (auto it : result)
        {
            cout << it << endl;
        }
    }
}
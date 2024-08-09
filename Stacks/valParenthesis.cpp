#include <iostream>
#include <stack>

using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.empty())
        {
            return false;
        };
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        stack<char> open;
        for (const auto &it : s)
        {
            // If it isn't a closing bracket then move to the else statement
            if (pairs.find(it) != pairs.end())
            {
                // This condition states whether a closed bracket does not have an open bracket meaning that if the open stack is empty, there are not open brackets.
                if (open.empty())
                {
                    return false;
                }
                // This condition states to check if the top element matches the closing element within the pair NOT the key.
                if (open.top() != pairs[it])
                {
                    return false;
                }
                open.pop();
            }
            // Push since it is a open bracket
            else
            {
                open.push(it);
            }
        }
        return open.empty();
    }
};
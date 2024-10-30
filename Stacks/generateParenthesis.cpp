#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        backtrack(n, 0, 0, "", res); // Recursive call
        return res;
    }

private:
    void backtrack(int n, int o, int c, string current, vector<string> &res)
    {
        // Principle works on the basis of having closed and open brackets.
        if (o == c && o == n)
        {
            res.push_back(current);
            return;
        }
        // We have them as if conditions because we are forcing them like a tree path
        if (o < n)
        {
            backtrack(n, o + 1, c, current + "(", res);
        }
        if (c < o)
        {
            backtrack(n, o, c + 1, current + ")", res);
        }
        // If none of the conditions meet then it just returns. Remember that we place the closing bracket last because once it has called, we know it will be invalid if it tries to input a open parenthesis.
        // Therefore, once it returns, it will just return again until it meets with an open bracket due to the closing parenthesis being the last if condition.
    };
};

int main()
{
    Solution sol;
    vector<string> sols = sol.generateParenthesis(7);
    for (auto it : sols)
    {
        cout << it << endl;
    }
};
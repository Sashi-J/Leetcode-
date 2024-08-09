#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{

public:
    int evalRPN(vector<string> &tokens)
    {
        // push -> encounter operand -> perform operation -> save into final result.
        // The issue with my thought process was actually saving the final result into the stack itself.
        // Another concept was how to save the variables once they were popped and it was as simple as storing them for later aka a temp variable.
        stack<int> st;
        for (auto it : tokens)
        {
            if (it == "+")
            {
                while (st.size() != 1) // Makes it possible to have more than two values at a at time within this operation. Making sure that it is not the size of 1 cus we cannot pop that final result and there will always be one value within the stack.
                {

                    int a = st.top(); // the a variable will always retain the previous operation done. So this can be considered the final result.
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(a + b);
                }
            }
            else if (it == "-")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if (it == "*")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b * a);
            }
            else if (it == "/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(static_cast<int>(static_cast<double>(b) / a)); // Since we cannot divide ints directly in c++ 11 we need to convert it into a double and then an int.
            }
            else
            {
                st.push(stoi(it));
            }
        }
        return st.top();
    };
};

int main()
{
    Solution sol;
    vector<string> tokens = {"1", "2", "4", "+"};
    int result = sol.evalRPN(tokens);
    cout << result;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // Since we know the answer is based on how many elements there are we can define a space.
        vector<int> res(temperatures.size(), 0);
        // Pair of temp and index
        stack<pair<int, int>> st;
        for (int i = 0; i < temperatures.size(); i++)
        {
            // This while loop checks the prior temp pair and all of the prior temperatures in a while loop. So this means that if we push something before, it will check if a temperature is higher even for somethign we pushed a long time ago.
            while (!st.empty() && temperatures[i] > st.top().first)
            {
                auto pair = st.top();
                st.pop();
                // Pair second gives you the index and the i - pair.second gives you the distance between the days.
                res[pair.second] = i - pair.second;
            }
            st.push({temperatures[i], i});
        }
        return res;
    }
};

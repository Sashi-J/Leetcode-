#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // Declare Size of the  vector
        int sizeVector = nums.size();
        // Declare an unordered map to identify the elements and frequencies
        unordered_map<int, int> mainMap;

        // Populate:
        for (int i = 0; i < sizeVector; i++)
        {
            mainMap[nums[i]]++;
        }
        for (unordered_map<int, int>::iterator it = mainMap.begin(); it != mainMap.end(); it++)
        {
            cout << "Key:" << it->first << endl;
            cout << "Value: " << it->second << endl;
        }
        // Declare Vector Container
        vector<vector<int>> elementToFrequency(sizeVector + 1);

        // Lets distribute this over buckets where the indices are frequencies and the elements are the value of the vector
        for (unordered_map<int, int>::iterator it = mainMap.begin(); it != mainMap.end(); it++)
        {
            elementToFrequency[it->second].push_back(it->first);
        }
        cout << "This is the inside of elementToFrequency" << endl;
        for (int i = 0; i < elementToFrequency.size(); i++)
        {
            cout << "Index: " << i << " ";
            for (int j = 0; j < elementToFrequency[i].size(); j++)
            {
                cout << elementToFrequency[i][j] << " ";
            }
            cout << endl;
        }
        // Create a Vector for answer
        vector<int> ans;
        // We begin with the greediest answer
        for (int i = sizeVector; i >= 0; --i)
        {
            // if the size of the vector is greater than k (k being the given value) then break since we are keeping it.
            if (ans.size() >= k)
            {
                break;
            }
            // Decrement if the value is less than k. Reduce the vector.
            if (!elementToFrequency[i].empty())
            {
                for (int nums : elementToFrequency[i])
                {
                    ans.push_back(nums);
                }
                if (ans.size() >= k)
                {
                    break;
                }
            }
        }
        return ans;
    }
};
// Test Cases
int main()
{
    Solution solution;

    // Test case
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    int k = 2;

    vector<int> result = solution.topKFrequent(nums, k);

    // Print the result
    cout << "Top " << k << " frequent elements: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
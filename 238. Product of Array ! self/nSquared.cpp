/*
This is a test solution but then halfway I realized it was O of n^2 and then decide to rethink my solution path.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct VectorHash
{
    template <class T>
    size_t operator()(const vector<T> &vec) const
    {
        size_t seed = vec.size();
        for (const auto &value : vec)
        {
            seed ^= hash<T>{}(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<vector<int>, vector<int>, VectorHash> container;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {

            int num = nums[i];
            // cout << "NUMBER VALUE: " << num << endl;

            for (int j = 0; j < n; j++)
            {

                if (j != i)
                {

                    // ERROR: I had previously had i instead of num since that is why the number 0 would appear as the key.
                    container[vector<int>{num}].push_back(nums[j]);
                    // Lets Multiply
                }
            }
        }
        for (auto f : container)
        {
            for (auto b : f.first)
            {
                cout << b << ": " << endl;

                for (auto w : f.second)
                {
                    cout << w << ", ";
                }
            }
            cout << endl;
        }
        return ans;
    }
};
int main()
{
    Solution test;
    vector<int> nums{1, 2, 3, 2};
    vector<int> answer = test.productExceptSelf(nums);
    cout << "ANSWERS: " << endl;
    for (auto k : answer)
    {
        cout << k << endl;
    }
}
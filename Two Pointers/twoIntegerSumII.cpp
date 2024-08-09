#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result{}; // indices
        if (numbers.empty())
        {
            return result;
        }
        int l = numbers.size() - 1;
        int *end = &numbers[l];
        int *front = &numbers[0];
        int l_i = l + 1, f_i = 1;
        while (front != &numbers[l])
        {

            while (front != end)
            {

                if ((*front + *end) == target)
                {
                    result.push_back(f_i);
                    result.push_back(l_i);

                    return result;
                }
                end--;
                l_i--;
            }
            front++;
            f_i++;
            end = &numbers[l];
            l_i = l + 1;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> ex = {1, 3, 4, 4}; // Pairs with the front pointer being the slowest and the back pointer being index-1 (index-1 keeps being updated)
    vector<int> res{};
    res = sol.twoSum(ex, 8);
    for (auto it : res)
    {
        cout << it << endl;
    }
};
// SLOW POINTERS AND FAST POINTERS NEEDED FOR PAIRS
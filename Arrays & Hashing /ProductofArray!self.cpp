#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // Get the size of the vector
        // Note: Size does not return the amount of index's but the amount of elements
        int n = nums.size();
        // Create to vectors that will determine the left side and right side of all the products.
        vector<int> leftProducts(n);
        vector<int> rightProducts(n);
        // Create vector ans
        vector<int> ans;
        // Make the leftProducts vector first index be 1 since there is nothing to the left other than itself.
        leftProducts[0] = 1;
        rightProducts[n - 1] = 1;
        // We start at number one since we are multiply all the values from the left and we want to not reach out out of bounds due to nums[i-1] since that would return the last element if i was 0.;
        for (int i = 1; i < n; i++)
        {
            leftProducts[i] = nums[i - 1] * leftProducts[i - 1];
        }
        // We declare 'i' to be the second to last element in the vector to start multiplying all the right values.
        for (int i = n - 2; i >= 0; i--)
        {
            rightProducts[i] = nums[i + 1] * rightProducts[i + 1];
        }
        // Populate the ans vector
        for (int i = 0; i < n; i++)
        {
            ans.push_back(rightProducts[i] * leftProducts[i]);
        }

        return ans;
    }
};
// Test Case
int main()
{
    Solution test;
    vector<int> nums{1, 2, 3, 4};
    vector<int> result = test.productExceptSelf(nums);
    cout << "RESULTS: ";
    for (auto l : result)
    {
        cout << l << ", ";
    }
}
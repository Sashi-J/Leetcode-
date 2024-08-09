#include <iostream>
#include <vector>
/*
MISTAKES DONE:
- Did incorrect math calculation on the area
- Forgot to initialize int data type which kept multiplying some trash value
 */
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &heights)
    {

        int left = 0;
        int right = heights.size() - 1;
        int maxArea = 0;
        while (left < right)
        {
            int area = (right - left) * min(heights[right], heights[left]);
            maxArea = max(maxArea, area);
            if (heights[left] < heights[right])
            {
                left += 1;
            }
            else
            {
                right -= 1;
            }
        }
        return maxArea;
    }
};
// Why not sort it and make it multiply the largest numbers first

int main()
{
    Solution sol;
    vector<int> test = {1, 7, 2, 5, 4, 7, 3, 6};

    cout << sol.maxArea(test) << endl;
}

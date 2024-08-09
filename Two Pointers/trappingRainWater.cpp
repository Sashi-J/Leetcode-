#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &heights)
    {
        if (heights.empty())
        {
            return 0;
        }
        int mxArea;
        int i = 0, j = heights.size() - 1;
        int maxLeft = i, maxRight = j;
        while (i < j)
        {
            // This if condition basically acts as the minimum function of both the left and right max pointers.
            if (maxLeft < maxRight)
            {
                // Increment of pointer
                i++;
                // Update on max pointers and area.
                maxLeft = max(maxLeft, heights[i]);
                mxArea += maxLeft - heights[i];
            }
            else
            {
                // Increment of pointer
                j++;
                // Update on max pointers and area.
                maxRight = max(maxRight, heights[j]);
                mxArea += maxRight - heights[j];
            }
        }
        return mxArea;
    };
};
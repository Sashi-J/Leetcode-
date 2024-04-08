#include <iostream>
#include <string>        //Needed to have the class string
#include <unordered_map> //Needed for unordered_maps
#include <vector>        //Needed for vectors
#include <algorithm>     // Needed for sort()
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // Declare Unordered_map which contains a vector for the value since we are going to push the similar values with its connected keys. We NEED to have a vector.
        unordered_map<string, vector<string>> container;

        // Populate the map.
        for (int i = 0; i < strs.size(); i++)
        {
            // Declare temp variable since we need to maintain the original string value.
            string temp = strs[i];
            // Sort the string so we can know if the elements match with the anagram key.
            sort(temp.begin(), temp.end());
            // Check if the key has been placed before
            if (container.find(temp) == container.end())
            {
                // Create new key
                container[temp].push_back(strs[i]);
            }
            else
            {
                // Simply push to the existing key
                container[temp].push_back(strs[i]);
            }
        }
        // Declare answer vector
        vector<vector<string>> ans;
        // Populate with the answers
        for (auto x : container)
        {
            // We will be pushing back vectors of strings
            ans.push_back(x.second);
        }

        // Return answer
        return ans;
    }
};

int main()
{
    cout << "hey, friends.\n";
}

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> mySet(nums.begin(), nums.end());
        int longest = 0;

        for (int x : mySet)
        {
            if (!mySet.count(x - 1))
            {
                int length = 0;
                while (mySet.count(x + length))
                {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

int main(void)
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution sol;

    int result = sol.longestConsecutive(nums);
    cout << result;
}
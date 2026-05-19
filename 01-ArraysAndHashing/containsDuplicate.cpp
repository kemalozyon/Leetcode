#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <chrono>

using namespace std;

class Solution
{
public:
    // Solution 1
    bool containsDuplicate1(vector<int> &nums)
    {
        // O(nˆ2)
        for (int i = 0, n = nums.size() - 1; i < n; i++)
        {
            for (int j = i + 1; j < n + 1; j++)
            {
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Solution 2
    bool containsDuplicate2(vector<int> &nums)
    {
        // O(nlogn)
        sort(nums.begin(), nums.end());
        // O(n)
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }
        return false;
    }

    bool containsDuplicate3(vector<int> &nums)
    {
        // space O(n)
        set<int> mySet;
        // time complexity : O(n)
        for (int i = 0; i < nums.size(); i++)
        {
            if (mySet.count(nums[i]))
            {
                return true;
            }
            mySet.insert(nums[i]);
        }
        return false;
    }
};

int main(void)
{
    vector<int> v;

    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }

    v.push_back(99999); // adding duplicate

    Solution sol;
    vector<int> v1 = v;
    auto start = chrono::high_resolution_clock::now();
    bool value1 = sol.containsDuplicate1(v1);
    auto end = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end - start);

    vector<int> v2 = v;
    start = chrono::high_resolution_clock::now();
    bool value2 = sol.containsDuplicate2(v2);
    end = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end - start);

    vector<int> v3 = v;
    start = chrono::high_resolution_clock::now();
    bool value3 = sol.containsDuplicate3(v3);
    end = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << value1 << " Duration 1: " << duration1.count() << " us" << endl; // 11960594 us
    cout << value2 << " Duration 2: " << duration2.count() << " us" << endl; // 382 us
    cout << value3 << " Duration 3: " << duration3.count() << " us" << endl; // 46325 us
}
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> topKFreaquent(vector<int> &nums, int k)
    {
        unordered_map<int, int> myMap;
        vector<int> returnArray = {};

        int n = nums.size();

        // preparing a hashmap
        for (int i = 0; i < n; i++)
        {
            if (!myMap.count(nums[i]))
            {
                myMap[nums[i]] = 1;
            }
            else
            {
                myMap[nums[i]]++;
            }
        }

        // copying map to a vector:
        vector<pair<int, int>> vec(myMap.begin(), myMap.end());

        //sort by value;
        sort(vec.begin(), vec.end(), [](auto& x, auto& y) {
            return x.second > y.second; // ascending sort
        });

        for (int i = 0; i < k; i++)
        {
            returnArray.push_back(vec[i].first);
        }
        return returnArray;
    }

    void displayArray(vector<int>& myArray){
        cout << "[";
        for(auto& num : myArray){
            cout << num << ", ";
        }
        cout << "]";
    }
};

int main(void)
{
    Solution sol;
    vector<int> myArray = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    vector<int> myValue = sol.topKFreaquent(myArray, 2);
    sol.displayArray(myValue);
    
}
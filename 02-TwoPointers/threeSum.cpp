#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
    public:
    // vector<vector<int>> threeSum(vector<int>& nums){
    //     int n = nums.size();
    //     unordered_map<int, int> my_map;
    //     // Preparing map:
    //     for (int i = 0; i < n; i++){
    //         my_map.insert({i, nums[i]});
    //     }
    //     vector<int> myVector;

    //     int i = 0, j = n - 1;
    //     while (i < j){
    //         int target = -1 *  (nums[i] + nums[j]);

    //     }
    // }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result = {};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};
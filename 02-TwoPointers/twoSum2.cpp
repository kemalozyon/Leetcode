#include <iostream>

using namespace std;

class Solution{
    public:
    vector<int> twoSum(vector<int>& nums, int target){
        int i = 0, j = nums.size() - 1;
        while (i < j){
            int sum = nums[i] + nums[j];
            if (sum == target){
                return {i, j};
            }
            else if (sum > target){
                j--;
            }else{
                i++;
            }
        }
        return {-1, -1};
    }
};

int main(void){
    Solution sol;
    vector<int> test = {2,7,11,15};
    sol.twoSum(test, 9);
}
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution{
    public:
        // Solution 1 Brute force
        vector<int> twoSum1(vector<int>& nums, int target){
            int n = nums.size();
            for(int i = 0; i < n - 1 - 1; i++){
                for (int j = i + 1; j < n; j++){
                    if(nums[i] + nums[j] == target){
                        return {i, j};
                    }
                }
            }
            return {};
        }

        // Solution 2 using hashmap

        vector<int> twoSum2(vector<int>& nums, int target){
            unordered_map<int, int> myMap;
            int n = nums.size();
            // filling the hashmap
            for(int i = 0; i < n; i++){
                myMap[nums[i]] = i;
            }

            for(int i = 0; i < n; i++){
                if(myMap.count(target - nums[i]) && myMap[target - nums[i]] != i){
                    return {i, myMap[target - nums[i]]};
                }
            }

            return {};
        }

        vector<int> twoSum3(vector<int>& nums, int target){
            unordered_map<int, int> myMap;
            int n = nums.size();

            for (int i = 0; i < n; i++){
                if(!myMap.count(target - nums[i])){
                    myMap[nums[i]] = i;
                }
                else{
                    return {myMap[target - nums[i]], i};
                }

            }
            return {};
        }
};

int main(void){
    Solution sol;
    vector<int> myVector = {2,7,11,15};
    vector<int> myVector1 = sol.twoSum1(myVector, 9);
    vector<int> myVector2 = sol.twoSum2(myVector, 9);
    vector<int> myVector3 = sol.twoSum3(myVector, 9);
    
    for (int x : myVector3){
        cout << x << endl;
    }

}


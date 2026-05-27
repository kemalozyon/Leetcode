#include <iostream>

using namespace std;

class Solution{

public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int countZero = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] == 0) countZero++;
        }
        int product = 1;
        vector<int> resultVector = {};
        if(countZero == 0){
            for (int i = 0; i < n; i++){
                product *= nums[i];
            }
            for (int i = 0; i < n; i++){
                resultVector.push_back(product / nums[i]);
            }
        }else if (countZero == 1){
            for(int i = 0; i < n; i++) {
                if(nums[i] != 0){
                    product *= nums[i];
                }
            }
            for(int i = 0; i < n; i++){
                if(nums[i] != 0){
                    resultVector.push_back(0);
                }
                else{
                    resultVector.push_back(product);
                }
            }
        }else{
            for(int i = 0; i < n; i++){
                resultVector.push_back(0);
            }
        }

        return resultVector;
    }

    string displayResult(vector<int> result){
        string output = "[";
        for(int& x : result){
            output += to_string(x) + ", ";
        }
        output += "]";
        return output;
    }
};

int main(void){
    Solution sol;
    vector<vector<int>> nums = {{1,2,3,4}, {-1,1,0,-3,3}};
    vector<int> result = {};
    int n = nums.size();
    string output = "";
    for (int i = 0; i < n; i++){
        cout << "### Test Case" << i + 1 << " ###"<< endl;
        result = sol.productExceptSelf(nums[i]);
        output = sol.displayResult(result);
        cout << output << endl;
    }

}
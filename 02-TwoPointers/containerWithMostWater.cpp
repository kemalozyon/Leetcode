#include <iostream>

using namespace std;
class Solution{
    public:
        int maxArea(vector<int>& height){
            int n = height.size();
            int i = 0, j = n - 1;
            int max = 0;
            int dif = n - 1, length;
            while (i < j){
                if(height[i] > height[j]){
                    length = dif * height[j];
                    j--;
                    dif--;

                }else if(height[j] > height[i]){
                    length = dif * height[i];
                    dif--;
                    i++;
                }else{
                    length = dif * height[i];
                    i++;
                    j--;
                    dif-=2;
                }
                if(length > max){
                    max = length;
                }
            }
            return max;
        }
};

int main(void){
    vector<int> myVector = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    cout << sol.maxArea(myVector) << endl;
}
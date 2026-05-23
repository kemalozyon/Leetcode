#include <iostream>
#include <algorithm>

using namespace std;
class Solution{
    public:
        vector<vector<string>> groupAnagrams1(vector<string>& strs){
            vector<vector<string>> returnVector = {};
            vector<string> valueVector = {};
            int n = strs.size();
            for (int i = 0; i < n; i++){
                    valueVector.push_back(strs[i]);
                    string s = strs[i];
                    strs.erase(strs.begin() + i);
                    n = strs.size(); // we need to update the n since it is decreasing each deletion iteration
                    i--;
                for (int j = 0; j < n; j++){
                    string k = strs[j];
                    sort(s.begin(), s.end());
                    sort(k.begin(), k.end());
                    if( s == k){
                        valueVector.push_back(strs[j]);
                        strs.erase(strs.begin() + j);
                        n = strs.size(); // we need to update the n since it is decreasing each deletion iteration
                        j--; // Doing that is important since we will delete the current index to reach the value that what we was there
                    }
                }
                returnVector.push_back(valueVector);
                valueVector = {};
            }
            return returnVector;
        }
        
        void displayResult(vector<vector<string>> result){
            int n = result.size();
            string output="[";
            for(int i = 0; i < n; i++){
                int m = result[i].size();
                output+="[";
                for (int j = 0; j < m; j++){
                    output += result[i][j] + ", ";
                }
                output += "]";
            }
            output += "]";
            cout << output << endl;
        }

};


int main(void){
    Solution sol;

    vector<string> myVector = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = sol.groupAnagrams1(myVector);
    sol.displayResult(result);
}
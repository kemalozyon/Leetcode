#include <iostream>
#include <algorithm>
#include <set>


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

        vector<vector<string>> groupAnagrams2(vector<string>& strs){
            vector<vector<string>> returnValue = {};
            vector<string> valueVector = {};
            set<int> mySet;

            int n = strs.size();
            
            for (int i = 0; i < n; i++){
                while (mySet.count(i)){
                    i++;
                }
                if (i>=n) break;
                valueVector.push_back(strs[i]);
                if(i != n){
                    for (int j = i + 1; j < n; j++){
                        if (mySet.count(j)) continue;
                        string s = strs[i], t = strs[j];
                        if (s.length() != t.length()) continue;
                        int count[26] = {0};
                        // check if it is anagram or not
                        for(int k = 0; k < (int)s.length(); k++){
                            count[s[k] - 'a']++;
                            count[t[k] - 'a']--;
                        }
                        bool checkAnagram = false;
                        for(int m = 0; m < 26; m++){
                            if(count[m] != 0) checkAnagram = true;
                        }
                        if(checkAnagram) continue;

                        mySet.insert(j);
                        valueVector.push_back(t);
                    }
                }
                returnValue.push_back(valueVector);
                valueVector = {};
            }
            return returnValue;
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
    vector<vector<string>> result2 = sol.groupAnagrams2(myVector);
    vector<vector<string>> result = sol.groupAnagrams1(myVector);
    sol.displayResult(result);
    sol.displayResult(result2);
}
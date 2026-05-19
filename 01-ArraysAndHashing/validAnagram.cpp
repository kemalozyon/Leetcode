#include <iostream>
#include <algorithm> 
#include <string>

using namespace std;

class Solution{
    public:

        // First solution coming to my mind
        bool isAnagram1(string s, string t){
            // O(nlogn)
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
        }

        bool isAnagram2(string s, string t){
            // Constraint : If every single element is small char
            if(s.length() != t.length()) return false;
            int count[26] = {0};

            for(int i = 0; i < s.length(); i++){
                count[s[i] - 'a']++;
                count[t[i] - 'a']--;
            }

            for(int i = 0; i < 26; i++){
                if(count[i] != 0) return false;
            }
            return true;
        }

};


int main(void){
    Solution sol;
    bool value = sol.isAnagram2("sakarya", "aksaray");
    cout << value << endl;
}

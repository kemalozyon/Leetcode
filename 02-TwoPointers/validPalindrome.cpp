#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string myString = "";
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (c >= 'A' && c <= 'Z')
            {
                c += 32;
                myString += c;
            }
            else if (c >= 'a' && c <= 'z')
            {
                myString += c;
            }
            else if (c >= '0' && c <= '9')
            {
                myString += c;
            }
        }

        int i = 0, j = myString.size() - 1;
        while (i <= j)
        {
            if (myString[i] == myString[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main(void){
    string test = "A man, a plan, a canal: Panama";
    Solution sol;
    cout << sol.isPalindrome(test) << endl;
}
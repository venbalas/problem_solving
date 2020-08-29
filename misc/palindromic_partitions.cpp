#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> decompInProgress;
        decompose(s, 0, result, decompInProgress);

        return result;
    }

    void decompose(std::string s, int start, vector<vector<string>> &result, vector<string> decompInProgress)
    {
        if (start == s.size())
        {
            result.push_back(decompInProgress);
        }
        else
        {
            for (int i = start; i < s.size(); i++)
            {
                auto segment = s.substr(start, i-start+1);
                if (isPalindrome(segment))
                {
                    decompInProgress.push_back(segment);
                    decompose(s, i + 1, result, decompInProgress);
                    decompInProgress.pop_back();
                }
            }
        }
    }

    bool isPalindrome(std::string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != s[s.size() - 1 - i])
                return false;
        }

        return true;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    auto result = s.partition("aab");

    for(auto palindrome_array:result) {

        for(auto str: palindrome_array) {
            cout<<str<<" ";
        }
        cout<<endl;
    }

}
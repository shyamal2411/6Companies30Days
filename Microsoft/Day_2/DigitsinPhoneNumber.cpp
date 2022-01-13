#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<string> ans;
    string keypad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv",
                        "wxyz"};
       
    vector<string> letterCombinations(string digits) {
    if(digits.empty())
        return ans;
        string path = digits;
        backtrack(0, path, digits);
        return ans;
    }
    
    void backtrack(int index, string &path, const string &digits){
        if(index == digits.size()){
            ans.push_back(path);
            return;
        }
        for(char c : keypad[digits[index] - '0']){
            path[index] = c;
            backtrack(index + 1, path, digits);
        }
    }    
};

int main(){
    Solution ss;
    vector<string> ans = ss.letterCombinations("23");
    for(auto a: ans)
        cout<<a<<" ";
    return 0;
}
#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
    string repeat(string s,int times){
        string ans = "";
        for(int i = 0; i < times; i++)
            ans += s;
        
        return ans;
    }
    
    string decodeString(string s) {
        int i = 0;
        while(i < s.size()){
            if(s[i] != ']'){
                i++;
                continue;
            }
            int j = i;
            while(s[j] != '[')
                j--;
            
            string lettersToRepeat = s.substr(j+1, i-j-1);
            int k = j;
            j--;
            
            while((j>0) && (isdigit(s[j])))
                j--;
            
            if(j != 0)
                j++;
            int timesToRepeat = stoi(s.substr(j, k - j));
            
            s.replace(j, i-j+1, repeat(lettersToRepeat, timesToRepeat));
            
            i = j + lettersToRepeat.size() * timesToRepeat;
        }
        return s;
    }
};

int main(){
    Solution obj;
    string s = "2[abc]3[cd]ef";
    cout << obj.decodeString(s) << endl;
    return 0;
}
#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string gcdOfStrings(string a, string b) {
        if(a+b == b+a)
            return a.substr(0, gcd(a.size(), b.size()));
        else
            return "";
    }
};

int main(){
    Solution ss;
    string a = "ABCABC";
    string b = "ABC";
    cout<<ss.gcdOfStrings(a,b)<<endl;
    return 0;
}
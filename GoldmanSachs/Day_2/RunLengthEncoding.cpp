#include<iostream> 
using namespace std;


class Solution{
    public:
void RuleLengthEncoding(string s){

    int n = s.size();
    for(int i =0; i < n; i++){
        int count = 1;
        while(i < n-1 && s[i] == s[i+1])
        {
            count++;
            i++;
        }
    cout<<s[i]<<count;
    }
}
};

int main(){
    string s;
    Solution ss;
    s = "wwwwaaadexxxxxxywww";
    ss.RuleLengthEncoding(s);
    return 0;
}
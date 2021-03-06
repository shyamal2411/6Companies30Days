#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int CountWays(string s){
		    int n = s.size();
		    int dp[n+1];
		    int mod = 1e9+7;
		    dp[0] = 1;
		    dp[1] = 1;
		    
		    if(n == 1 && s[0]!='0')
		    return 1;
		    
		    if(s[0] == '0')
		    return 0;
		    
		    for(int i = 2; i <= n; i++){
		        dp[i] = 0;
		        
		        if(s[i-1] > '0')
		        dp[i] = dp[i-1];
		        
		        if(s[i-2] == '1' || s[i-2] == '2' && s[i-1] < '7')
		        dp[i] = (dp[i] + dp[i-2]) % mod;
		    }
		    return dp[n];
		    }

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
} 
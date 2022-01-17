#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum = 0;
        for(auto a: nums)
            sum += a; // Presum
        
        if(sum % 2)
            return false;
        
        sum /= 2;
        vector<bool> dp(sum+1, false); //vector of each number is subset or not
        dp[0] = true;
        
        for(auto a:nums){
            for(int i = sum; i>= a; i--){
                dp[i] = dp[i] || dp[i-a]; //either use it or not
            }
        }
        return dp[sum];
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 5, 11, 5};
    cout<<s.canPartition(nums);
    return 0;
}
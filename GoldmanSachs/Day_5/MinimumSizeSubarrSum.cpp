#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i, j, k, ans = INT_MAX;
        vector<int> sum(n);
        sum[0] = nums[0];
        for(i=1;i<n;i++)
            sum[i]=sum[i-1] + nums[i];
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                int finalsum = sum[j] - sum[i] + nums[i];
                if(finalsum >=target){
                    ans = min(ans, (j-i+1));
                    break;
                }
            }
        }
        return (ans != INT_MAX) ? ans:0;
    }
};
// Time: O(n^2)

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
            cin >> nums[i];
        int target;
        cin >> target;
        Solution obj;
        int ans = obj.minSubArrayLen(target, nums);
        cout << ans << "\n";
    }
    return 0;
}
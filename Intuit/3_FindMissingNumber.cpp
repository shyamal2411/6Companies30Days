#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int res = 0;
        // for (int i = 0; i < nums.size(); i++)
        //     res ^= nums[i]^(i+1);
        // return res;
         int n=nums.size();
         int low = 0, high = n - 1;
         int mid;

  while ((high - low) > 1) {
    mid = (low + high) / 2;

    if ((nums[low] - low) != (nums[mid] - mid))
      high = mid;
    else if ((nums[high] - high) != (nums[mid] - mid))
      low = mid;
  }
  return (nums[low] + 1);
    }
};

int main(){
    Solution ss;
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    cout << ss.missingNumber(nums) << endl;
    return 0;
}
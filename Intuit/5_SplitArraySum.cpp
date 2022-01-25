#include<bits/stdc++.h> 
using namespace std;

class Solution {
private:

    bool doable (const vector<int>& nums, int cuts, long long max) {
        
        // 'acc' is the temporary accumulator for the currently processed group.
        
        int acc = 0;
        for (num : nums) {
            
            if (num > max) return false;
            
            else if (acc + num <= max) acc += num;            
            else {
                --cuts;
                acc = num;
                
                // If we've used up all cuts, this means this 'max' is not doable.
                if (cuts < 0) return false;
            }
        }
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        
        for (num : nums) {
            left = max(left, (long long)num);
            right += num;
        }
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (doable(nums, m - 1, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main(){
    Solution ss;
    vectorq<int> nums = {1,2,3,4,5,6,7,8,9,10};
    cout << ss.splitArray(nums, 5) << endl;
    return 0;
}
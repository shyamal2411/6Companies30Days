#include<bits/stdc++.h> 
using namespace std;

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/submissions/
class Solution {
public:
    int shipWithinDays(vector<int>& wt, int days) {
        int maxx = 0, sum = 0;
        for(int val : wt){
            sum += val; //pre sum of all weights
            maxx = max(maxx, val);
        }
        // if at any place size = days given, return max
        if(wt.size() == days)
            return maxx;
            // Applying binary search
        int low = maxx;
        int high = sum;
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(isPossible(wt, mid, days) == true){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    bool isPossible(vector<int> &wt, int mid, int days){
        int d = 1;
        int sum = 0;
        for(int i = 0; i < wt.size(); i++){
            sum+= wt[i];
            
            if(sum > mid){
                d++;
                sum = wt[i];
            }
        }
        return d<=days;
    } 
};

int main(){
    Solution s;
    vector<int> wt = {1,2,3,4,5,6,7,8,9,10};
    cout<<s.shipWithinDays(wt, 5)<<endl;
    return 0;
}

// To do questions: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/discuss/256729/JavaC%2B%2BPython-Binary-Search
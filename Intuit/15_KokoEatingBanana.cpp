#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000;
        
        // Binaru search
        while(left <= right){
            int mid = left + (right - left) / 2;
            // if koko can eat, mid bananas per hour in less than or equal to h time
            if(help(piles, mid, h))
                right = mid - 1; //decrement right pointer
            else
                left = mid + 1; //increment left pointer
        }
        return left; //left pointer hold our optimized k, at the end of Binary search
    }
    
    bool help(vector<int> &piles, int k, int h){
        int hours = 0; //track hours
        /*
        Example
        k = 4
        pile = 10
        pile / k = 10/4 = 2
        pile%k=2, so we need to have one more hour to eat remaining bananas left over as reminder
        */
        
        for(int p: piles){
            int div = p / k;
            hours += div;
            if(p % k!=0)
                hours++; // we need extra hour
        }
        return hours <= h;
    }
};

int main(){
    Solution s;
    vector<int> piles = {3,6,7,11};
    cout<<s.minEatingSpeed(piles, 8);
    return 0;
}
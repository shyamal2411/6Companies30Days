#include<bits/stdc++.h> 
using namespace std;

// https://leetcode.com/problems/number-of-boomerangs/
class Solution{
    public:
   int numberOfBoomerangs(vector<vector<int>>& points) {
    int ans = 0, n = points.size();
    for(int i=0;i<n;i++) {
        unordered_map<int,int>mp;
        for(int j=0;j<n;j++) {
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];
            int dis = dx*dx + dy*dy;
            // we can pair jth point with any other point we have found till now
            // as ordering also matter, so multiplied by 2
            ans += mp[dis]*2;
            mp[dis]++;
        }
    }
    return ans;
}
};

int main(){
    Solution ss;
    vector<vector<int>> points = {{0,0},{1,0},{2,0}};
    cout<<ss.numberOfBoomerangs(points)<<endl;
    return 0;
}
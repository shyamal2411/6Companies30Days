#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty())
            return 0;
        int n = isConnected.size(), i, j;
        
        vector<bool> visited(n,false);
        int city = 0;
        for(int i = 0;i<visited.size();i++){
             city += !visited[i] ? dfs(i, isConnected, visited), 1 : 0;
        }
        return city;
    }
    void dfs(int i, vector<vector<int>> &isConnected, vector<bool> &visited){
        visited[i]=true;
        for(int j=0;j<visited.size();j++){
            if(i!=j && isConnected[i][j] && !visited[j])
                dfs(j, isConnected, visited);
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> isConnected{{1,1,0},{1,1,0},{0,0,1}};
    cout<<s.findCircleNum(isConnected);
    return 0;
}
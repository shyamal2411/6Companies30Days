#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int count=0, temp=0;
    void dfs(vector<vector<int>> &grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!=1)    
            return;
        
        grid[i][j] =-1;
        count++;
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);

        temp = max(temp, count);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int i,j, m = grid[0].size();
        
        for(i = 0;i<n;i++){
            for(j = 0;j<m;j++){
                if(grid[i][j]==1){
                    count=0;
                    dfs(grid, i, j);
                }
            }
        }
        return temp;
    }
    
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    cout<<s.maxAreaOfIsland(grid);
    return 0;
}
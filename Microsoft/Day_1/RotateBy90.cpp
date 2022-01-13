#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
       for(int i = 0; i < matrix.size(); i++){
           for(int j = 0; j < i; j++)
               swap(matrix[i][j], matrix[j][i]);
       }
        
        for(int i = 0; i < matrix.size(); i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(matrix);
    for(auto a: matrix)
        for(auto b: a)
            cout<<b<<" ";
    return 0;
}
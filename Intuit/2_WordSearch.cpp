#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0;i< board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(adjacent(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool adjacent(vector<vector<char>> &board, string &word, int i, int j, int index){
        if(index == word.size())
            return true;
        
        if(i<0 || j<0 || i> board.size()-1 || j> board[0].size()-1)
            return false;
        
        if(board[i][j]!=word[index])
            return false;
        
        board[i][j]='-';
          bool further = adjacent(board, word, i+1, j, index+1) ||
                       adjacent(board, word, i-1, j, index+1) ||
                       adjacent(board, word, i, j-1, index+1) ||
                       adjacent(board, word, i, j+1, index+1);
        board[i][j]=word[index];
        return further;
    }
};

int main(){
    Solution ss;
    vector<vector<char>>  board = {{"A","B","C","E"}, {"S","F","C","S"}, {"A","D","E","E"}};
    ss.adjacent(board, "SEE", 0, 0, 0);
    if(ss.exist(board, "SEE"))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
        return 0;
}
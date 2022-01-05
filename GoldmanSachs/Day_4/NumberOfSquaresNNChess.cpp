
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long squaresInChessBoard(long long N) {
       long long ans = (N*(N+1)*(2*N+1))/6;
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
}  
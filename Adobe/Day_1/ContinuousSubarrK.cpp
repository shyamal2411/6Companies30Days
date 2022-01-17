#include<bits/stdc++.h> 
using namespace std;

#define int long long 
#define nl "\n"
const int M=1e5 + 5;
typedef vector<int> vi;
#define f(i,a,n) for(int i=a;i<n;i++)
#define rf(i,a,n) for(int i=n-1;i>=a;i--)
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cin.tie(0);cout.tie(0);
#define read(arr,n) for(int i=0;i<n;i++)cin>>arr[i];
#define pr(arr,n) for(int i=0;i<n;i++)cout<<arr[i];
#define in cin>>
#define out cout<<
#define first fr
#define second sc

void printt(vector<int> &arr, int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}

int subarrSum1(vector<int> arr, int n, int sum){
    for(int i = 0; i < n; i++){
        int curSum=0;
        for(int j = i+1; j < n; j++){
            if(curSum == sum){
                cout<<i<<" "<<j<<endl;
                return 1; 
            }
            else if(curSum > sum){
                break;
            }
                curSum += arr[j];           
        }
    }
    cout<<"NULL"<<endl;
    return 0;
}

int subarrSum2(vector<int> arr, int n, int sum)
{
    int cursum = arr[0], start = 0, i,j;
    for(i = 1; i <= n; i++){
        while(cursum > sum and start < i-1){
            cursum -= arr[start];
            start++;
        }
        if(cursum == sum){
            cout<<start<<" "<<i-1<<endl;
            return 1;
        }
        cursum += arr[i]; 
    }
    cout<<"NULL"<<endl;
    return 0;
}

void solve(){
 int size;
 cin>>size;
    vector<int> arr(size);
    read(arr,size);
    int sum = 23;
    // subarrSum1(arr,size,sum);
    subarrSum2(arr,size,sum);
    // rev(arr, 0, size-1);
    // printt(arr, size);
}

int32_t main(){
    FIO int t; t=1;
    //in t;
    while(t--) solve();
  
return 0;
}
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int tab(vector<int>& height, int n, int k){
        vector<int> dp(n,0);
        
        for(int i=1;i<n;i++){
            int steps=INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    int s=abs(height[i]-height[i-j])+dp[i-j];
                    steps=min(steps,s);
                }
            }
            dp[i]=steps;
        }
        return dp[n-1];
    }
    
    int mem(vector<int>& height, int i, int k, vector<int>&dp){
        if(i==0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int steps=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int s=abs(height[i]-height[i-j])+mem(height, i-j, k, dp);
                steps=min(steps,s);
            }
        }
        return dp[i]=steps;
    }
    
    
    int helper(vector<int>& height, int i, int k){
        if(i==0){
            return 0;
        }
        int steps=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int s=abs(height[i]-height[i-j])+helper(height, i-j, k);
                steps=min(steps,s);
            }
        }
        return steps;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        // return helper(height, n-1, k);
        
        // vector<int> dp(n,-1);
        // return mem(height, n-1, k, dp);
        
        return tab(height, n, k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends
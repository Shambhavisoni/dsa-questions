//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int s_opt(vector<int>& height, int n) {
        // Code here
        int prev2=0, prev1=0;
        
        for(int i=1;i<n;i++){
            int oneStep=abs(height[i]-height[i-1])+prev1;
            int twoSteps=INT_MAX;
            if(i>1){
                twoSteps=abs(height[i]-height[i-2])+prev2;
            }
            int curr=min(oneStep, twoSteps);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
        
    }
    int tab(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n,0);
        
        for(int i=1;i<n;i++){
            int oneStep=abs(height[i]-height[i-1])+dp[i-1];
            int twoSteps=INT_MAX;
            if(i>1){
                twoSteps=abs(height[i]-height[i-2])+dp[i-2];
            }
            dp[i]=min(oneStep, twoSteps);
        }
        return dp[n-1];
        
    }
    int mem(vector<int>& height, int i, vector<int>& dp) {
        // Code here
        if(i==0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int oneStep=abs(height[i]-height[i-1])+mem(height, i-1, dp);
        int twoSteps=INT_MAX;
        if(i>1){
            twoSteps=abs(height[i]-height[i-2])+mem(height, i-2, dp);
        }
        return dp[i]=min(oneStep, twoSteps);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        // return recur(height, n-1);
        
        // vector<int> dp(n,-1);
        // return mem(height, n-1, dp);
        
        // return tab(height, n);
        
        return s_opt(height, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends
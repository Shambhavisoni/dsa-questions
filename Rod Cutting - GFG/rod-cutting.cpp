//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int sO(int price[], int n){
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        
        for(int i=0;i<=n;i++){
            prev[i]=i*price[0];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int take=INT_MIN;
                int rodLength=i+1;
                if(j>=rodLength){
                    take=price[i]+curr[j-rodLength];
                }
                int notTake=prev[j];
                curr[j]=max(take, notTake);
            }
            prev=curr;
        }
        return prev[n];
    }
    int tab(int price[], int n){
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        
        for(int i=0;i<=n;i++){
            dp[0][i]=i*price[0];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int take=INT_MIN;
                int rodLength=i+1;
                if(j>=rodLength){
                    take=price[i]+dp[i][j-rodLength];
                }
                int notTake=dp[i-1][j];
                dp[i][j]=max(take, notTake);
            }
        }
        return dp[n-1][n];
    }
    // int tab(int price[], int n){
    //     vector<vector<int>> dp(n+1, vector<int>(n, 0));
        
    //     for(int i=0;i<=n;i++){
    //         dp[i][0]=i*price[0];
    //     }
        
    //     for(int i=0;i<=n;i++){
    //         for(int j=1;j<n;j++){
    //             int take=INT_MIN;
    //             int rodLength=j+1;
    //             if(i>=rodLength){
    //                 take=price[j]+dp[i-rodLength][j];
    //             }
    //             int notTake=dp[i][j-1];
    //             dp[i][j]=max(take, notTake);
    //         }
    //     }
    //     return dp[n][n-1];
    // }
    int mem(int price[], int n, int i, vector<vector<int>>& dp){
        if(i==0){
            return n*price[i];
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        int take=INT_MIN;
        int rodLength=i+1;
        if(n>=rodLength){
            take=price[i]+mem(price, n-rodLength, i, dp);
        }
        int notTake=mem(price, n, i-1, dp);
        return dp[n][i]=max(take, notTake);
    }
    int recur(int price[], int n, int i){
        if(i==0){
            return n*price[i];
        }
        int take=INT_MIN;
        int rodLength=i+1;
        if(n>=rodLength){
            take=price[i]+recur(price, n-rodLength, i);
        }
        int notTake=recur(price, n, i-1);
        return max(take, notTake);
    }
    int cutRod(int price[], int n) {
        //code here
        
        // return recur(price, n, n-1);
        
        // vector<vector<int>> dp(n+1, vector<int>(n, -1));
        // return mem(price, n, n-1, dp);
        
        // return tab(price, n);
        
        return sO(price, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
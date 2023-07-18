//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int tab(int N, int arr[]){
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        // for(int i=0;i<N;i++){
        //     dp[i][i]=0;
        // }
        
        for(int i=N-1;i>=1;i--){
            for(int j=1;j<N;j++){
                if(i==j){
                    dp[i][i]=0;
                }
                else{
                    int mini=1e9;
                    for(int k=i;k<j;k++){
                        int steps=arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                        mini=min(steps, mini);
                    }
                    dp[i][j]=mini;
                }
                
            }
        }
        return dp[1][N-1];
    }
    int mem(int N, int arr[], int i, int j, vector<vector<int>>& dp){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=1e9;
        for(int k=i;k<j;k++){
            int steps=arr[i-1]*arr[k]*arr[j] + mem(N, arr, i, k, dp) + mem(N, arr, k+1, j, dp);
            mini=min(steps, mini);
        }
        return dp[i][j]=mini;
    }
    int recur(int N, int arr[], int i, int j){
        if(i==j){
            return 0;
        }
        int mini=1e9;
        for(int k=i;k<j;k++){
            int steps=arr[i-1]*arr[k]*arr[j] + recur(N, arr, i, k) + recur(N, arr, k+1, j);
            mini=min(steps, mini);
        }
        return mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        // return recur(N, arr, 1, N-1);
        
        // vector<vector<int>> dp(N, vector<int>(N, -1));
        // return mem(N, arr, 1, N-1, dp);
        
        return tab(N, arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
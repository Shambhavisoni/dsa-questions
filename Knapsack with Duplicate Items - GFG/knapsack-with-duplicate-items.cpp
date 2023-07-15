//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int tab(int n, int w, int val[], int wt[]){
        vector<vector<int>> dp(n, vector<int>(w+1, 0));
        
        for(int i=0;i<=w;i++){
            if(w>=wt[i]){
                dp[0][i]=val[0]*(i/wt[0]);
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=w;j>=0;j--){
                int take=INT_MIN, notTake=INT_MIN;
                if(j>=wt[i]){
                    take=val[i]+dp[i][j-wt[i]];
                }
                // else{
                    notTake=dp[i-1][j];
                // }
                dp[i][j]=max(take, notTake);
            }
        }
        return dp[n-1][w];
    }
    int mem(int w, int val[], int wt[], int i, vector<vector<int>>& dp){
        if(i==0){
            if(w>=wt[i]){
                return val[i]*(w/wt[i]);
            }
            else{
                return 0;
            }
        }
        if(dp[w][i]!=-1){
            return dp[w][i];
        }
        int take=INT_MIN;
        if(w>=wt[i]){
            take=val[i]+mem(w-wt[i], val, wt, i, dp);
        }
        int notTake=mem(w, val, wt, i-1, dp);
        return dp[w][i]=max(take, notTake);
    }
    int recur(int w, int val[], int wt[], int i){
        if(i==0){
            if(w>=wt[i]){
                return val[i]*(w/wt[i]);
            }
            else{
                return 0;
            }
        }
        int take=INT_MIN;
        if(w>=wt[i]){
            take=val[i]+recur(w-wt[i], val, wt, i);
        }
        int notTake=recur(w, val, wt, i-1);
        return max(take, notTake);
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        // return recur(w, val, wt, n-1);
        
        vector<vector<int>> dp(w+1, vector<int>(n, -1));
        return mem(w, val, wt, n-1, dp);
        
        // return tab(n, w, val, wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
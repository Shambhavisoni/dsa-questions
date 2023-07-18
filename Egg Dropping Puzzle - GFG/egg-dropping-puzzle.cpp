//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int mem(int eggs, int floors, vector<vector<int>>& dp){
        if(eggs==1){
            return floors;
        }
        if(floors==0 || floors==1){
            return floors;
        }
        if(dp[eggs][floors]!=-1){
            return dp[eggs][floors];
        }
        int mini=1e9;
        for(int k=1;k<=floors;k++){
            int attempts = 1 + max(mem(eggs-1, k-1, dp), mem(eggs, floors-k, dp));

            mini=min(mini, attempts);
        }
        return dp[eggs][floors]=mini;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return mem(n, k, dp);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
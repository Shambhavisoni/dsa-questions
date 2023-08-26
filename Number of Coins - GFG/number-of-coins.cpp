//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int recur(int coins[], int i, int v, vector<vector<int>>& dp){
	    if(v==0){
	        return 0;
	    }
	    if(i==0){
	        if(v%coins[0]==0){
	            return v/coins[0];
	        }
	        return 1e9;
	    }
	    
	    if(dp[i][v]!=-1){
	        return dp[i][v];
	    }
	    
	    int take=1e9;
	    if(v>=coins[i]){
	        take=1+recur(coins, i, v-coins[i], dp);
	    }
	    int notTake=recur(coins, i-1, v, dp);
	    
	    return dp[i][v]=min(take, notTake);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(M, vector<int>(V+1, 1e9));
	   // int ans=recur(coins, M-1, V, dp);
	    
	    for(int i=0;i<M;i++){
	        dp[i][0]=0;
	    }
	    for(int i=0;i<=V;i++){
	        if(i%coins[0]==0){
	            dp[0][i]=i/coins[0];
	        }
	    }
	    
	    for(int i=1;i<M;i++){
	        for(int j=1;j<=V;j++){
	            int take=1e9;
        	    if(j>=coins[i]){
        	        take=1+dp[i][j-coins[i]];
        	    }
        	    int notTake=dp[i-1][j];
        	    
        	    dp[i][j]=min(take, notTake);
	        }
	    }
	    int ans=dp[M-1][V];
	    if(ans==1e9){
	        return -1;
	    }
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
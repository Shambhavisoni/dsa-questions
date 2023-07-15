//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int sO(int arr[], int n){
	    vector<int> p(n+1, 0);
	    vector<int> c(n+1, 0);
	    
	    for(int curr=n-1;curr>=0;curr--){
	        for(int prev=curr-1;prev>=-1;prev--){
	            int take=0;
        	    if(prev==-1 || arr[prev]<arr[curr]){
        	        take=arr[curr]+c[curr+1];
        	    }
        	    int notTake=c[prev+1];
        	    p[prev+1]=max(take, notTake);
	        }
	        c=p;
	    }
	    return c[0];
	}
	int tab(int arr[], int n){
	    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	    
	    for(int curr=n-1;curr>=0;curr--){
	        for(int prev=curr-1;prev>=-1;prev--){
	            int take=0;
        	    if(prev==-1 || arr[prev]<arr[curr]){
        	        take=arr[curr]+dp[curr+1][curr+1];
        	    }
        	    int notTake=dp[curr+1][prev+1];
        	    dp[curr][prev+1]=max(take, notTake);
	        }
	    }
	    return dp[0][0];
	}
	int mem(int arr[], int curr, int prev, int n, vector<vector<int>>& dp){
	    if(curr>=n){
	        return 0;
	    }
	    if(dp[curr][prev+1]!=-1){
	        return dp[curr][prev+1];
	    }
	    int take=0;
	    if(prev==-1 || arr[prev]<arr[curr]){
	        take=arr[curr]+mem(arr, curr+1, curr, n, dp);
	    }
	    int notTake=mem(arr, curr+1, prev, n, dp);
	    return dp[curr][prev+1]=max(take, notTake);
	}
	int recur(int arr[], int curr, int prev, int n){
	    if(curr>=n){
	        return 0;
	    }
	    int take=0;
	    if(prev==-1 || arr[prev]<arr[curr]){
	        take=arr[curr]+recur(arr, curr+1, curr, n);
	    }
	    int notTake=recur(arr, curr+1, prev, n);
	    return max(take, notTake);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	   // return recur(arr, 0, -1, n);
	    
	   // vector<vector<int>> dp(n, vector<int>(n+1, -1));
	   // return mem(arr, 0, -1, n, dp);
	    
	   // return tab(arr, n);
	    
	    return sO(arr, n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int mem(int W, int wt[], int val[], int i, int n, vector<vector<int>>& dp){
        if(W==0){
            return 0;
        }
        if(i==0){
            if(wt[0]<=W){
                return val[0];
            }
            return 0;
        }
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        int take=INT_MIN;
        if(W>=wt[i]){
            take = val[i] + mem(W-wt[i], wt, val, i-1, n, dp);
        }
        int notTake = mem(W, wt, val, i-1, n, dp);
        return dp[i][W]=max(take, notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> prev(W+1, 0);
       vector<int> curr(W+1, 0);
       
    //   for(int i=0;i<n;i++){
    //       dp[i][0]=0;
    //   }
       
       for(int w=0;w<=W;w++){
           if(wt[0]<=w){
               prev[w]=val[0];
           }
       }
       
       for(int i=1;i<n;i++){
           curr[0]=0;
           for(int w=1;w<=W;w++){
               int take=INT_MIN;
                if(w>=wt[i]){
                    take = val[i] + prev[w-wt[i]];
                }
                int notTake = prev[w];
                curr[w]=max(take, notTake);
           }
           prev=curr;
       }
       return prev[W];
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
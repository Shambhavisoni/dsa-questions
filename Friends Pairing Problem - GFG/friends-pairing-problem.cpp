//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int mod=1e9 + 7;
    long long helper(int n, vector<long long>& dp){
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        long long single = helper(n-1, dp) % mod;
        long long pair = (((n-1) % mod) * (helper(n-2, dp) % mod)) % mod;
        return dp[n]=((single % mod) + (pair % mod)) % mod;
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<long long> dp(n+1, -1);
        return (int)helper(n, dp);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends
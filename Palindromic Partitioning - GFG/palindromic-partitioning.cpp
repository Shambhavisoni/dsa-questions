//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPal(string s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int mem(string s, int i, int j, vector<vector<int>>& dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=1e9;
        for(int k=i;k<=j;k++){
            if(isPal(s, i, k)){
                int cut;
                if(k==j){
                    cut=0;
                }
                else{
                   cut=1+mem(s, k+1,j, dp);
                }
                mini=min(mini, cut);
            }
        }
        return dp[i][j]=mini;
    }
    int recur(string s, int i, int j){
        if(i>=j){
            return 0;
        }
        int mini=1e9;
        for(int k=i;k<=j;k++){
            if(isPal(s, i, k)){
                int cut;
                if(k==j){
                    cut=0;
                }
                else
                   cut=1+recur(s, k+1,j);
                mini=min(mini, cut);
            }
        }
        return mini;
    }
    int palindromicPartition(string s)
    {
        // code here
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return mem(s, 0, n-1, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
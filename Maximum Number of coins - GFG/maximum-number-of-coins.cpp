//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int maxCoins(int n, vector <int> &a)
        {
                // write your code here
                // int n = a.size();
                a.push_back(1);
                a.insert(a.begin(), 1);
                vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
                for (int i = n; i >= 1; i--) {
                    for (int j = 1; j <= n; j++) {
                        if (i > j) continue;
                        int maxi = INT_MIN;
                        for (int ind = i; ind <= j; ind++) {
                            int cost = a[i - 1] * a[ind] * a[j + 1] +
                                    dp[i][ind - 1] + dp[ind + 1][j];
                            maxi = max(maxi, cost);
                        }
                        dp[i][j] = maxi;
                    }
                }
                return dp[1][n];
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int tab(vector<vector<int>>& points, int n){
        vector<vector<int>> dp(n, vector<int>(4,0));
        dp[0][0]=max(points[0][1],points[0][2]);
        dp[0][1]=max(points[0][0],points[0][2]);
        dp[0][2]=max(points[0][0],points[0][1]);
        dp[0][3]=max(points[0][0],max(points[0][1], points[0][2]));

        for(int day=1;day<n;day++){
            for(int prev_act=0;prev_act<4;prev_act++){
                int maxi=0;
                for(int i=0;i<3;i++){
                    if(i!=prev_act){
                        int act=points[day][i]+dp[day-1][i];
                        maxi=max(maxi,act);
                    }
                }
                dp[day][prev_act]=maxi;
            }
        }
        return dp[n-1][3];
    }
    int mem(vector<vector<int>>& points, int day, int prev_act, vector<vector<int>>& dp){
        if(day==0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(i!=prev_act){
                    maxi=max(maxi,points[0][i]);
                }
            }
            return maxi;
        }
        if(dp[day][prev_act]!=-1){
            return dp[day][prev_act];
        }
        
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=prev_act){
                int act=points[day][i]+mem(points, day-1, i, dp);
                maxi=max(maxi,act);
            }
        }
        return dp[day][prev_act]=maxi;
    }
    int recur(vector<vector<int>>& points, int day, int prev_act){
        if(day==0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(i!=prev_act){
                    maxi=max(maxi,points[0][i]);
                }
            }
            return maxi;
        }
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=prev_act){
                int act=points[day][i]+recur(points, day-1, i);
                maxi=max(maxi,act);
            }
        }
        return maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        // return recur(points, n-1, n);
        
        // vector<vector<int>> dp(n, vector<int>(4,-1));
        // return mem(points, n-1, 3, dp);
        
        return tab(points, n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
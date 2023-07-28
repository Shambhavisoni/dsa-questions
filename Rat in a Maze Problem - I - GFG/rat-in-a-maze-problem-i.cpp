//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper(vector<vector<int>> &m, int r, int c, int n, vector<string>& ans, string s){
        if(r==n-1 && c==n-1){
            ans.push_back(s);
            return;
        }
        
        int dr[]={-1, 0, 1, 0};
        int dc[]={0, 1, 0, -1};
        
        
        for(int i=0;i<4;i++){
            int newr=r+dr[i];
            int newc=c+dc[i];
            
            if(newr>=0 && newr<n && newc>=0 && newc<n && m[newr][newc]==1){
                if(dr[i]==-1 && dc[i]==0){
                    s.push_back('U');
                }
                if(dr[i]==0 && dc[i]==1){
                    s.push_back('R');
                }
                if(dr[i]==1 && dc[i]==0){
                    s.push_back('D');
                }
                if(dr[i]==0 && dc[i]==-1){
                    s.push_back('L');
                }
                m[newr][newc]=0;
                helper(m, newr, newc, n, ans, s);
                s.pop_back();
                m[newr][newc]=1;
            }
    }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> v;
        string s;
        
        if(m[0][0]==0 || m[n-1][n-1]==0){
            return {"-1"};
        }
        
        m[0][0]=0;
        helper(m, 0, 0, n, v, s);
        return v;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(vector<vector<char>>& grid, int r, int c, int n){
        for(int i=0;i<n;i++){
            if(grid[i][c]=='Q'){
                return false;
            }
            if(grid[r][i]=='Q'){
                return false;
            }
        }
        
        int i=r, j=c;
        while(i>=0 && j>=0){
            if(grid[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        i=r, j=c;
        while(i<n && j<n){
            if(grid[i][j]=='Q'){
                return false;
            }
            i++;
            j++;
        }
        i=r, j=c;
        while(j>=0 && i<n){
            if(grid[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }
        i=r, j=c;
        while(i>=0 && j<n){
            if(grid[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
        
    }
    void helper(vector<vector<char>>& grid, int col, int n, vector<int>& v, vector<vector<int>>& ans){
        if(col>=n){
            ans.push_back(v);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isSafe(grid, i, col, n)){
                grid[i][col]='Q';
                v.push_back(i+1);
                helper(grid, col+1, n, v, ans);
                grid[i][col]='.';
                v.pop_back();
            }
        }
        
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> v;
        vector<vector<int>> ans;
        vector<vector<char>> grid(n, vector<char>(n, '.'));
        helper(grid, 0, n, v, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
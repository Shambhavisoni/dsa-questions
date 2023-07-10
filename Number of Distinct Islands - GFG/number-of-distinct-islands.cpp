//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int base_i, 
               int base_j, int r,int c, vector<vector<int>>& v, int m, int n){
        queue<pair<int,int>> q;
        q.push({r,c});
        vis[r][c]=1;
        v.push_back({r-base_i, c-base_j});
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            
            q.pop();
            
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
    
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
    
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                     q.push({nrow,ncol});
                     vis[nrow][ncol]=1;
                     v.push_back({nrow-base_i, ncol-base_j});
                }
            }
        }
    }
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int base_i, 
               int base_j, int row,int col, vector<vector<int>>& v, int m, int n){
        vis[row][col]=1;
        v.push_back({row-base_i, col-base_j});
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(grid, vis, base_i, base_j, nrow, ncol, v, m, n);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<vector<int>>> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]){
                    vector<vector<int>> v;
                    // dfs(grid, vis, i, j, i, j, v, n, m);
                    bfs(grid, vis, i, j, i, j, v, n, m);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
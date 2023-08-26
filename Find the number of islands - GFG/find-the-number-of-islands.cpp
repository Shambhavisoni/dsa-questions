//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<int>>& vis, int n, int m){
        vis[r][c]=1;
        
        // int dr[]={-1, 0, 1, 0};
        // int dc[]={0, 1, 0, -1};
        
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nr=i+r;
                int nc=j+c;
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
                    dfs(grid, nr, nc, vis, n, m);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size(), c=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid, i, j, vis, n, m);
                    c++;
                }
            }
        }
        
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    queue<pair<int, pair<int,int>>> q;
	    q.push({0, {KnightPos[0],KnightPos[1]}});
	    vector<vector<int>> vis(N+1, vector<int>(N+1, 0));
	    
	    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
	    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	    
	    while(!q.empty()){
	        int steps=q.front().first;
	        int node_x=q.front().second.first;
	        int node_y=q.front().second.second;
	        
	        q.pop();
	        
	        if(node_x==TargetPos[0] && node_y==TargetPos[1]){
	            return steps;
	        }
	        
	        for(int i=0;i<8;i++){
	            int x=node_x+dx[i];
	            int y=node_y+dy[i];
	            
	            if(x>0 && x<=N && y>0 && y<=N && !vis[x][y]){
	                q.push({steps+1,{x, y}});
	                vis[x][y]=1;
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        
        
        // weight, node, parent
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        vector<int> vis(V, 0);
        int sum=0;
        
        q.push({0,{0,-1}});
        
        while(!q.empty()){
            int wt=q.top().first;
            int node=q.top().second.first;
            int parent=q.top().second.second;
            
            q.pop();
            
            if(!vis[node]){
                sum+=wt;
                vis[node]=1;
                
                for(auto it:adj[node]){
                    int adj_wt=it[1];
                    int adj_node=it[0];
                    q.push({adj_wt,{adj_node, node}});
                }
            }
            
            
        }
        return sum;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
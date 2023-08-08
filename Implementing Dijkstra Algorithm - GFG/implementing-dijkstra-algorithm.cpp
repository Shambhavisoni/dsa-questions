//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // distance, node
        queue<pair<int,int>> q;
        vector<int> dis(V, INT_MAX);
        
        dis[S]=0;
        q.push({0,S});
        
        while(!q.empty()){
            int wt=q.front().first;
            int node=q.front().second;
            
            q.pop();
            
            for(auto it: adj[node]){
                int adj_node=it[0];
                int adj_wt=it[1];
                
                if(dis[adj_node]>adj_wt+wt){
                    dis[adj_node]=adj_wt+wt;
                    q.push({dis[adj_node], adj_node});
                }
            }
        }
        
        return dis;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
	bool dfs(int u, int par, vector<int>adj[], vector<bool>&vis){
		vis[u] = true;    //marking the current vertex as visited.
		
		for(auto v: adj[u]){    //iterating on all the adjacent vertices.
			if(v == par) continue;
				
			//if current vertex is visited, we return true else we call the function recursively to detect the cycle.
			
			if(vis[v]) return true;
			if(dfs(v, u, adj, vis))
				return true;
		}
		return false;
	}
	
	
	bool isCycle(int V, vector<int> adj[]){
		vector<bool>visited(V, false);
		for(int i = 0; i < V; i++){
		    //if vertex is not visited, we call the function to detect cycle.
			if(!visited[i] && dfs(i, -1, adj, visited)) return true;

		}
		return false;
	}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
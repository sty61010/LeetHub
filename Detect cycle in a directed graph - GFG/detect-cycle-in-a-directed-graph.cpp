//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int cur, vector<int> adj[], vector<int> &vis){
        if(vis[cur] == 0) return false; // already visited
        if(vis[cur] == 1) return true; // cycle detected
        vis[cur] = 1; // visiting
        for(auto a: adj[cur]) if(dfs(a, adj, vis)) return true;
        vis[cur] = 0; // visited
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, -1);
        for(int i = 0; i < V; i++) if(dfs(i, adj, vis)) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
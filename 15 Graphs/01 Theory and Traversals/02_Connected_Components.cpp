class Solution {
private:
  void dfs(int node, vector<int> adj[], int vis[]) {
    vis[node] = 1;

    for (auto it : adj[node]) {
      if (!vis[it]) {
        dfs(it, adj, vis);
      }
    }
  }

public:
  int findNumberOfComponent(int V, vector<vector<int>> &edges) {
    int E = edges.size();
    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
    }

    int vis[V] = {0};
    int components = 0;

    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        vis[i] = 0;
        components++;
        dfs(i, adj, vis);
      }
    }

    return components;
  }
};

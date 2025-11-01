class Solution {
private:
  void dfsHelperFunc(int node, vector<int> adj[], int vis[], vector<int> &arr) {
    vis[node] = 1;
    arr.push_back(node);

    for (auto it : adj[node]) {
      if (!vis[it]) {
        dfsHelperFunc(it, adj, vis, arr);
      }
    }
  }

public:
  vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int start = 0;
    vector<int> ans;

    dfsHelperFunc(start, adj, vis, ans);

    return ans;
  }

  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> ans;

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      ans.push_back(node);

      for (auto it : adj[node]) {
        if (!vis[it]) {
          vis[it] = 1;
          q.push(it);
        }
      }
    }

    return ans;
  }
};

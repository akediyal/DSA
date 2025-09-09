class Solution {
private:
  bool isPossible(int node, int color, vector<int> &colors,
                  vector<vector<int>> &adj) {
    for (int i = 0; i < adj[node].size(); i++) {
      int adj_node = adj[node][i];

      if (colors[adj_node] == color) {
        return false;
      }
    }

    return true;
  }

  bool helperFunc(int node, vector<int> &colors, vector<vector<int>> &adj,
                  int m, int n) {
    if (node == n) {
      return true;
    }

    for (int color = 1; color <= m; color++) {
      if (isPossible(node, color, colors, adj)) {
        colors[node] = color;
        bool val = helperFunc(node + 1, colors, adj, m, n);

        if (val) {
          return true;
        }

        colors[node] = -1;
      }
    }

    return false;
  }

public:
  bool graphColoring(vector<vector<int>> &edges, int m, int n) {
    vector<vector<int>> adj(n);

    for (auto &i : edges) {
      int u = i[0];
      int v = i[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> colors(n, -1);

    bool ans = helperFunc(0, colors, adj, m, n);

    return ans;
  }
};

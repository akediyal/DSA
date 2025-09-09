class Solution {
private:
  bool isPossible(int node, int color, vector<int> &colors, vector<int> adj[]) {
    for (int adj_node : adj[node]) {
      if (colors[adj_node] == color) {
        return false;
      }
    }

    return true;
  }

  bool helperFunc(int node, vector<int> &colors, vector<int> adj[], int m,
                  int n) {
    if (n == node) {
      return true;
    }

    for (int color = 1; color <= m; color++) {
      if (isPossible(node, color, colors, adj)) {
        colors[node] = color;

        if (helperFunc(node + 1, colors, adj, m, n)) {
          return true;
        }

        colors[node] = 0;
      }
    }

    return false;
  }

public:
  bool graphColoring(vector<vector<int>> &edges, int m, int n) {
    vector<int> adj[n];

    for (int i = 0; i < edges.size(); i++) {
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> colors(n, 0);

    bool ans = helperFunc(0, colors, adj, m, n);

    return ans;
  }
};

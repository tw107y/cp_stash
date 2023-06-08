// bridges are things you cannot disconnect. Disconnecting a bridge will disconnect the graph
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5; // number of vertices in graph
vector<int> edges[N]; // each vertex has a list of connected vertices
int T = 0;
int low[N]; // WHAT DOES THIS DO
int preorder[N]; // WHAT DOES THIS DO
set<pair<int, int>> bridges;

void dfs(int u, int from = -1) {
  low[u] = preorder[u] = T++;
  for (int v : edges[u]) {
    // ignore the edge to our parent in the dfs
    if (v == from) continue;
    // update the lowest value in the preorder sequence that we can reach
    if (preorder[v] != -1) low[u] = min(low[u], preorder[v]);
    else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      // if we haven't visited v before, check to see if we have a bridge
      if (low[v] == preorder[v]) bridges.insert(make_pair(min(u, v), max(u, v)));
    }
  }
}

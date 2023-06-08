#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5; // number of vertices in graph
vector<int> edges[N]; // each vertex has a list of connected vertices

void add(int u, int v) {
    edges[u].push_back(v);
    // Warning: If the graph has self-loops, you need to check this.
    if (v != u) {
        edges[v].push_back(u);
    }
}

/*
 * bfs
 */
// dist from start. -1 if unreachable.
int dist[N];
// previous node on a shortest path to the start
// Useful for reconstructing shortest paths
int prv[N];
void bfs(int start) {
    fill(dist, dist+N, -1);
    dist[start] = 0;
    prv[start] = -1;

    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        for (int nxt : edges[c]) {
            // Push if we have not seen it already.
            if (dist[nxt] == -1) {
                dist[nxt] = dist[c] + 1;
                prv[nxt] = c;
                q.push(nxt);
            }
        }
    }
    // to print the path 
    // vector<int> path;
    // int x = final point
    // path.push_back(x);
    // while (prv[x]!=-1) {
    //      x = prv[x];
    //      path.push_back(x);
    // }
    // for (int i = path.size()-1; i >= 0; i--) cout << path[i] << " "; cout << "\n";
}

///////////////////////////////////////dfs////////////////////////////////////////
bool seen[N];
void dfs(int u) {
  if (seen[u]) return;
  seen[u] = true;
  for (int v : edges[u]) dfs(v);
}

// cycle detection
bool seen[N];
bool active[N];
// the vertices that are still marked active when this returns are the ones in the cycle we detected
bool has_cycle(int u) {
  if (seen[u]) return false;
  seen[u] = true;
  active[u] = true;
  for (int v : edges[u]) {
    if (active[v] || has_cycle(v)) return true;
  }
  active[u] = false;
  return false;
}

/*
 * tree representation
 */

const int N = 1e6 + 5;

// We need the list of edges to construct our representation
// But we don't use it afterwards.
vector<int> edges[N];

int par[N]; // Parent. -1 for the root.
vector<int> children[N]; // Your children in the tree.
int size[N]; // As an example: size of each subtree.

void constructTree(int c, int cPar = -1) {
    par[c] = cPar;
    size[c] = 1;
    for (int nxt : edges[c]) {
        if (nxt == par[c]) continue;
        constructTree(nxt, c);
        children[c].push_back(nxt);
        size[c] += size[nxt];
    }
}
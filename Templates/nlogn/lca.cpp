#include<bits/stdc++.h>
using namespace std;
/*
 * lca 1
 */

// parent[u][k] is the 2^k-th parent of u
int n;
const int N = 100010;
int parent[N][19];
void preprocess() {
  for (int i = 0; i < n; i++) {
    // assume parent[i][0] (the parent of i) is already filled in
    for (int j = 1; (1<<j) < n; j++) {
      parent[i][j] = -1;
    }
  }

  // fill in the parent for each power of two up to n
  for (int j = 1; (1<<j) < n; j++) {
    for (int i = 0; i < n; i++) {
      if (parent[i][j-1] != -1) {
        // the 2^j-th parent is the 2^(j-1)-th parent of the 2^(j-1)-th parent
        parent[i][j] = parent[parent[i][j-1]][j-1];
      }
    }
  }
  // Add code for log
}


/*
 * lca 2
 */
int depth[N];
int lca (int u, int v) {
  // make sure u is deeper than v
  if (depth[u] < depth[v]) swap(u,v);
  
  // log[i] holds the largest k such that 2^k <= i
  for (int i = log[depth[u]]; i >= 0; i--) {
    // repeatedly raise u by the largest possible power of two until it is the same depth as v
    if (depth[u] - (1<<i) >= depth[v]) u = parent[u][i]; 
  }

  if (u == v) return u;

  for (int i = log[depth[u]]; i >= 0; i--)
    if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
      // raise u and v as much as possible without having them coincide
      // this is important because we're looking for the lowest common ancestor, not just any
      u = parent[u][i];
      v = parent[v][i];
    }

  // u and v are now distinct but have the same parent, and that parent is the LCA
  return parent[u][0];
}
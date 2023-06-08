// Dinitz Algorithm for Max Flow
// Needs to be revised. 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int V = 1000; // 1.5*amount of vertices
const int E = 50000; // more than 2*amount of edges
// If doesn't work just try to add more

int start[V];
int succ[E], cap[E], to[E];
int edge_counter;

void add_edge(int u, int v, int c) {
  cap[edge_counter] = c, to[edge_counter] = v;
  succ[edge_counter] = start[u];
  start[u] = edge_counter;
  ++edge_counter;
}

void init(void) {
  edge_counter = 0;
  fill(start, start + V, -1);
}

void add_edges(int u, int v, int c) {
  add_edge(u, v, c); // original edge
  add_edge(v, u, 0); // residual edge
}

int inv(int e) { return e ^ 1; }

int s, t;
int lvl[V];
int nextchld[V];

bool bfs() {
  fill(lvl, lvl+V, -1);
  queue<int> q;
  q.push(s);
  lvl[s] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    nextchld[u] = start[u];
    for (int e = start[u]; ~e; e = succ[e])
      if (cap[e] > 0) {
        int nxt = to[e];
        if (lvl[nxt] != -1) 
          continue;
        lvl[nxt] = lvl[u] + 1;
        q.push(nxt);
      }
  }
  return lvl[t] != -1;
}

int seen[V];
int ans = 0;

// altered From jack copland on ed
void dfs(int a) {
  if (seen[a]) return;
  seen[a] = true;
  ans++;
  for (int e = start[a]; ~e; e = succ[e]) {   // iterate over all edges
    // t is whether it's from the sink or not, false means from source
    if (cap[e] >= 1) {
      dfs(to[e]);
    }
  }
}

int aug(int u, int cflow) {
  if (u == t) return cflow; 
  for (int &i = nextchld[u]; i >= 0; i = succ[i]) {
    if (cap[i] > 0) {
      int nxt = to[i];
      if (lvl[nxt] != lvl[u] + 1) continue;
      int rf = aug(nxt, min(cflow, cap[i]));
      if (rf > 0) {
        cap[i] -= rf;
        cap[i^1] += rf;
        return rf;
      }
    }
  }
  lvl[u]=-1;
  return 0;
}

const long long INF = 1000*1000*1000+7;

long long max_flow() {
  long long tot = 0;
  while (bfs()) {
    
    for (long long x = aug(s,INF); x; x = aug(s,INF))
      tot += x;
  }
    
  return tot;
}

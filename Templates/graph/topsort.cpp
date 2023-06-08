#include<bits/stdc++.h>
using namespace std;
/*
 * topological sort
 */

// if the edges are in ASCENDING order of node number,
// this produces the lexicographically GREATEST ordering
const int N = 100010;
bool seen[N];
vector<int> edges[N];
int n;

void dfs(int u, vector<int>& postorder) {
  if (seen[u]) return;
  seen[u] = true;
  for (int v : edges[u]) dfs(v, postorder);
  postorder.push_back(u);
} 

vector<int> topsort() {
  vector<int> res;
  for (int i = 0; i < n; i++) dfs(i, res);
  reverse(res.begin(), res.end()); // #include <algorithm>
  return res;
}



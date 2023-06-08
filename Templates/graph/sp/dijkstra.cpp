#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edge; // (distance, vertex)
const int N = 100100;
vector<edge> edges[N];
int dist[N];
bool seen[N];
priority_queue<edge, vector<edge>, greater<edge>> pq;

void dijkstra (int s) {
  pq.push(edge(0, s)); // distance to s itself is zero
  while (!pq.empty()) {
    // choose (d, v) so that d is minimal
    // i.e. the closest unvisited vertex
    edge cur = pq.top();
    pq.pop();
    int v = cur.second, d = cur.first;
    if (seen[v]) continue;

    dist[v] = d;
    seen[v] = true;

    // relax all edges from v
    for (edge nxt : edges[v]) {
      int u = nxt.second, weight = nxt.first;
      if (!seen[u])
        pq.push(edge(d + weight, u));
    }
  }
}
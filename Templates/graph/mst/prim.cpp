/*
 * prim
 */
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int N = 100010;

vector<ii> edges[N]; // pairs of (weight, v)
bool in_tree[N];
// use greater as the comparator instead of the default less so the priority queue is a min-heap instead of a max-heap
// the vector<int> parameter is the container the queue is stored in, an implementation detail you will not need to change
priority_queue<ii, vector<ii>, greater<ii>> pq;

int mst() {
  int total_weight = 0;
  in_tree[0] = true; // (2)
  for (auto edge : edges[0]) pq.emplace(edge.first, edge.second);
  while (!pq.empty()) { // (3)
    auto edge = pq.top(); pq.pop();
    // if this edge goes to somewhere already in the tree, it's useless (we've already done something better)
    if (in_tree[edge.second]) continue;
    in_tree[edge.second] = true;
    total_weight += edge.first;
    for (auto edge : edges[edge.second]) pq.emplace(edge.first, edge.second); // (4)
  }
  return total_weight;
}


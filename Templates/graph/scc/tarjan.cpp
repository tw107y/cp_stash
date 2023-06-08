#include<bits/stdc++.h>
using namespace std;
/*
 * tarjan 1
 */

const int MAX_VERTICES = 100010;

int n;

// we will number the vertices in the order we see them in the DFS
int dfs_index[MAX_VERTICES];
// for each vertex, store the smallest number of any vertex we see
// in its DFS subtree
int lowlink[MAX_VERTICES];

// explicit stack
stack<int> s; // #include <stack>
bool in_stack[MAX_VERTICES];

// arbitrarily number the SCCs and remember which one things are in
int scc_counter;
int which_scc[MAX_VERTICES];

vector<int> edges[MAX_VERTICES];

void connect(int v) {
  // a static variable doesn't get reset between function calls
  static int i = 1;
  // set the number for this vertex
  // the smallest numbered thing it can see so far is itself
  lowlink[v] = dfs_index[v] = i++;
  s.push(v);
  in_stack[v] = true;

  // continued


/*
 * tarjan 2
 */

  for (auto w : edges[v]) { // for each edge v -> w
    if (!dfs_index[w]) {  // w hasn't been visited yet
      connect(w);
      // if w can see something, v can too
      lowlink[v] = min(lowlink[v], lowlink[w]);
    }
    else if (in_stack[w]) {
      // w is already in the stack, but we can see it
      // this means v and w are in the same SCC
      lowlink[v] = min(lowlink[v], dfs_index[w]);
    }
  }
  // v is the root of an SCC
  if (lowlink[v] == dfs_index[v]) {
    ++scc_counter;
    int w;
    do {
      w = s.top(); s.pop();
      in_stack[w] = false;
      which_scc[w] = scc_counter;
    } while (w != v);
  }
}

// call connect for each vertex once
int main() {
    for (int v = 0; v < n; ++v) if (!dfs_index[v]) connect(v);
}




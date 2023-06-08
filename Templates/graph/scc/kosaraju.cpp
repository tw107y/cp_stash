#include<bits/stdc++.h>
using namespace std;
/*
 * kosaraju
 */
int p = 0;
const int N = 100010;
bool seen[N];
vector<int> edges[N];
int postorder[N];
int scc[N];
bool seen_r[N];
vector<int> edges_r[N];
int n;

void dfs(int u) {
	if (seen[u])
		return;
	seen[u] = true;
	for (int v : edges[u])
		dfs(v);
	postorder[p++] = u;
}

void dfs_r(int u, int mark) {
	if (seen_r[u])
		return;
	seen_r[u] = true;
	scc[u] = mark;
	for (int v : edges_r[u])
		dfs_r(v, mark);
} 

int compute_sccs() {
	int sccs = 0;
	for (int i = 1; i <= n; i++)
		if (!seen[i])
			dfs(i);
	for (int i = p - 1; i >= 0; i--) {
		int u = postorder[i];
		if (!seen_r[u]) // ignore visited vertices
			dfs_r(u, sccs++);
	}
	return sccs;
}
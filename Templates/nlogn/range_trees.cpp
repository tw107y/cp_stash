// the number of additional nodes created can be as high as the next power of two up from N (2^17 = 131,072)
// use struct to save memory
// 1<<19 for 3*10^5 which is standard // TEST
// Left inclusive right exclusive
// This implementation is sum range tree
#include<bits/stdc++.h>
using namespace std;
const int N = 100100;
int tree[1<<18];
int n; // actual length of underlying array

int query(int qL, int qR, int i = 1, int cL = 0, int cR = n) {
  if (cL == qL && cR == qR) return tree[i];
  int mid = (cL + cR) / 2;
  int ans = 0;
  if (qL < mid) ans += query(qL, min(qR, mid), i * 2, cL, mid);
  if (qR > mid) ans += query(max(qL, mid), qR, i * 2 + 1, mid, cR);
  return ans;
}

void update(int p, int v, int i = 1, int cL = 0, int cR = n) {
  if (cR - cL == 1) {
    tree[i] = v;
    return;
  }
  int mid = (cL + cR) / 2;
  if (p < mid) update(p, v, i * 2, cL, mid);
  else update(p, v, i * 2 + 1, mid, cR);
  tree[i] = tree[i*2] + tree[i*2+1];
}


/*
 * range tree on trees // TEST IF THIS WORKS
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 100100;
// Suppose you already have your tree set up.
vector<int> children[N];
// A node is responsible for the range [startRange[v], endRange[v])
int indexInRangeTree[N], startRange[N], endRange[N];
int totId;
// A range tree that supports point update, range sum queries.
long long rangeTree[1<<18];

void compute_tree_ranges(int c) {
    indexInRangeTree[c] = startRange[c] = totId++;
    for (int nxt : children[c]) {
        compute_tree_ranges(nxt);
    }
    endRange[c] = totId;
}

void update_node(int id, int v) {
    update(indexInRangeTree[id], v);
}

int query_subtree(int id) {
    return query(startRange[id], endRange[id]);
}

/*
 * range updates point queries
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 100100;
long long lazyadd[1<<18];

int n;

// The root node is responsible for [0, n). Update range [uL, uR)
// Compare to range query code.
void update(int uL, int uR, int v, int i = 1, int cL = 0, int cR = n) {
  if (uL == cL && uR == cR) {
    lazyadd[i] += v;
    return;
  }
  int mid = (cL + cR) / 2;
  if (uL < mid) update(uL, min(uR, mid), v, i * 2, cL, mid);
  if (uR > mid) update(max(uL, mid), uR, v, i * 2 + 1, mid, cR);
}

long long query(int p, int i = 1, int cL = 0, int cR = n) {
  if (cR - cL == 1) {
    return lazyadd[i];
  }
  int mid = (cL + cR) / 2;
  long long ans = lazyadd[i];
  if (p < mid) ans += query(p, i * 2, cL, mid);
  else ans += query(p, i * 2 + 1, mid, cR);
  return ans;
}


/*
 * range updates range queries 1
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 100100;
long long lazyadd[1<<18], sum[1<<18];

// Procedure for recalculating a node's sum from its lazy and children.
void recalculate(int id, long long l, long long r) {
  sum[id] = lazyadd[id] * (r - l);
  if (r - l != 1) {
    sum[id] += sum[id * 2];
    sum[id] += sum[id * 2 + 1];
  }
}

void update_lazy(int id, long long v, long long l, long long r) {
  lazyadd[id] += v;
  recalculate(id, l, r);
}

// Preorder procedure for propagation. Do NOT call it on leaves.
void propagate(int id, long long l, long long r) {
  long long mid = (l + r) / 2;
  update_lazy(id * 2, lazyadd[id], l, mid);
  update_lazy(id * 2 + 1, lazyadd[id], mid, r);
  lazyadd[id] = 0;
}
/*
 * range updates range queries 2
 */

int n;

// The root node is responsible for [0, n). Update range [uL, uR)
void update(int uL, int uR, int v, int i = 1, int cL = 0, int cR = n) {
  if (uL == cL && uR == cR) {
    update_lazy(i, v, cL, cR);
    return;
  }
  propagate(i, cL, cR);
  int mid = (cL + cR) / 2;
  if (uL < mid) update(uL, min(uR, mid), v, i * 2, cL, mid);
  if (uR > mid) update(max(uL, mid), uR, v, i * 2 + 1, mid, cR);
  recalculate(i, cL, cR);
}

long long query(int qL, int qR, int i = 1, int cL = 0, int cR = n) {
  if (qL == cL && qR == cR) {
    return sum[i];
  }
  propagate(i, cL, cR);
  int mid = (cL + cR) / 2;
  long long ans = 0;
  if (qL < mid) ans += query(qL, min(qR, mid), i * 2, cL, mid);
  if (qR > mid) ans += query(max(qL, mid), qR, i * 2 + 1, mid, cR);
  return ans;
}
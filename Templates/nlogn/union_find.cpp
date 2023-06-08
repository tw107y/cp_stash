/*
 * union find size heuristic only
 */
const int N = 100010;
int parent[N];
int subtree_size[N];  

void init(int n) {
  for (int i = 0; i < n; i++) {
    parent[i] = i;
    subtree_size[i] = 1;
  }
}

/*
 * union find path compression
 */
int root(int x) {
  // only roots are their own parents
  // otherwise apply path compression
  return parent[x] == x ? x : parent[x] = root(parent[x]);
}

void join(int x, int y) {
  // join roots
  x = root(x); y = root(y);
  // test whether already connected
  if (x == y)
    return;
  // size heuristic
  // hang smaller subtree under root of larger subtree
  if (subtree_size[x] < subtree_size[y]) {
    parent[x] = y;
    subtree_size[y] += subtree_size[x];
  } else {
    parent[y] = x;
    subtree_size[x] += subtree_size[y];
  }
}


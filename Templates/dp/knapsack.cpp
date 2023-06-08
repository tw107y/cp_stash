#include<bits/stdc++.h>
using namespace std;
/*
 * knapsack top down
 */
int n;
const int N = 100010;
const int S = 19;
// 2D cache, should be initialised to -1 because 0 is a valid answer
int cache[N+1][S+1];
int s[N]; // weight // I think
int v[N]; // value // I think

int f(int i, int r) {
  // base cases
  if (r < 0) return -2e9;
  if (i > n || r == 0) return 0;
  // check cache
  if (cache[i][r] != -1) return cache[i][r];
  // calculate answer
  return cache[i][r] = max(f(i + 1, r - s[i]) + v[i], f(i + 1, r));
}


/*
 * knapsack bottom up
 */

int dp[N+2][S+1];

for (int i = N; i >= 1; --i) {
  // everything from larger i will be available here
  for (int r = 0; r <= S; ++r) {
    // we have declared the array larger, so if i == N, dp[i+1][...] will be zero.
    int m = dp[i+1][r];
    // bounds check so we don't go to a negative array index
    if (r - s[i] >= 0) m = max(m, dp[i+1][r-s[i]] + v[i]);
    dp[i][r] = m;
  }
}
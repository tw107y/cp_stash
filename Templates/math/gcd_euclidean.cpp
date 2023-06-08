#include <bits/stdc++.h>
using namespace std;

/*
 * gcd
 */

int gcd_(int a, int b) {
  return b ? gcd_(b, a % b) : a;
}


/*
 * gcd for extended euclidean algorithm. ax + by = 1
 */

int gcd_e(int a, int b, int& x, int& y) { // x stores ?, y stores ?.
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  int x1, y1;
  int d = gcd_e(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
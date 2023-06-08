/*
 * primes // FOR ONE NUMBER. NOT SIEVE. SIEVE IS FOR EVERY NUMBER UP TILL 1e7.
 */

#include <bits/stdc++.h>
using namespace std;

bool isprime(int x) {
  if (x < 2) return false;

  for (int f = 2; f*f <= x; f++) {
    if (x % f == 0) return false;
  }
  return true;
}

// Returns prime factors in increasing order with right multiplicity.
vector<int> primefactorize(int x) {
  vector<int> factors;
  for (int f = 2; f*f <= x; f++) {
    while (x % f == 0) {
      factors.push_back(f);
      x /= f;
    }
  }
  if (x != 1) factors.push_back(x);
  return factors;
}
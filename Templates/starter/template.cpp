#include <bits/stdc++.h>

// if the above doesn't compile,
/*
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include <iterator>
#include <utility>
#include <numeric>
#include <cstddef>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <random>
#include <chrono>
#include <math.h>
#include <time.h>
#include <string>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
#include <set>
#include <map>
*/
// Generally, only use stuff that is required. But if lazy use all.

using namespace std;

#define PI 3.1415926535897932384626433832795
#define M 1000000007
#define For(x, n) for(int x = 0; x < n; x++)
typedef long long ll;

void yes() {
    cout << "YES\n";
}

void no() {
    cout << "NO\n";
}

ll MOD(ll a) {
    ll b = a % M;
    return b >= 0 ? b : b + M;
}

ll pw(ll a, ll b) {
    if (b == 0) return 1;
    ll t = pw(a, b/2);
    t = MOD(t*t);
    if (b%2==1) t = MOD(t*a);
    return t;
}

// solve function which handles each individual query.
void solve() {

    cout << "Hello World.\n";
}

int main() {

    // Increases the speed of the coded by around 1.5 times if there are a lot of inputs. e.g. 10^5.
    // However, this is not necessary if we use scanf/printf, and should not be used without 
    // understanding it outside of cp. 
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while (t) {
        solve();
        --t;
    }
}

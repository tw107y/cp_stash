#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll M = 1000000007ll;
ll pw(ll a, ll b) {
    if (b == 0) return 1;
    ll t = pw(a,b/2);
    t = (t*t) % M;
    if (b%2==1) t =(t*a)%M;
    return t;
}

ll inv(ll a) {
    return pw(a, M-2);
}

const int N = 100010;
ll fact[N];

void precomp() {
    fact[0] = 1;
    for (ll i = 1; i < N; i++) {
        fact[i] = (fact[i-1] * i ) % M;
    }
}

ll ncr(ll n, ll r) {
    return ((fact[n] * inv(fact[r]))%M * inv(fact[n-r]))%M;
}
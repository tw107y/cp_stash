// O(n) String hashing and then O(1) comparison
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

struct H {
	typedef uint64_t ull;
	ull x; H(ull x=0) : x(x) {}
#define OP(O,A,B) H operator O(H o) { ull r = x; asm \
	(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); return r; }
	OP(+,,"d"(o.x)) OP(*,"mul %1\n", "r"(o.x) : "rdx")
	H operator-(H o) { return *this + ~o.x; }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};


/*
Usage: 
    string s = "popppp";

    HashInterval hi(s);
    
    hi.hashInterval(0,1) == hi.hashInterval(3,4) // outputs true            p = p
    hi.hashInterval(0,2) == hi.hashInterval(3,5) // outputs false           po != pp
    hi.hashInterval(0,sz(s)) == hi.hashInterval(0,sz(s)) // outputs true    string = itself
*/

int main() {
    string s1 = "abcabcc";
    string s2 = "popppp";

    HashInterval hi1(s1);
    HashInterval hi2(s2);
    int i = 0;
    if (hi2.hashInterval(0,2) == hi2.hashInterval(3,4)) {
        i = 1;
    }
    cout << i << "\n";
}

// Binary search + upper lower bound
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Find the smallest X such that f(X) is true; E.g. if x works then all X >= x works
int binarysearch(function<bool(int)> f) {
    int lo = 0;
    int hi = 100000;
    int bestSoFar = -1; // this will be returned if no value from 0-100000 works
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (f(mid)) {
            bestSoFar = mid;
            hi = mid - 1; // swap this line and this line+2 if want biggest X such that f(X) is true
        } else {
            lo = mid + 1;
        }
    }
    return bestSoFar;
}

double fpbs(function<bool(int)> cando) { // floating point binary search
    double lo = 0, hi = 1e10;
    for (int it = 0; it < 70; it++) { // iteration depends on precision.
        double mid = (lo + hi) / 2;
        if (cando(mid)) hi = mid;
        else lo = mid;
    }
    return lo; // hi and lo will be approximately the same at this point.
}


int main() {
    // set.upper_bound(x) returns the iterator for the element that goes right after x.
    // set.lower_bound(x) returns the iterator for the element that is either right before x or x itself.
    // use *set.lower_bound(x) to dereference it
    // for map use map.lower_bound(x)->first, map.lower_bound(x)->second // NEED TO CHECK THIS 
}
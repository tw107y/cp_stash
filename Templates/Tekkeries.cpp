// Let's say sum stores an array of values and you want to sort it while keeping track of the index of the original array.
// This sorts it from smallest to biggest.
sum[n]
vector<int> p(n);
iota(p.begin(), p.end(), 0); // p becomes [0, 1, 2, 3, ..., n-1]
sort(p.begin(), p.end(), [&](int i, int j) {
    return sum[i] < sum[j];
});

/*
Usage
    Initially, sum = [14, 5, 9, 8, 7, 7, 6], p = [0, 1, 2, 3, 4, 5, 6]
    After sorting, sum = [5, 6, 7, 7, 8, 9, 14], p = [1, 6, 4, 5, 3, 2, 0]
    Edit: This is not necessarily correct since sort() in cpp is not stable. 
    If we want stability we should use stable_sort() instead, but it will be slower than sort().
*/

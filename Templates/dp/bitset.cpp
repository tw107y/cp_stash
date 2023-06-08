/*
 * bitsets
 */
int n;

void bitset() {
    // for all sets
    for (int i = 0; i < (1<<n); i++) {
        // for all subsets of that set, in descending order
        for (int j = i; j; j = (j-1) & i) {
            // do something with the subset
        }
    }
} 


// 10010010 i

// 10010010 j
// 10010000
// 10000010
// 10000000
// 00010010
// 00010000
// 00000010

void bitset_v2() {
    // for all sets
    for (int i = 0; i < (1<<n); i++) {
        // match each index in a set
        for (int j = 0; j < n; j++) {
            if (i&j) {
                // do something with this index for this set
            }
        }
    }
} 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
            tree_order_statistics_node_update> ordered_set;
typedef tree<int, char, less<int>, rb_tree_tag, 
            tree_order_statistics_node_update> ordered_map;

ordered_map mymap;
ordered_set myset;
int main() {
    myset.insert(2);
    myset.insert(4);
    myset.insert(1);
    printf("%d\n", *(myset.find_by_order(0))); // 1
    printf("%d\n", (int)myset.order_of_key(3)); // 2
    printf("%d\n", (int)myset.order_of_key(4)); // 2
    printf("%d\n", (int)myset.size()); // 3

    mymap[2] = 'a';
    mymap[4] = 'b';
    mymap[1] = 'c';
    pair<int, char> pic = *mymap.find_by_order(0);
    printf("%d %c\n", pic.first, pic.second); // 1 c
    printf("%d\n", (int)mymap.order_of_key(3)); // 2
    printf("%d\n", (int)mymap.order_of_key(4)); // 2
    printf("%d\n", (int)mymap.size()); // 3
}
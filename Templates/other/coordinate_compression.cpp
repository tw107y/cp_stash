#include <bits/stdc++.h>
using namespace std;
map<int, int> coordMap;

void compress(vector<int>& values) {
    for (int v : values) {
        coordMap[v] = 0;
    }
    int cId = 0;
    for (auto it = coordMap.begin(); it != coordMap.end(); ++it) {
        it->second = cId++;
    }
    for (int &v : values) { // I still dont know what this code does lol
        v = coordMap[v];
    }
}
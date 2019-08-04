#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

long dfs(size_t i, vector<int>v) {
    if (i == 2) return v[0] + v[1];
    vector<int> next(v);
    next[0] += next[1];
    next[2] += next[1];
    next.erase(next.begin()+1);
    long a = dfs(i-1, next);
    next = vector<int>(v);
    next[i-3] += next[i-2];
    next[i-1] += next[i-2];
    next.erase(next.begin() + i-2);
    long b = dfs(i - 1, next);
    return min(a, b);
}

int main() {
    size_t n;
    cin >> n;
    vector<int> a(n);
    for (auto &ai:a) cin >> ai;
    cout << dfs(n, a) << '\n';
    return 0;
}

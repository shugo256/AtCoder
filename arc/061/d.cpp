#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
using P = pair<int, int>;

int main() {
    long h, w, n;
    cin >> h >> w >> n;
    map<P, long> blacks;
    set<P> cand;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        blacks[{a, b}] = 1;
        for (int x=-1; x<2; x++)
            for (int y=-1; y<2; y++)
                cand.insert({a+x, b+y});
    }
    long cnt[10] = {0};
    cnt[0] = (h-2) * (w-2);
    for (auto c:cand) {
        int temp = 0;
        if (c.first < 2 || c.first > h-1 || c.second < 2 || c.second > w-1) continue;
        for (int x=-1; x<2; x++)
            for (int y=-1; y<2; y++)
                temp += blacks[{c.first+x, c.second+y}];
        cnt[temp]++;
        cnt[0]--;
    }
    for (auto ci:cnt)
        cout << ci << '\n';
    return 0;
}
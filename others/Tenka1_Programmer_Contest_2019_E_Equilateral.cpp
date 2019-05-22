#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> P;

//未解決や


int manhattan(P l, P r) {
    return abs(l.first - r.first) + abs(l.second - r.second);
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<P> coins;
    int sum=0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            char c;
            cin >> c;
            if (c != '#') continue;
            coins.push_back({i, j});
        }
    }
    int cnt = 0;
    for (auto i = coins.begin(); i < coins.end(); i++) {
        for (auto j = i; j < coins.end(); j++) {
            for (auto k = j; k < coins.end(); k++) {
                int manij = manhattan(*i, *j),
                    manjk = manhattan(*j, *k),
                    manki = manhattan(*k, *i);
                if (manij == manjk && manjk == manki) cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
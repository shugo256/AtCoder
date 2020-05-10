#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    int a[n]; for (auto &ai:a) {
        cin >> ai;
        ai--;
    }
    int city = 0;
    ll visited[n]; fill(visited, visited+n, -1);
    vector<int> loop;
    ll offset;
    for (int i=0; i<n; i++) {
        loop.push_back(city + 1);
        visited[city] = i;
        city = a[city];
        if (visited[city] >= 0) {
            offset = visited[city];
        }
    }
    if (k < offset) {
        cout << loop[k] << '\n';
        return 0;
    }
    int looplen = loop.size() - offset;
    cout << loop[(k - offset) % looplen + offset]  << '\n';
    return 0;
}
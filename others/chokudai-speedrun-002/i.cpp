#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

using P = pair<long, long>;

int main() {
    int n;
    cin >> n;
    P foods[n], best={1, 1};
    int besti = -1;
    for (int i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        foods[i] = {a, b};
        if ((best.first-1) / b + 1 <= (a-1) / best.second + 1) {
            best = {a, b};
            besti = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == besti) continue;
        if ((best.first-1) / foods[i].second + 1 <= (foods[i].first-1) / best.second + 1) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << besti + 1 << '\n';
    return 0;
}

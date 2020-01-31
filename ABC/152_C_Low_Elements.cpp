#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    int mi = n, cnt = 0;
    for (int i=0, pi; i<n; i++) {
        cin >> pi;
        if (mi >= pi) cnt++;
        mi = min(mi, pi);
    }

    cout << cnt << '\n';
    return 0;
}
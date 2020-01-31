#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt=0;
    bool used[100010] = {0};
    for (int i=0; i<n; i++) {
        int ai; cin >> ai;
        if (used[ai]) cnt++;
        else used[ai] = true;
    }
    cout << max(1, n - (cnt + cnt%2)) << '\n';
    return 0;
}
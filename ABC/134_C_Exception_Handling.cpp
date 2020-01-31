#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], as[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        as[i] = a[i];
    }
    sort(as, as+n, greater<int>());
    for (auto ai:a) {
        if (ai == as[0]) cout << as[1] << endl;
        else             cout << as[0] << endl;
    }
    return 0;
}
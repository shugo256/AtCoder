#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int d, t, s;
    cin >> d >> t >>s;
    cout << (t * s >= d ? "Yes" : "No") << '\n';
    return 0;
}
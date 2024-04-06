#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

struct work {long a, b;};

int main() {
    int n;
    cin >> n;
    work w[n];
    for (auto &wi:w) cin >> wi.a >> wi.b;
    sort(w, w+n, [](work l, work r) {
        return l.b < r.b || (l.b == r.b && l.a > r.a);
    });
    long t = 0;
    for (auto wi:w) {
        t += wi.a;
        if (t > wi.b) {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';
    return 0;
}

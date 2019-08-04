#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool prev = false;
    int cnt=0;
    for (int i=1; i<=n; i++) {
        int p;
        cin >> p;
        if (p == i) {
            if (!prev) cnt++;
            prev = !prev;
        } else
            prev = false;
    }
    cout << cnt << '\n';
    return 0;
}
#include <iostream>
#include <algorithm>

#define MAX 100000

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bool cnt[n]; fill(cnt, cnt+n, 0);
    for (int i=0; i<2*m; i++) {
        int a;
        cin >> a; a--;
        cnt[a] = !cnt[a];
    }
    for (auto o:cnt) {
        if (o) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}
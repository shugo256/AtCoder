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
    for (int i=0, h, w; i<n; i++) {
        cin >> h >> w;
        for (int j=0; j<h; j++) {
            for (int k=0; k<w; k++) {
                cout << (char)('A' + ((min(j, 3) + min(k, 3)) % 3));
            }
            cout << '\n';
        }
    }
    return 0;
}
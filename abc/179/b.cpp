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
    int cnt = 0;
    for (int i=0, d1, d2; i<n; i++) {
        cin >> d1 >> d2;
        if (d1 == d2) {
            cnt++;
        } else {
            cnt = 0;
        }
        if (cnt == 3) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    return 0;
}
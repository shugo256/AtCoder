#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    int zero=0;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a == 0) zero++;
        else m[a]++;
    }
    if (m.size() == 3 && n % 3 == 0) {
        bool yes = true;
        int a = 0;
        for (auto &mi:m) {

            if (mi.second != n/3) {
                yes = false;
                break;
            }
            a = a xor mi.first;
        }
        if (yes && a == 0) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    if ((m.size() == 1 && (zero == n / 2 && n % 2 == 0) || (zero == n / 3 && n % 3 == 0)) || m.size() == 0) {
        cout << "Yes" << '\n';
        return 0;
    }
    cout << "No" << '\n';
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int k, a, b;
    cin >> k >> a >> b;
    for (int i=a; i<=b; i++) {
        if (i % k == 0) {
            cout << "OK" << '\n';
            return 0;
        }
    }
    cout << "NG" << '\n';
    return 0;
}
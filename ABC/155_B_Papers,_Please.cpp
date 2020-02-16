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
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        if (ai%2 == 0 && ai%3 && ai%5) {
            cout << "DENIED" << '\n';
            return 0;
        }
    }
    cout << "APPROVED" << '\n';
    return 0;
}
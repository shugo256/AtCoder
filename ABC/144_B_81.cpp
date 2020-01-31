#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    bool calcable[101];
    fill(calcable, calcable+101, false);
    for (int i=1; i<10; i++) {
        for (int j=i; j<10; j++) {
            calcable[i * j] = true;
        }
    }
    int n;
    cin >> n;
    cout << (calcable[n] ? "Yes" : "No") << '\n';
    return 0;
}
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    long best = 0;
    for (int i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        best += max(a , b);
    }
    cout << best << '\n';
    return 0;
}

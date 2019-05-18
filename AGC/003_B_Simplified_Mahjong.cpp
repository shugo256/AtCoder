#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int r = 0;
    long pairs = 0;
    for (int i=0; i<n; i++) {
        long a;
        cin >> a;
        pairs += (a + r) / 2;
        if (a > 0) r = (a + r) % 2;
        else r = 0;
    }
    cout << pairs << '\n';
    return 0;
}
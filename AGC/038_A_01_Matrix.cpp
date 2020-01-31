#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++)
            cout << ((i < b) xor (j < a));
        cout << '\n';
    }
    return 0;
}
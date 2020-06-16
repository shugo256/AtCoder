#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    for (int i=0, zi; i<5; i++) {
        cin >> zi;
        if (zi == 0) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    return 0;
}
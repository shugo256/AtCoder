#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        cout << a % b << '\n';
    }
    return 0;
}
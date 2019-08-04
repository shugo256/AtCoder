#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    long prev=0, h;
    for (int i=0; i<n; i++) {
        cin >> h;
        if (h < prev) {
            cout << "No\n";
            return 0;
        }
        prev = max(h-1, prev);
    }
    cout << "Yes\n";
    return 0;
}
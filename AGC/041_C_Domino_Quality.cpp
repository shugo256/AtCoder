#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cassert>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 2) cout << -1 << '\n';
    else if (n % 4 == 0) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if ((i/2 + j/2) % 2) {
                    cout << (char)('a' + ((i/2 + j/2) * 2 + i % 2) % 26);
                } else {
                    cout << (char)('a' + ((i/2 + j/2) * 2 + j % 2) % 26);
                }
            }
            cout << '\n';
        }
    } else if (n % 2 == 1) {
        cout << '.';
        for (int i=0; i<n-1; i++) cout << (char)('a' + i / 2 % 26);
        cout << '\n';
        for (int i=0; i<n-1; i++) {
            cout << (char)('a' + i / 2 % 26);
            for (int j=1; j<n; j++) cout << '.';
            cout << '\n';
        }
    } else {
        n /= 2;
        for (int k=0; k<2; k++) {
            cout << '.';
            for (int l=0; l<2; l++)
                for (int i=0; i<n-1; i++) 
                    cout << (char)('a' + i / 2 % 26);
            cout << '\n';
            for (int i=0; i<n-1; i++) {
                for (int l=0; l<2; l++) {
                    cout << (char)('a' + i / 2 % 26);
                    for (int j=1; j<n; j++) cout << '.';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
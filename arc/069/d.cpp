#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool wolf[n], resp[n];
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        resp[i] = (c == 'o');
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            wolf[n-2] = i;
            wolf[n-1] = j;
            for (int k=0; k<n; k++) {
                bool pw1 = wolf[(n + k - 1) % n],
                     pw2 = wolf[(n + k - 2) % n],
                     pr1 = resp[(n + k - 1) % n];
                wolf[k] = !(pr1 xor pw1 xor pw2);
            }
            if (wolf[n-2] == i && wolf[n-1] == j) {
                for (auto w : wolf) {
                    cout << (w ? 'W' : 'S');
                }
                cout << '\n';
                return 0;
            }
        }
    }
    
    cout << -1 << '\n';
    return 0;
}
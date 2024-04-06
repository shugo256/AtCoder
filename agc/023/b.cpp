#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cin.ignore();
        cout << 1 << '\n';
        return 0;
    }
    vector<string> s(n);
    for (auto &si:s) {
        cin >> si;
        si += si.substr(0, n-1);
    }
    for (size_t i=0; i<n-1; i++) s.push_back(s[i]);
    int cnt=0;
    size_t a = 0, b = n - 1;
    while (b >= n/2) {
        bool good = true;
        for (size_t i=0; i<n; i++) {
            for (size_t j=0; j<i; j++) {
                if (s[i+a][j+b] != s[j+a][i+b]) {
                    good = false;
                    break;
                }
            }
            if (!good) break;
        }
        if (good) cnt += n;
        if (a + b < n) a++;
        else b--;
    }
    cout << cnt << '\n';
    //for (auto si:s) cerr << si << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "12345678";
    s = s.substr(0, n);
    string p = "", q = "";
    for (int i=0, pi; i<n; i++) {
        cin >> pi;
        p += (char)('0' + pi);
    }
    for (int i=0, qi; i<n; i++) {
        cin >> qi;
        q += (char)('0' + qi);
    }
    int i=0, a, b;
    do {
        if (p == s) a = i;
        if (q == s) b = i;
        i++;
    } while (next_permutation(s.begin(), s.end()));
    cout << abs(a - b) << '\n';
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

#define MAX 1000010

template <typename T>
T gcd(T a, T b) {
    if (a > b) {
        T buf = a;
        a = b;
        b = buf;
    }
    return a == 0 ? b : gcd(a, b%a);
}

int main() {
    int n;
    cin >> n;
    vector spf(MAX, -1);
    spf[0] = 0; spf[1] = 1;
    for (int i=2; i<MAX; i++) {
        if (spf[i] < 0) {
            for (int j=i; j<MAX; j+=i) {
                spf[j] = i;
            }
        }
    }
    set<int> st;
    int all_gcd = 0;
    bool pairwise = true;
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        all_gcd = gcd(all_gcd, ai);
        while (ai > 1) {
            if (st.count(spf[ai])) {
                pairwise = false;
                break;
            } else {
                int prime = spf[ai];
                while (ai % prime == 0) ai /= prime;
                st.insert(prime);
            }
        }
    }
    if (pairwise) {
        cout << "pairwise coprime" << '\n';
    } else if (all_gcd == 1) {
        cout << "setwise coprime" << '\n';
    } else {
        cout << "not coprime" << '\n';
    }
    return 0;
}
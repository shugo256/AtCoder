#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    long n;
    cin >> n;
    long perm[n];
    for (long i=0; i<n; i++) {
        int a;
        cin >> a; a--;
        perm[a] = i;
    }
    set<long> used;
    used.insert(-1);
    used.insert(n);
    long sum = 0;
    for (long i=0; i<n; i++) {
        long p = perm[i];
        auto itr1 = used.upper_bound(p), itr2 = itr1;
        itr1--;
        sum += (*itr2 - p) * (p - *itr1) * (i + 1);
        used.insert(p);
    }
    cout << sum << '\n';
    return 0;
}
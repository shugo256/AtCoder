#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<long, greater<long>> s;
    long red=0;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        red ^= a;
        s.insert(a);
    }
    long blue=0,
         d = 1l << 60;
    auto itr = s.begin();
    for (int i=0; i<=60; i++) {
        long rd = red and d,
             bd = blue and d;
        if (rd == 0 && bd == 0) {
            long bval = 0;
            auto bitr = itr;
            for ( ; *itr >= d && itr != s.end(); itr++) {
                if ((blue xor *itr) + (red xor *itr) > bval) {
                    bval = (blue xor *itr) + (red xor *itr);
                    bitr = itr;
                }
            }
            red ^= *bitr;
            blue ^= *bitr;
        }
        else if (rd == 0 || bd == 0) {
            while (*itr >= d && itr != s.end()) {
                itr = s.erase(itr);
                s.insert(*itr - d);
            }
        }
        d /= 2;
    }
    cout << red + blue << '\n';
    return 0;
}
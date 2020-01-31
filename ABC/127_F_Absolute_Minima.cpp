#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int q; cin >> q;
    long a, b;
    cin >> a >> a >> b;
    multiset<long> alist;
    alist.insert(a);
    auto center = alist.begin();
    int len = 1;
    long sum = b;
    for (int i = 1; i < q; i++) {
        // cerr << "center " << *center << ' ' << sum << '\n';
        int type; cin >> type;
        if (type == 1) {
            cin >> a >> b;
            sum += abs(*center - a) + b;
            alist.insert(a);
            if (len%2 == 1 && a < *center) 
                center--;
            else if (len%2 == 0 && a >= *center) {
                long prev = *center;
                center++;
                sum -= *center - prev;
            }
            len++;
        } else
            cout << *center << ' ' << sum << '\n';
    }
    return 0;
}

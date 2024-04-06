#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define INF 10000000000000000

int main() {
    int n, k;
    cin >> n >> k;
    long sum = 0;
    multiset<long> minus, plus;
    for (int i=0; i<k; i++) minus.insert(INF);
    for (int i=0; i<n; i++) {
        bool t; long a;
        cin >> t >> a;
        sum += a;
        if (t) {
            plus.insert(a);
            if (minus.empty()) {
                auto front = plus.begin();
                sum -= *front;
                plus.erase(front);
            } else {
                auto back = minus.end();
                back--;
                minus.erase(back);
            }
        } else {
            minus.insert(a);
            if (plus.empty()) {
                auto front = minus.begin();
                sum -= *front;
                minus.erase(front);
            } else {
                auto back = plus.end();
                back--;
                plus.erase(back);
            }
        }
    }
    cout << sum << '\n';
    return 0;
}
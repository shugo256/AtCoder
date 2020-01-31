#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

struct test {long b, l, u, i;};

long n, x;
long aoki=0;

long last(test t) {
    return (aoki + (t.u - t.l) * t.b) / t.u;
}

long fudan(test t) {
    return x * t.u - t.b * (t.u - t.l);
}

int main() {
    cin >> n >> x;
    test testsA[n], testsB[n];
    auto compA = [&](test l, test r) {
        return (aoki + (l.u - l.l) * l.b) / l.u
        < (aoki + (r.u - r.l) * r.b) / r.u;
    };
    auto compB = [&](test l, test r) {
        return fudan(l) > fudan(r);
    };
    for (int i=0; i<n; i++) {
        test t;
        cin >> t.b >> t.l >> t.u;
        t.i = i;
        testsA[i] = t;
        testsB[i] = t;
        aoki += t.b*t.l;
    }
    bool used[100010] = {0};
    sort(testsA, testsA+n, compA);
    sort(testsB, testsB + n, compB);
    int aid=0, bid=0;
    long time=0;
    while (aoki > 0) {
        while (used[testsA[aid].i]) aid++;
        long l = last(testsA[aid]);
        if (l > x) {
            while (used[testsB[bid].i]) bid++;
            aoki -= fudan(testsB[bid]);
            used[testsB[bid].i] = true;
            time += x;
        } else {
            time += l;
            break;
        }
    }
    cout << time << '\n';
    return 0;
}

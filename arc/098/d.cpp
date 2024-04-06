#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long n;
    cin >> n;
    long cnt=0, now=0, total = 0, a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        while ((now ^ a[i]) != now + a[i]) {
            total += cnt;
            now ^= a[i - cnt];
            cnt--;
        }
        now ^= a[i];
        cnt++;
        if (i == n - 1) total += (cnt + 1) * cnt / 2;
    }
    cout << total << '\n';
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    long n, k;
    cin >> n >> k;
    long a[n];
    for (auto &ai:a) cin >> ai;
    long j=0, sum=0, cnt=0;
    for (long i=0; i<n; i++) {
        while (sum < k && j < n) {
            sum += a[j];
            j++;
            //cerr << sum << ' ' << i << ' ' << j << '\n';
        }
        if (sum < k) break;
        cnt += n - j + 1;
        sum -= a[i];
    }
    cout << cnt << '\n';
    return 0;
}

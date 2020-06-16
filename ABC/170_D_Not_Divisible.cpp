#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int cnt[1000010] = {0};
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (cnt[a[i]] > 1 || (a[i] > 1 && cnt[1] > 0)) {
            ans++;
        } else {
            for (int j=2; j*j <= a[i] && j < a[i]; j++) {
                if (a[i] % j == 0) {
                    if (cnt[j] > 0 || cnt[a[i] / j] > 0) {
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << n - ans << '\n';
    return 0;
}
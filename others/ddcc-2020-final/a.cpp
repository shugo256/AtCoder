#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    bool used[100] = {0};
    int ans = 0;
    for (int i=0, ai; i<n; i++) {
        cin >> ai;
        vector<int> divs;
        for (int i=1; i*i<=ai; i++) {
            if (ai % i == 0) {
                divs.push_back(i);
                if (ai/i != i)
                    divs.push_back(ai/i);
            }
        }
        sort(divs.begin(), divs.end());
        int l = divs.size();
        int g[l];
        g[0] = 0;
        for (int j=0; j<l; j++) {
            fill(used, used+100, false);
            for (int k=0; k<j; k++) {
                if (divs[j] % divs[k] == 0) {
                    used[g[k]] = true;
                }
            }
            for (int k=0; k<100; k++) {
                if (!used[k]) {
                    g[j] = k;
                    break;
                }
            }
        }
        ans ^= g[l-1];
    }
    cout << (ans ? "Yes" : "No") << '\n';
    return 0;
}
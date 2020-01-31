#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool a[n], b[n];
    vector<int> ans;
    for (auto &ai:a) cin >> ai;
    for (int i=n; i>0; i--) {
        b[i-1] = a[i-1];
        for (int j=2*i; j<=n; j+=i)
                b[i-1] ^= b[j-1];
        if (b[i-1])
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int i=ans.size()-1; i>=0; i--) cout << ans[i] << (i > 0 ? ' ' : '\n');
    return 0;
}
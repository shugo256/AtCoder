#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int n, m;
vector<int> s[10];
int p[10];
int on[10] = {0};

int dfs(int i) {
    //cerr << i << ' ' << n << '\n';
    if (i == n) {
        bool yes = true;
        for (int j = 0; j < m; j++) {
            int sum=0;
            for (auto sjk : s[j]) sum += on[sjk];
            //cerr << sum << '\n';
            if (sum % 2 != p[j]) {
                yes = false;
                break;
            }
        }
        return (int)yes;
    } else {
        int a, b;
        on[i] = 0;
        a = dfs(i + 1);
        on[i] = 1;
        b = dfs(i + 1);
        return a + b;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int sij; cin >> sij;
            s[i].push_back(sij - 1);
        }
    }
    for (int i = 0; i < m; i++) cin >> p[i];
    cout << dfs(0) << '\n';
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    set<int> s;
    for (int i=1; i<=n; i++) s.insert(i);
    for (int i=0, di; i<k; i++) {
        cin >> di;
        for (int j=0, aij; j<di; j++) {
            cin >> aij;
            s.erase(aij);
        }
    }
    cout << s.size() << '\n';
    return 0;
}
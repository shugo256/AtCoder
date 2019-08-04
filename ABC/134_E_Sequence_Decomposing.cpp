#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<int> s;
    for (int i=0; i<n; i++) {
        int ai;
        cin >> ai;
        auto lb = s.lower_bound(ai);
        if (s.begin() != lb) {
            lb--;
            s.erase(lb);
        }
        s.insert(ai);
    }
    cout << s.size() << '\n';
    return 0;
}
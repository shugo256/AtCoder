#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        s.insert(a);
    }
    cout << max(1, (int)(s.size()+1)/2*2-1) << '\n';
    return 0;
}
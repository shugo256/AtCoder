#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int cnt = 1, sum = 0;
    for (int i=0; i<n; i++) {
        int l; cin >> l;
        sum += l;
        if (sum <= x) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    int n, p1, p2, cnt=0;
    cin >> n >> p1 >> p2;
    for (int i=2; i<n; i++) {
        int p3;
        cin >> p3;
        if (min(p1, p3) < p2 && p2 <= max(p1, p3)) cnt++;
        p1 = p2;
        p2 = p3;
    }
    cout << cnt << '\n';
    return 0;
}

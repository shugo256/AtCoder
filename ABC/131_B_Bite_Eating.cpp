#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>


using namespace std;

int main() {
    int n, l, best=1000, sum = 0;
    cin >> n >> l;
    for (int i=1; i<=n; i++) {
        if (abs(l + i - 1) < abs(best))
            best = l + i - 1;
        sum += l + i - 1;
    }
    cout << sum - best << '\n';
    return 0;
}

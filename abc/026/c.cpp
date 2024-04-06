#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[20];

int paycheck(int i=0) {
    if (G[i].empty()) return 1;
    int maxp=0, minp=10000000;
    for (auto g:G[i]) {
        int gpay = paycheck(g);
        maxp = max(maxp, gpay);
        minp = min(minp, gpay);
    }
    return maxp + minp + 1;
}

int main() {
    int n;
    cin >> n;
    for (int i=1; i<n; i++) {
        int chokuzoku;
        cin >> chokuzoku;
        chokuzoku--;
        G[chokuzoku].push_back(i);
    }
    cout << paycheck() << '\n';
    return 0;
}
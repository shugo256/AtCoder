#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n];
    for (auto &di:d) cin >> di;
    sort(d, d+n);
    cout << d[n/2] - d[n/2-1] << '\n';
    return 0;
}

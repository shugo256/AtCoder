#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (auto &ai:a)
        cin >> ai;
    double sum = 0;
    for (auto &ai:a) {
        sum += 1 / (double) ai;
    }
    cout << setprecision(10) << 1 / sum << '\n';
    return 0;
}
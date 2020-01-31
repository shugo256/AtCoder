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
    int v[n];
    for (auto &vi:v) cin >> vi;
    sort(v, v+n);
    double sum = v[0];
    for (auto vi:v) {
        sum += (double) vi;
        sum /= 2;
    }
    cout << setprecision(10) << sum << '\n';
    return 0;
}
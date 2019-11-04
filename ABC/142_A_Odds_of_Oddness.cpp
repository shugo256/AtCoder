#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << setprecision(15) << (double)(n - n / 2) / n << '\n';
    return 0;
}

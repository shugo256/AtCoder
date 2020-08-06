#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> f(n, 0);
    for (int x=1; x<=100; x++) {
        for (int y=1; y<=100; y++) {
            for (int z=1; z<=100; z++) {
                int val = x * x + y * y + z * z + x * y + y * z + z * x - 1;
                if (val < n)
                    f[val]++;
            }
        }
    }
    for (auto &fi:f) cout << fi << '\n';
    return 0;
}
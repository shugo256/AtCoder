#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    long m;
    cin >> n >> m;
    unordered_map<long, long> mods;
    long rui = 0, sum = 0;
    mods[0] = 1;
    for (int i=0; i<n; i++) {
        long a;
        cin >> a;
        rui = (rui+a) % m;
        sum += mods[rui];
        mods[rui]++;
    }
    cout << sum << '\n';
    return 0;
}
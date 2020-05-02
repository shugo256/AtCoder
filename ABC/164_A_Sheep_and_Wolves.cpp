#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int s, w;
    cin >> s >> w;
    cout << (s <= w ? "unsafe" : "safe") << '\n';
    return 0;
}
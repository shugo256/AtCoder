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
    cout << (1000 - n % 1000) % 1000 << '\n';
    return 0;
}
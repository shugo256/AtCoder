#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string s;
    int k;
    cin >> k >> s;
    cout << s.substr(0, k) + (s.size() > k ? "..." : "") << '\n';
    return 0;
}
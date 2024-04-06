#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    char prev = '\0';
    int score = 0;
    for (auto c:s) {
        if (c == prev) score++;
        prev = c;
    }
    cout << score + min(2*k, n - score - 1) << '\n';
    return 0;
}
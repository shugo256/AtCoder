#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string s;
    cin >> s;
    int len = (int)s.size(), h = len / 2, cnt = 0;
    for (int i=0; i<h; i++) {
        if (s[i] != s[len-i-1]) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
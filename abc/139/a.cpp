#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int cnt = 0;
    for (int i=0; i<3; i++) cnt += (s[i] == t[i]);
    cout << cnt << '\n';
    return 0;
}
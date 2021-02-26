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
    int n = s.size();
    s += (s[n-1] == 's' ? "es" : "s");
    cout << s << '\n';
    return 0;
}
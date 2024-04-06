#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>


using namespace std;

int main() {
    string s;
    map<char, int> m;
    cin >> s;
    for (auto c:s)m[c]++;
    bool res = true;
    for (auto mi:m) if (mi.second != 2) res = false;
    cout << (m.size() == 2 && res ? "Yes" : "No")
         << '\n';
    return 0;
}

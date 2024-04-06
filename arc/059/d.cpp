#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> P;

int main() {
    string s;
    cin >> s;
    int32_t len = (int)s.size();
    P cnt[26];
    for (auto &p:cnt) p = {len, 0};
    for (int b = 0; b < len; b++) {
        int i = s[(size_t)b] - 'a', a = cnt[i].first, same = cnt[i].second;
        if (b > a && (b-a+1) / 2 < same + 1) {
            cout << a + 1 << ' ' << b + 1 << '\n';
            return 0;
        } else 
            cnt[i] = {b, 1};
    }
    cout << -1 << ' ' << -1 << '\n';
    return 0;
}
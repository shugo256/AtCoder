#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    size_t l = 0, r = 0;
    for (auto c:s) {
        if (c == '(') r++;
        else if (r > 0) r--;
        else l++;
    }
    cout << string(l, '(') + s + string(r, ')') << '\n';
    return 0;
}
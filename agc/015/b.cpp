#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    long i = 0, n = (long)s.size() - 1, cnt = 0;
    for (auto c:s) {
        if (c == 'U')
            cnt += n + i;
        else
            cnt += 2*n - i;
        i++;
    }
    cout << cnt << '\n';
    return 0;
}
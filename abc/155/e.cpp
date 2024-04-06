#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define INF 10000000

int main() {
    string n;
    cin >> n;
    n = '0' + n;
    int len = n.size(),
        low = 0, up = 0,
        plow = 0, pup = 0;
    for (int i=0; i<len; i++) {
        int digit = n[i] - '0';
        low = min(plow + digit, pup + 10 - digit);
        up  = min(plow + digit + 1, pup + 10 - digit - 1);
        plow = low; pup = up;
    }
    cout << low << '\n';
    return 0;
}
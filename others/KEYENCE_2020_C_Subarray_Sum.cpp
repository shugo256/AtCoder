#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    for (int i=0; i<k; i++) cout << s << ' ';
    if (s == (int) 1e9) s = 1;
    else s++;
    for (int i=k; i<n; i++) cout << s << (i < n-1 ? ' ' : '\n');
    return 0;
}
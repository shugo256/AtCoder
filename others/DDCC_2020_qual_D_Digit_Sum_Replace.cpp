#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    int m;
    cin >> m;
    ll d, c, sum=0, dcnt=0;
    for (int i=0; i<m; i++) {
        cin >> d >> c;
        sum += d*c;
        dcnt += c;
    }
    cout << (sum - 1) / 9 + dcnt - 1 << '\n';
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int h, m, s, c1, c2;
    cin >> h >> m >> s >> c1 >> c2;
    int t = h * 3600 + m * 60 + s,
        nms = t * 59 / 3600  + c1,
        nhm = t * 11 / 43200 + c2,
        t1 = max((nms * 3600) / 59, (nhm * 43200) / 11) + 1,
        t2 = min(((nms+1) * 3600) / 59, ((nhm+1) * 43200) /11);
    if (t1 % 3600 == 0) t1++;
    if (t2 % 3600 == 0) t2--;
    if (t1 > t2) cout << "-1" << '\n';
    else cout << t1 - t << ' ' << t2 - t << '\n';
    return 0;
}
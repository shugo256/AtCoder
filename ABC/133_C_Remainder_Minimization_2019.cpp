#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    long l, r;
    cin >> l >> r;
    int cnt[2019] = {0};
    long q = l / 2019,
         ama = l % 2019,
         dq = (r - l) / 2019,
         dama = (r - l) % 2019;
        
    if (dq >= 2) {
        for (auto &c:cnt) c = 2;
    } else if (dq == 1) {
        for (auto &c : cnt) c = 1;
        for (int i=ama; i<=ama+dama; i++) cnt[i%2019]++;
    } else {
        for (int i = ama; i <= ama + dama; i++) cnt[i % 2019]++;
    }
    int best = 2019;
    for (int i=0; i<2019; i++) {
        for (int j=0; j<=i; j++) {
            if ((i != j && cnt[i] && cnt[j]) || (i == j && cnt[i] == 2))
                best = min(best, (i * j) % 2019);
        }
    }
    cout << best << '\n';
    return 0;
}

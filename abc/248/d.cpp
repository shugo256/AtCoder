#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

struct event {
    int idx;
    int target;
    bool isEnd;
};

int main() {
    int n, q;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &ai : a) std::cin >> ai;

    std::cin >> q;
    std::vector events(n, std::vector<event>());
    for (int i = 0, li, ri, xi; i < q; i++) {
        std::cin >> li >> ri >> xi;
        li--; ri--;
        if (li > 0) {
            events[li-1].push_back({i, xi, false});
        }
        events[ri].push_back({i, xi, true});
    }
    std::vector<int> count(200010, 0);
    std::vector<int> results(q, 0);

    for (int i = 0; i < n; i++) {
        count[a[i]]++;
        for (auto &[qId, target, isEnd] : events[i]) {
            results[qId] += (isEnd ? count[target] : -count[target]);
        }
    }

    for (auto &ri : results) {
        std::cout << ri << '\n';
    }
    
    return 0;
}
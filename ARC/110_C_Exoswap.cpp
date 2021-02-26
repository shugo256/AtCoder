#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;


int main() {
    int n;
    std::cin >> n;
    std::vector used(n, false);
    std::vector<int> p(n), p_inv(n);
    for (int i=0; i<n; i++) {
        std::cin >> p[i];
        p[i]--;
        p_inv[p[i]] = i;
    }
    std::vector<int> ans;
    for (int i=0; i<n; i++) {
        for (int j=p_inv[i]; j>i; j--) {
            // for (auto &pi:p) std::cerr << pi << ' ';
            // std::cerr << std::endl;
            if (used[j-1]) {
                std::cout << -1 << '\n';
                return 0;
            }
            used[j-1] = true;
            std::swap(p_inv[p[j]], p_inv[p[j-1]]);
            std::swap(p[j], p[j-1]);
            ans.push_back(j);
        }
    }
    if (ans.size() == n-1) {
        for (auto &ai:ans) {
            std::cout << ai << '\n';
        }
    } else {
        std::cout << -1 << '\n';
    }
    return 0;
}
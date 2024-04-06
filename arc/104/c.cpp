#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)

using ll = long long;

using P = std::pair<int, bool>;
#define fi first
#define se second

struct floor {
    int id;
    bool used;
    bool in;
    bool has_tui;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<floor> status(2*n, floor{-1, false, false, false});
    for (int i=0, ai, bi; i<n; i++) {
        std::cin >> ai >> bi;
        if (ai >= bi && bi > 0) {
            std::cout << "No" << '\n';
            return 0;
        }
        if (ai > 0) {
            if (status[ai-1].used) {
                std::cout << "No" << '\n';
                return 0;
            }
            status[ai-1] = floor{i, true, true, bi > 0};
        }
        if (bi > 0) {
            if (status[bi-1].used) {
                std::cout << "No" << '\n';
                return 0;
            }
            status[bi-1] = floor{i, true, false, ai > 0};
        }
    }
    std::vector<bool> dp(n+1, false);
    dp[0] = true;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<i; j++) {
            if (!dp[j]) continue;
            int w = i - j;
            dp[i] = true;
            for (int k=0; k<w; k++) {
                if ((status[j*2+k].used && status[j*2+w+k].used && status[j*2+k].id == status[j*2+w+k].id)
                        || ( status[j*2+k].used && !status[j*2+w+k].used && !status[j*2+k].has_tui)
                        || (!status[j*2+k].used &&  status[j*2+w+k].used && !status[j*2+w+k].has_tui)
                        || (!status[j*2+k].used && !status[j*2+w+k].used)) {
                    continue;
                }
                dp[i] = false;
                break;
            }
            if (dp[i]) break;
        }
    }
    std::cout << (dp[n] ? "Yes" : "No") << '\n';
    return 0;
}
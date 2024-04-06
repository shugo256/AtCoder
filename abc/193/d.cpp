#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

void count(std::vector<int> &cnt, std::string &hand) {
    for (auto &hi:hand) {
        cnt[hi - '0']++;
    }
}

int score(std::string &hand) {
    std::vector cnt(10, 0);
    count(cnt, hand);
    int sum = 0;
    for (int i=1; i<10; i++) {
        int part = i;
        for (int j=0; j<cnt[i]; j++) part *= 10;
        sum += part;
    }
    return sum;
}

int main() {
    int k;
    std::string s, t;
    std::cin >> k >> s >> t;
    double ans = 0;
    int n = k * 9;
    for (int i=1; i<10; i++) {
        for (int j=1; j<10; j++) {
            s[4] = '0' + i;
            t[4] = '0' + j;
            // std::cerr << i << ' ' << j << ' ' << score(s) << ' ' << score(t) << std::endl;
            if (score(s) > score(t)){
                std::vector left(10, -k); // マイナス残り個数
                std::string concat = s + t;
                left[i]--; left[j]--; // 一旦返却
                count(left, concat);
                double p = double(std::max(-left[i], 0)) / (n - 8);
                left[i]++; // iを使う
                p *= double(std::max(-left[j], 0)) / (n - 9);
                ans += p;
            }
        }
    }
    std::cout << std::setprecision(10) << ans << '\n';
    return 0;
}
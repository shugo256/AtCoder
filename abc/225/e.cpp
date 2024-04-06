#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <complex>
#include <atcoder/segtree>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using namespace std::complex_literals;

using ll = long long;
using ld = long double;

int max(int a, int b) {
    return std::max(a, b);
}

int zero() {
    return 0;
}

#include <map>
#include <set>
// vecのなかの全要素について座標圧縮を行い、元座標->圧縮後座標というmapを作る
// O(NlogN) 座圧後のサイズを返す
// org: もともとの各iに対する座標 値渡しなので破壊しません
// zip: 圧縮
// unzip: 復元
template <typename T>
int compress(std::vector<T> org, std::map<T, int> &zip, std::vector<T> &unzip) {
    std::sort(org.begin(), org.end()); 
    org.erase(unique(org.begin(), org.end()), org.end()); // vecの各要素を小さい順に重複を無くして並べたもの
    int i = 0;
    for (auto &oi : org) {
        zip[oi] = i;
        unzip.push_back(oi);
        i++;
    }
    return i;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<ld, ld>> fus(n);
    std::vector<ld> args;
    for (auto &fui : fus) {
        ld xi, yi;
        std::cin >> xi >> yi;
        std::complex<ld> p(xi, yi);
        fui = {std::arg(p - 1.0il), std::arg(p - 1.0l)};
        args.push_back(fui.first);
        args.push_back(fui.second);
    }

    std::map<ld, int> zip;
    std::vector<ld> unzip;
    int m = compress(args, zip, unzip);

    atcoder::segtree<int, max, zero> dp(m);
    std::sort(fus.begin(), fus.end());
    for (auto &[b, e] : fus) {
        // std::cerr << b << ' ' << e << ' ' << zip[b] << ' ' << zip[e] << std::endl;
        int orgVal = dp.get(zip[e]);
        int updVal = dp.prod(0, zip[b] + 1) + 1;
        if (orgVal < updVal) {
            dp.set(zip[e], updVal);
        }
    }

    std::cout << dp.all_prod() << '\n';

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

// xorの掃き出し法 O(N^2)
// matに基底たちが入る
// Tはbitsetは無理(minしないといけないから)
template <typename T>
int gauss_jordan(vector<T> &mat) {
    std::vector<T> bases;
    for (auto e:mat) {
        for (auto &b:bases) {
            e = min(e, e^b);
        }
        if (e)
            bases.push_back(e);
    }
    mat.swap(bases);
    return (int)mat.size();
}


int main() {
    int n;
    std::cin >> n;
    std::cout << n << '\n';
    return 0;
}
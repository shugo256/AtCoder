#include <iostream>
#include <algorithm>

using namespace std;

#define MAX = 1000010
using T = long;

// 和以外はseg木でよくねという発想の元、和のみを実装
class BIT {
    T bit[MAX] = {0};
    const int n;

public:
    BIT(int n) : n(n) {}

    // v[a] += w
    template <typename ID>
    T add(ID a, T w) {
        for (int i=(int)a; i<n; i |= (i+1))
            bit[i] += w;
    }

    // v[0] + v[1] + ... + v[a-1]
    template <typename ID>
    T sum(ID a) {
        T res = 0;
        for (int i=(int)a-1; i>=0; i = (i & (i+1)) - 1)
            res += bit[i];
        return res;
    }
}

int main() {
    int n;
    cin >> n;
    
    cout << n << '\n';
    return 0;
}
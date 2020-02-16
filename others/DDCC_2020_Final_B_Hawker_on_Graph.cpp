#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<ll, ll>;
#define fi first
#define se second

#define INF (long)(1e16 + 1)

constexpr P P_ZERO{-INF, -INF},
            P_ONE{0, -INF};

inline P operator*(const P &l, const P &r) {
    if (l == P_ZERO || r == P_ZERO) return P_ZERO;
    return {l.fi + r.fi, max(l.se + r.fi, r.se)};
}

inline P operator+(const P &l, const P &r) {
    if (l == P_ZERO) return r;
    else if (r == P_ZERO) return l;
    if (l == P_ONE) return r;
    else if (r == P_ONE) return l;
    return {max(l.fi, r.fi), max(l.se, r.se)};
}


ostream &operator<<(ostream &os, const P &out) {
    if (out.fi == -INF)
        os << '{' << "-INF" << ", " << out.se << '}';
    else if (out.se == -INF)
        os << '{' << out.fi << ", " << "-INF" << '}';
    else
        os << '{' << out.fi << ", " << out.se << '}';
        
    return os;
}


#include <cassert>
#include <initializer_list>

template <typename T>
class matrix {
    int h, w;
    vector<vector<T>> body;

    // 長方形の配列になっているかcheck
    bool check() {
        for (auto &b:body)
            if ((int)b.size() != w)
                return false;
        return true;
    }

public:
    matrix() = default;

    // 初期化子リスト matrix<T> mat{{0}, {1}, {2}}; みたいにかける
    matrix(initializer_list<initializer_list<T>> _body) {
        for (auto &bi:_body) body.emplace_back(bi);
        h = (int)body.size();
        w = (int)body[0].size();
        assert(check());
    }

    matrix(int _h, int _w, T init=P_ZERO)
        : h(_h)
        , w(_w)
        , body((size_t)_h, vector<T>((size_t)_w, init)) {
    }
    // n x nの単位行列 matrix::I(n)でよべる
    static matrix I(int _n) {
        matrix m(_n, _n);
        for (int i=0; i<_n; i++) {
            m[i][i] = P_ONE;
        }
        return m;
    }

    pair<int, int> &shape() { return {h, w}; };
    
    template <typename ID> vector<T> &operator[](ID i) { return body[(size_t)i]; }
    template <typename ID> vector<T> operator[](ID i) const { return body[(size_t)i]; }

    auto begin() { return body.begin(); }
    auto end() { return body.end(); }
    auto begin() const { return body.begin(); }
    auto end() const { return body.end(); }

    matrix operator*(const matrix &r) {
        assert(w == r.h);
        matrix res(h, r.w);
        for (size_t i=0; i<(size_t)h; i++) {
            for (size_t j=0; j<(size_t)r.w; j++) {
                for (size_t k=0; k<(size_t)w; k++) {
                    res[i][j] = body[i][k] * r[k][j] + res[i][j];
                }
            }
        }
        return res;
    }
    void operator*=(const matrix &r) { *this = *this * r; }

    // TODO
    // T det() {
    //     assert(w == h);
        
    // }
    // matrix &inv() {
    //     matrix(h, w)
    // }

    // O(N^3 logk)
    matrix pow(ll k) {
        assert(h == w);
        // if (k < 0) return matrix.inv().pow(-k);
        matrix x = I(h), a(*this);
        while(k > 0){
            if(k & 1){
                x *= a;
            }
            a *= a;
            k >>= 1;
        }
        return x;
    }
};

template <typename T>
ostream &operator<<(ostream &os, const matrix<T> &out) {
    for (auto &oi:out) {
        if (&oi != &*out.begin()) os << '\n';
        for (auto &oij:oi)
            if (&oij == &*oi.begin()) os << oij;
            else os << ' ' << oij;
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, matrix<T> &in) {
    for (auto &ini:in) {
        for (auto &inij:ini)
            is >> inij;
    }
    return is;
}


int main() {
    int n, m, s, k;
    ll w;
    cin >> n >> m >> w >> s >> k;
    s--;
    matrix<P> mat(n, n);
    for (int i=0, ui, vi, wi; i<m; i++) {
        cin >> ui >> vi >> wi;
        ui--;
        vi--;
        mat[ui][vi] = {(ll)wi, 0ll};
    }
    auto g = mat.pow(k);
    ll ans = -1;
    for (auto &gsi:g[s]) ans = max(ans, max(w + gsi.fi, gsi.se));
    cout << ans << '\n';
    return 0;
}
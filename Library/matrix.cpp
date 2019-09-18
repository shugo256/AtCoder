#include <iostream>
#include <vector>

using namespace std;

#include <cassert>
template <typename T>
class matrix {
    int h, w;
    vector<vector<T>> body;

    bool check();

public:
    matrix(vector<vector<T>> &_body) : body(_body), h((int)_body.size()), w((int)_body[0].size()) {
        assert(check());
    }
    matrix(int _h, int _w, T init=0) : body((size_t)_h, vector<T>((size_t)_w, init)), h(_h), w(_w) {
        assert(check());
    }
    // n x nの単位行列
    matrix(int _n) : matrix(_n, _n, 0) {
        for (size_t i=0; i<(size_t)_n, i++) body[i][i] = 1;
    }

    int shape(bool i) { return i ? w : h };
    
    template <typename ID>
    vector<T> &operator[](ID i) { return body[(size_t)k]; };

    typename vector<T>::iterator begin() { return body.begin(); }
    typename vector<T>::iterator end() { return body.end(); }

    matrix &operator+(const matrix &r) {
        assert(h == r.h && w == r.w);
        matrix res(h, w);
        for (size_t i=0; i<(size_t)h; i++)
            for (size_t j=0; j<(size_t)w; j++)
                res[i][j] = body[i][j] + r[i][j];
    }
    matrix &operator-(const matrix &r) {
        assert(h == r.h && w == r.w);
        matrix res(h, w);
        for (size_t i=0; i<(size_t)h; i++)
            for (size_t j=0; j<(size_t)w; j++)
                res[i][j] = body[i][j] - r[i][j];
    }

    friend ostream &operator<<(ostream &os, matrix &out) {
        for (auto &bi:body) {
            for (auto &bij:bi)
                os << bij << ' ';
            os << '\n';
        }
    }

private:
    // 長方形の配列になっているかcheck
    bool check() {
        for (auto b:body)
            if (b.size() != w)
                return false;
        return true;
    }
};

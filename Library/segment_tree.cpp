#include <iostream>
#include <vector>

using namespace std;

#include <functional>

template <typename T>
class Segment_Tree {
    const size_t len, size, half;
    const T init;
    function<T(T, T)> f;
    vector<T> tree;

    // treeのサイズを計算
    size_t get_size(size_t len) {
        len--;
        size_t size = 2;
        while (len > 0) { len /= 2; size *= 2; }
        return size;
    }

    int update_id = -1;
    T update_val = 0;

public:
    Segment_Tree(vector<T> arr, T init, function<T(T, T)> f)
        : len(arr.size()),
          size(get_size(len) - 1),
          half((size + 1) / 2),
          init(init),
          f(f),
          tree((size_t)size, init) {
        cerr << "half"<< ' ' <<  half << '\n';
        size_t i = half - 1;
        for (auto ai : arr) {
            tree[i] = ai;
            i++;
        }
        size_t a = half - 1, b;
        while (a > 0) {
            b = a;
            a = (a - 1) / 2;
            for (size_t j=a; j<b; j++)
                tree[j] = f(tree[j*2+1], tree[j*2+2]);
        }
    }


    T &operator[] (int n) { 
        update();
        while (n < 0) n += half;
        size_t ret = (size_t)n % half + half - 1;
        update_id = n % (int)half;
        update_val = tree[ret];
        return tree[ret];
    }
    T &operator[] (size_t n) { return (*this)[(int)n]; }
    T operator[](pair<int, int> p) { 
        update(); 
        return query(p.first, p.second, 0, 0, (int)half);
    }

    T query(int a, int b, size_t k, int l, int r) {
        if (r <= a || b <= l) return init;
        if (a <= l && r <= b) return tree[k];
        int vl = query(a, b, k*2+1, l, (l+r)/2),
            vr = query(a, b, k*2+2, (l+r)/2, r);
        return f(vl, vr);
    }

    void update() {
        if (update_id == -1) return;
        size_t i = (size_t)update_id + half - 1;
        if (update_val == tree[i]) {
            update_id = -1;
            return;
        }
        while (i > 0) {
            i = (i - 1) / 2;
            tree[i] = f(tree[i * 2 + 1], tree[i * 2 + 2]);
        }
        update_id = -1;
    }

    void print_tree() {
        update();
        size_t next = 0;
        for (size_t i=0; i<size; i++) {
            cout << tree[i];
            if (i == next) {
                cout << '\n';
                next = (next + 1) * 2;
            } else 
                cout << string(size * 2 / (next+2), ' ');
        }
    }

    typename vector<T>::iterator begin() { return tree.begin() + half - 1; }
    typename vector<T>::iterator end() { return tree.end(); }
};

int main() {
    vector<int> arr({1, 3, 4, 2, 5});

    Segment_Tree<int> sgt(arr, 0, [](int r, int l) {return max(r, l);});

    sgt[-1] = 1;
    cerr << "fsdfs" << '\n';
    sgt.print_tree();
    cout << sgt[{4, 8}] << '\n';
}
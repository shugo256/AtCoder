#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define isLMS(i) (isL[(i)-1] && !isL[i])
#define LIMIT 1000000

template <typename T>
class SuffixArray {
    vector<T> s;
    const size_t len,
                 limit;  // lenは配列長 limitは配列に登場する文字/数字の種類数
    vector<size_t> bin,  // 頭文字の各アルファベットの出現回数の累積和
                   cnt,  // どのアルファベットから始まるものをいくつsaに割り当てたか
                   lms,  // LMSのインデックスを格納する配列
                   isL,  // s[i]がL型なら1 S型なら0
                   sa;   // sのsuffix arrayをインデックスで格納する配列

public:
    // Tが整数の時よう
    SuffixArray(vector<T> s, size_t limit=LIMIT)
     : s(s),
       len(s.size()),
       limit(limit),
       bin(limit+1, 0),
       cnt(limit+1, 0),
       isL(len+1),
       sa(len+1) {
           (this->s).push_back(0); // 末尾に番兵の追加
           lms.reserve(len/2);     // lmsの領域の確保
           sa_is();                // SAの構築
    } 

    // Tがcharの時用
    SuffixArray(string s, size_t limit=256) : SuffixArray(vector<char>(s.begin(), s.end()), limit) {}

    // LCP(高さ配列、蟻本p339)を計算する
    // lcp[i] = sa[i]とsa[i+1]の先頭何文字が一致しているか
    // このlcpをRange Minimum Queryに載せれば任意のi jに対してlcpが計算可能
    vector<int> lcp;

    void construct_lcp() {
        vector<size_t> rank(len+1);
        lcp.resize(len);
        for (size_t i=0; i<=len; i++)
            rank[sa[i]] = i;
        size_t h = 0;
        for (size_t i=0; i<len; i++) {
            size_t j = sa[rank[i] - 1];
            if (h > 0) h--;
            for ( ; i+h<len && j+h<len && s[i+h] == s[j+h]; h++);

            lcp[rank[i] - 1] = (int)h;
        }
    }

    auto begin() { return sa.begin(); }
    auto end()   { return sa.end(); }

    template <typename ID>
    int operator[](ID i) { return (int)sa[(size_t)i]; }

private:

    //SA-IS法によりSuffixArrayを構築する
    void sa_is() {
        isL[len] = false;
        bin[1] = 1;
        for (size_t i=len; i>0; i--) {
            isL[i-1] = (s[i-1] == s[i]) ? isL[i] : (s[i-1] > s[i]);
            bin[(size_t)s[i-1]+1]++;
            if (isLMS(i))
                lms.push_back(i);
        }

        vector<size_t> aligned(lms); // あとでlmsは色々並べ替えるが、ここに今の整列した状態を保存しておく
        reverse(aligned.begin(), aligned.end()); // 降順になっているのをひっくり返して昇順にする

        for (size_t i=0; i<limit; i++) bin[i+1] += bin[i]; // 累積和

        induced_sort(); // 1回目のinduced sort

        fill(sa.begin(), sa.end(), 0); // saにLMS部分文字列の順位を格納する
        size_t n = 0, lmslen = lms.size();

        // 辞書順で隣り合うLMSについて一致しているかどうか調べる(たかだかn回の比較)
        for (auto itr=lms.begin(); itr+1!=lms.end(); itr++) {
            size_t i = *itr, j = *(itr+1);
            for (size_t d=0; i+d <= len && j+d <= len; d++) {
                if (s[i+d] != s[j+d] || isLMS(i+d) != isLMS(j+d)) {
                    n++;
                    break;
                } else if (d > 0 && (isLMS(i+d) || isLMS(j+d)))
                    break;
            }
            sa[j] = n;
        }

        if (n < lmslen-1) {
            vector<size_t> next_s(lmslen-1);
            for (size_t i=0; i<lmslen-1; i++) { // alignedはここで使うために用意した
                next_s[i] = sa[aligned[i]];
                sa[aligned[i]] = 0; // saはまた0リセット
            }

            // sa-isを再帰的に用いる
            SuffixArray<size_t> next(next_s, n+1);

            for (size_t i=0; i<lmslen-1; i++)
                lms[i] = aligned[(size_t)next[lmslen-1-i]];
            lms[lmslen-1] = len;
        } else {
            for (auto i:aligned) 
                sa[i] = 0; // saを0リセット
        }

        fill(cnt.begin(), cnt.end(), 0);

        induced_sort();
    }

    // induced sortの3ステップを行う
    void induced_sort() {

        // step1:LMSをひとまず書き込んでいく
        for (auto i:lms) {
            size_t c = (size_t)s[i];
            cnt[c+1]++;
            sa[bin[c+1] - cnt[c+1]] = i;
        }

        fill(cnt.begin(), cnt.end(), 0);

        //step2:L型のsuffixを埋めていく
        for (auto i:sa) {
            if (i == 0 || !isL[i-1]) continue;
            size_t c = (size_t)s[i-1];
            sa[bin[c] + cnt[c]] = i-1;
            cnt[c]++;
        } 

        fill(cnt.begin(), cnt.end(), 0);
        auto lmsitr = lms.rbegin();

        //step3:S型のsuffixを埋めていく
        for (auto itr=sa.rbegin(); itr!=sa.rend(); itr++) {
            size_t i = *itr;
            if (i == 0) continue;
            if (isLMS(i)) { // ここでlmsをsaに出てくる順に並べ替えておく
                *lmsitr = i;
                lmsitr++;
            }
            if (isL[i-1]) continue;
            size_t c = (size_t)s[i-1];
            cnt[c]++;
            sa[bin[c+1] - cnt[c]] = i-1;
        }
    }
};

#include <functional>
#include <limits>

// i番目をxにかえるだけの関数(点更新のデフォルト) (i++はwarnig回避)
#define CHANGE_I [](int i, T x) { i++; return x; }
// i番目にxたす
#define ADD(sg) [&](int i, T x) { return sg[i] + x; }

template <typename T>
class SegmentTree {
    int n;                       // 葉の数
    T def;                 // 初期値 && 単位元
    vector<T> tree;              // 本体 
    function<T(T, T)> operation_f; // 区間クエリで使う処理
    function<T(int, T)> update_f;  // 点更新で使う処理 ただの変更の他、i番目にxをたすみたいなこともできる

    // 区間[a, b)の総和(と言うか総operation(は？))
    // ノードk=[l, r)を見ている
    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def;            // 全く交差しない場合
        if (a <= l && r <= b) return tree[(size_t)k]; // 完全に包含される場合
        T vl = _query(a, b, k * 2 + 1, l, (l + r) / 2),
          vr = _query(a, b, k * 2 + 2, (l + r) / 2, r);
        return operation_f(vl, vr);
    }

  public:
    SegmentTree(int _n, T _def, function<T(T, T)> _operation_f, function<T(int, T)> _update_f = CHANGE_I)
        : def(_def), operation_f(_operation_f), update_f(_update_f)  {
        n = 1;
        while (n < _n) n <<= 1;
        tree = vector<T>((size_t)(2*n - 1), def);
    }

    //よく使うやつら min, max, sum
    SegmentTree(int _n, T _def, string mode, function<T(int, T)> _update_f = CHANGE_I)
        : SegmentTree(
            _n, 
            _def,
            mode == "max" ? [](T l, T r) { return max(l, r); } :
           (mode == "min" ? [](T l, T r) { return min(l, r); } :
                            [](T l, T r) { return l + r; }), // sum
            _update_f
        ) {}

    SegmentTree(int _n, string mode, function<T(int, T)> _update_f = CHANGE_I)
        : SegmentTree(
            _n, 
            mode == "max" ? numeric_limits<T>::lowest() : 
           (mode == "min" ? numeric_limits<T>::max() :
                            0), // sum
            mode,
            _update_f
        ) {}

    template <typename ID>
    void update(ID i, T x) {
        T next_i = update_f((int)i, x);
        i += (ID)n - 1;
        tree[(size_t)i] = next_i;
        while (i > 0) {
            i = (i - 1) / 2;
            tree[(size_t)i] = operation_f(tree[(size_t)(i * 2 + 1)], tree[(size_t)(i * 2 + 2)]);
        }
    }

    template <typename ID1, typename ID2>
    T query(ID1 a, ID2 b) { return _query((int)a, (int)b, 0, 0, n); }

    void print_tree() {
        size_t next = 0, size = (size_t)(2 * n - 1);
        for (size_t i=0; i<size; i++) {
            cout << tree[i];
            if (i == next) {
                cout << '\n';
                next = (next + 1) * 2;
            } else 
                cout << string(size * 2 / (next+2), ' ');
        }
    }

    auto begin() { return tree.begin() + n - 1; }
    auto end() { return tree.end(); }

    T operator[](int i) { return tree[ (size_t)(i + n - 1) ]; }
};
/*
コンストラクタ
SegmentTree(n, def, op_func, [up_func])
SegmentTree(n, def, mode, [up_func])
SegmentTree(n, mode, [up_func])
*/

int main() {
    int n;
    string s;
    cin >> n >> s;
    SuffixArray<char> sa(s);
    SegmentTree<int> sg(n, "min");
    sa.construct_lcp();
    int i=0;
    for (auto &li:sa.lcp)
        sg.update(i++, li);
    int ans = 0;
    for (int i=0; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            ans = max(ans, min(abs(sa[i] - sa[j]), sg.query(i, j)));
        }
    }
    cout << ans << '\n';
    return 0;
}
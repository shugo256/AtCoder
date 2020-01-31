#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#include <limits>
#include <numeric>
#define isLMS(i) (isL[(i)-1] && !isL[i])

// sa_is()でしか使わない配列isLをlongest_match()においてrank配列として再利用
#define rank(i) (isL[(i)]) 


template <typename T>
class Suffix_Array {
    vector<T> s;
    const size_t len,
        		 limit;  // lenは配列長 limitは配列に登場する文字/数字の種類数
    vector<size_t> bin,  // 頭文字の各アルファベットの出現回数の累積和
				   cnt,  // どのアルファベットから始まるものをいくつsaに割り当てたか
				   lms,  // LMSのインデックスを格納する配列
                   isL;  // s[i]がL型なら1 S型なら0

public:
    vector<size_t> sa;  // sのsuffix arrayをインデックスで格納する配列

    Suffix_Array(vector<T> s, size_t limit = numeric_limits<T>::max())
	 : s(s),
       len(s.size()),
	   limit(limit),
	   bin(limit+1, 0),
	   cnt(limit+1, 0),
	   isL(len+1),
       sa(len+1) { 
           (this->s).push_back(0); // 末尾に番兵の追加
           lms.reserve(len/2);     // lmsの領域の確保
    } 

    //SA-IS法によりSuffixArrayを構築する
    void sa_is() {
		isL[len] = false;
        bin[1] = 1;
		for (size_t i=len; i>0; i--) {
            isL[i-1] = (s[i-1] == s[i]) ? isL[i] : (s[i-1] > s[i]);
            bin[s[i-1]+1]++;
            if (isLMS(i))
                lms.push_back(i);
		}

        if (lms.size() == 0) {
            iota(sa.begin(), sa.end(), 0);
            return;
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
            Suffix_Array<size_t> next(next_s, n+1);
            next.sa_is();

            for (size_t i=0; i<lmslen-1; i++)
                lms[i] = aligned[next.sa[lmslen-1-i]];
            lms[lmslen-1] = len;
        } else {
            for (auto i:aligned) 
                sa[i] = 0; // saを0リセット
        }

        fill(cnt.begin(), cnt.end(), 0);

        induced_sort();
	}

    // LCPからi, j, kの値を求め、引数の各ポインタに格納する
    void longest_match(size_t *ibest, size_t *jbest, size_t *kbest) {
        for (size_t i=0; i<=len; i++)
            rank(sa[i]) = i;
        size_t k = 0;
        for (size_t i=0; i<len; i++) {
            size_t j = sa[rank(i) - 1];
            if (k > 0) k--;
            for ( ; i+k<len && j+k<len && s[i+k] == s[j+k]; k++);
            if (k > *kbest) {
                *ibest = min(i, j);
                *jbest = max(i, j);
                *kbest = k;
            }
        }
    }

private:

    // induced sortの3ステップを行う
    void induced_sort() {

        // step1:LMSをひとまず書き込んでいく
        for (auto i:lms) {
            T c = s[i];
            cnt[c+1]++;
            sa[bin[c+1] - cnt[c+1]] = i;
        }

        fill(cnt.begin(), cnt.end(), 0);

        //step2:L型のsuffixを埋めていく
        for (auto i:sa) {
            if (i == 0 || !isL[i-1]) continue;
            T c = s[i-1];
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
            T c = (T)s[i-1];
            if (c+1 > limit) cerr << c+1 << ' ' << limit;
            cnt[c]++;
            sa[bin[c+1] - cnt[c]] = i-1;
        }
    }
};

#include <map>
#include <set>
// vecのなかの全要素について座標圧縮を行い、元座標->圧縮後座標というmapを作る
// O(NlogN) 座圧後のサイズを返す
// org: もともとの各iに対する座標 値渡しなので破壊しません
// zip: 圧縮
// unzip: 復元
template <typename T>
int compress(vector<T> org, map<T, int> &zip, vector<T> &unzip) {
    sort(org.begin(), org.end()); 
    org.erase(unique(org.begin(), org.end()), org.end()); // vecの各要素を小さい順に重複を無くして並べたもの
    int i = 0;
    for (auto &oi : org) {
        zip[oi] = i;
        unzip.push_back(oi);
        i++;
    }
    return i;
}

using P = pair<int, ll>;
#define fi first
#define se second

int main() {
    int n;
    cin >> n;
    ll a[n], b[n];
    for (auto &ai:a) cin >> ai;
    for (auto &bi:b) cin >> bi;
    vector<ll> as(2*n), bs(n);
    for (int i=0; i<n; i++) {
        as[i] = as[i+n] = a[i] ^ a[(i+1) % n];
        bs[i] = b[i] ^ b[(i+1) % n];
    }
    map<ll, int> zip;
    vector<ll> unzip, asa(2*n);
    int m = compress(as, zip, unzip);
    for (int i=0; i<2*n; i++) {
        asa[i] = zip[as[i]]+1;
    }
    Suffix_Array<ll> sa(asa, m+2);
    sa.sa_is();
    auto lb = partition_point(sa.sa.begin(), sa.sa.end(), [&](size_t k) {
        for (int i=0; i<n; i++) {
            if (k+i >= 2*n || as[k+i] < bs[i]) return true;
            if (as[k+i] > bs[i]) return false;
        }
        return false;
    });
    auto ub = partition_point(sa.sa.begin(), sa.sa.end(), [&](size_t k) {
        for (int i=0; i<n; i++) {
            if (k+i >= 2*n || as[k+i] < bs[i]) return true;
            if (as[k+i] > bs[i]) return false;
        }
        return true;
    });
    vector<P> ans;
    for (auto itr=lb; itr!=ub; itr++) {
        int k = (int)*itr;
        if (k < n)
            ans.push_back({k, a[k] ^ b[0]});
    }
    sort(ans.begin(), ans.end());
    for (auto &p:ans) cout << p.fi << ' ' << p.se << '\n';
    return 0;
}
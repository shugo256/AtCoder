#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>

using ll = long long;

using namespace std;

using P = pair<long, long>;
#define fi first
#define se second

#define MAX 1000000000l
#define INF 1000000001l

long pow(long n, long k) {
    if (k <= 0 || n == 1) return 1;
    if (k >= 30) return INF;
    long root = pow(n, k/2),
         rr = root * root,
         odd = (k % 2 ? n : 1),
         val = (rr < INF / odd ? rr * odd : INF);
    return val;
}

int main() {
    int n;
    cin >> n;
    long a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    long l = 0, r = MAX;
    while (r - l > 1) {
        long m = (l + r + 1) / 2;
        stack<P> st;
        st.push({0, 0});
        bool under;
        for (auto &ai:a) {
            P next = st.top(),
              tp = next;
            st.pop();
            under = false;
            while (ai < tp.fi) {
                under = true;
                next = st.top();
                if (next.fi < ai) {
                    next = P{ai, 1};
                    st.push(next);
                }
                // cerr << tp.fi << ' ' << tp.se << '\n';
                long p = pow(m, tp.fi - next.fi);
                tp.se = (tp.se + p - 1) / p - 1;
                tp.fi = next.fi;
                tp.se += next.se;
                st.pop();
                // cerr << tp.fi << ' ' << tp.se << '\n';
            }
            st.push(tp);
            if (ai == tp.fi) {
                st.pop();
                tp.se++;
                st.push(tp);
            }
            else { // ai > tp.fi
                st.push({ai, 1 + under});
            }
        }
        P next = st.top(),
          tp = next;
        st.pop();
        while (tp.fi > 0) {
            // cerr << tp.fi << ' ' << tp.se << '\n';
            next = st.top();
            long p = pow(m, tp.fi - next.fi);
            tp.se = (tp.se + p - 1) / p - 1;
            tp.fi = next.fi;
            tp.se += next.se;
            st.pop();
        }
        // cerr << tp.se << ' ' << l << ' ' << m << ' ' << r << '\n';
        if (tp.se > 0) l = m;
        else r = m;
    }
    cout << r << '\n';
    return 0;
}
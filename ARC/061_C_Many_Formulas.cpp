#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;

//深さ優先 サンプルでは上手くいくが、なぜかRE
long long formula(size_t j, string s, stack<int> st) {
    while(!st.empty()) {
        if (st.top() == 1) {
            st.pop();
            return formula(j-1,s.substr(0,j),st) + stoll(s.substr(j));
        }
        st.pop();
        j--;
    }
    return stoll(s);
}
long long dfs(size_t i, size_t l, string s, stack<int> st, long long sum) {
    if (i == l-1) {
        sum += formula(l-1,s,st);
        if (st.top() == 1) {
            i--;
            st.pop();
            while (st.top() == 1) {
                i--;
                st.pop();
                if (i == 0) return sum;
            }
        }
        i--;
        st.pop();
        st.push(1);
    } else {
        st.push(0);
    }
    return dfs(i+1, l, s, st, sum);
}

int main() {
    string s;
    cin >> s;
    size_t l = s.length();
    stack<int> st;
    printf("%lld\n",dfs(0,l,s,st,0));
    return 0;
}
#include <cstdio>
#include <stack>
using namespace std;

//深さ優先 

bool dfs(int i, int sum, int n[4], stack<int> st) {
    if (i == 4) {
        if (sum == 7) {
            char f[] = "0123456=7";
            for (i=0; i<4; i++) {
                f[2*i] = (char)n[i] + '0';
                if (i < 3) {
                    f[5-2*i] = (st.top() == 1) ? '+' : '-';
                    st.pop();
                }
            }
            printf("%s\n",f);
            return true;
        } else 
            return false;
    } else {
        st.push(1);
        if (dfs(i+1, sum+n[i], n, st))
            return true;
        else {
            st.pop();
            st.push(-1);
            return dfs(i+1, sum-n[i], n, st);
        }
    }
}

int main() {
    char s[5];
    int n[4];
    scanf("%s",s);
    stack<int> st;
    for (int i=0; i<4; i++) {
        n[i] = s[i] - '0';
    }
    dfs(1,n[0],n,st);
    return 0;
}
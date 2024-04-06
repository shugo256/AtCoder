#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

#define MAX_N 100

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int b[N], ans[MAX_N] = {0};
    vector<int> bvec;
    for (int i=0; i<N; i++) {
        scanf("%d", b+i);
        bvec.push_back(b[i]);
    }
    sort(b, b+N, greater<int>());
    for (int i=0; i<N; i++) {
        int a = b[i], n = (int)(bvec.rend() - find(bvec.rbegin(), bvec.rend(), a)) - 1;
        bvec.erase(bvec.begin() + n);
        int count = 0;
        bool inserted = false;
        for (int j=N-1; j>=0; j--) {
            if (ans[j] != 0) continue;
            if (count == n - a + 1) {
                ans[j] = a;
                inserted = true;
                break;
            }
            count++;
        }
        if (!inserted) {
            printf("-1\n");
            return 0;
        }
    }
    for (int i=0; i<N; i++) printf("%d\n", ans[i]);
    return 0;
}
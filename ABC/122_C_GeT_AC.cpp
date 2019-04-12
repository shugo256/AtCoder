#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    vector<int> acs;
    bool a;
    scanf("%d %d", &N, &Q); getchar();
    for (int i=0; i<N; i++) {
        int c = getchar();
        if (a && c == 'C') acs.push_back(i-1);
        if (c == 'A') a = true;
        else a = false;
    }
    for (int i=0; i<Q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        auto first = lower_bound(acs.begin(), acs.end(), l-1),
             last = lower_bound(acs.begin(), acs.end(), r-1);
        printf("%ld\n", last - first);
    }
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <deque>
#include <functional>

#define MAX_N 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

bool greatersecond(const P& left, const P& right) {
    return left.second > right.second;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    deque<P> uma;
    int t, d, i;
    for (i = 0; i < N; i++) {
        scanf("%d %d", &t, &d);
        uma.push_back({t, d});
    }
    sort(uma.begin(), uma.end(), greatersecond);
    bool used[MAX_N+1] = {0};
    ll sum=0;
    int var=0;
    for (i = 0; i < N; i++) {
        if (i < K) sum += uma[i].second;
        if (used[ uma[i].first ]) {
            uma[i].first = 0;
        } else {
            if (i < K) var++;
            used[ uma[i].first ] = true;
            uma[i].first = 1;
        }
    }
    ll max = sum + (ll)var*var;
    int j = K-1, k = K;
    for (i = var+1; i <= K; i++) {
        for ( ; j >= 0 && uma[j].first; j--);
        for ( ; k < N && !uma[k].first; k++);
        if (j < 0 || k >= N) break;
        sum += -uma[j].second + uma[k].second;
        j--; k++;
        if (max < sum + (ll)i*i) max = sum + (ll)i*i;
    }
    printf("%lld\n",max);
    return 0;
}
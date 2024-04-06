#include <cstdio>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, int> pii;

bool sumComp(const pii &left, const pii &right) {
    return (long)left.first + (long)left.second >= (long)right.first + (long)right.second;
}

int main()
{
    int N, A, B;
    scanf("%d",&N);
    long P[N];
    long sum = 0;
    for (int i=0; i<N; i++) {
        scanf("%d %d", &A, &B);
        P[i] = A + B;
        sum -= B;
    }
    sort(P,P+N,greater<int>());
    for (int i=0; i<N; i++) {
        if (i%2 == 0) sum += P[i];
    }
    printf("%ld\n",sum);
    return 0;
}
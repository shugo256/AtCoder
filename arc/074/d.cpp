#include <cstdio>
#include <queue>
#include <vector>

#define INF (long)1e15
#define MAX_N 100000

using namespace std;

int main() {
    int N, a;
    scanf("%d", &N);
    priority_queue<int, vector<int>, greater<int>> first;
    int second[N];
    priority_queue<int> third;
    long sum1 = 0, sum3 = 0;
    for (int i=0; i<3*N; i++) {
        scanf("%d", &a);
        if (i < N) {
            first.push(a);
            sum1+=a;
        } else if (i < 2*N) {
            second[i-N] = a;
        } else {
            third.push(a);
            sum3+=a;
        }
    }
    long score[MAX_N+1] = {0};
    score[0] = sum1; score[N] = -sum3;
    for (int i=1; i<=N; i++) {
        int a1 = second[i-1],   a3 = second[N-i];
        first.push(a1);       third.push(a3);
        int b1 = first.top(), b3 = third.top();
        first.pop();          third.pop();
        sum1 += a1 - b1;      sum3 += a3 - b3;
        score[i] += sum1;     score[N-i] -= sum3;
    }
    long best = -INF;
    for (int i=0; i<=N; i++) best = max(best, score[i]);
    printf("%ld\n", best);
    return 0;
}
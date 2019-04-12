#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, i, bigger=0, smaller=0;
    scanf("%d",&N);
    int A[N], D[N], B;
    long sum=0;
    for (i=0; i<N; i++) 
        scanf("%d",&A[i]);
    for (i=0; i<N; i++) {
        scanf("%d",&B);
        D[i] = A[i] - B;
        if (A[i] < B) {
            sum += B - A[i];
            smaller++;
        }
    }
    sort(D, D+N, greater<int>());
    while (sum > 0) {
        if (D[bigger] <= 0) {
            printf("-1\n");
            return 0;
        }
        sum -= D[bigger];
        bigger++;
    }
    printf("%d\n",bigger+smaller);
    return 0;
}
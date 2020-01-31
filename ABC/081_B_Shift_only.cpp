#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int N, i;
    scanf("%d",&N);
    int A[N];
    for (i=0; i<N; i++) {
        scanf("%d",&A[i]);
    }
    int end=0, ans=0;
    while(!end) {
        for (i=0; i<N; i++) {
            if (A[i] % 2 == 0) {
                A[i] /= 2;
            } else {
                end = 1;
                ans -= 1;
                break;
            }
        }
        ans += 1;
    }
    cout << ans << "\n";
}
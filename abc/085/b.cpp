#include <cstdio>


int main() {
    int N;
    scanf("%d",&N);
    int d[N], used[N], count=0;
    for (int i=0; i<N; i++) {
        scanf("%d",&d[i]);
        used[count] = d[i];
        count++;
        for (int j=0; j<count-1; j++) {
            if (d[i] == used[j]) {
                count--;
                used[count] = 0;
                break;
            }
        }
    }
    printf("%d\n",count);
}
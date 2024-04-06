#include <cstdio>
#include <cstring>
#include <algorithm>

int main() {
    int N, i, j;
    scanf("%d", &N);
    int h[N], sorted[N+1];
    for (i = 0; i < N; i++) scanf("%d", &h[i]);
    memcpy(sorted, h, sizeof(int)*(size_t)N);
    sorted[N] = 0;
    std::sort(sorted, sorted+N+1);
    int sum=0, count;
    bool cut;
    for (i = 0; i < N; i++) {
        cut = true;
        count = 0;
        for (j = 0; j < N; j++) {
            if (h[j] - sorted[i] <= 0)
                cut = true;
            else if (cut) {
                cut = false;
                count++;
            }
        }
        sum += count * (sorted[i+1] - sorted[i]);
    }
    printf("%d\n", sum);
    return 0;
}
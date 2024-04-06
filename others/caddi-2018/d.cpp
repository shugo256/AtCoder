#include <cstdio>

//全部偶数の場合は後手は先手の手をパクれば必勝
//一つでも奇数あれば、先手は初ターンで奇数のところ全部取った後に後手をパクれば必勝

int main() {
    int N, a;
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        scanf("%d",&a);
        if (a % 2 == 1) {
            printf("first\n");
            return 0;
        }
    }
    printf("second\n");
    return 0;
}
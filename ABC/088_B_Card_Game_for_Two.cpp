#include <cstdio>
#include <cstring>

void merge(const int al, const int bl, int a[], int b[], int result[]) {
    if (al == 0) {
        memcpy(result,b,sizeof(int) * (size_t)bl);
    } else if (bl == 0) {
        memcpy(result,a,sizeof(int) * (size_t)al);
    } else if (a[0] > b[0]) {
        result[0] = a[0];
        merge(al-1,bl,a+1,b,result+1);
    } else {
        result[0] = b[0];
        merge(al,bl-1,a,b+1,result+1);
    }
}

void mergesort(int l, int result[]) {
    if (l > 1) {
        int al=l/2, bl=l-al;
        int a[al], b[bl];
        memcpy(a,result,sizeof(int) * (size_t)al);
        memcpy(b,result+l/2,sizeof(int) * (size_t)bl);
        mergesort(al,a);
        mergesort(bl,b);
        merge(al,bl,a,b,result);
    }
}
int main() {
    int N, i;
    scanf("%d",&N);
    int a[N];
    for (i=0; i<N; i++) {
        scanf("%d",&a[i]);
    }
    mergesort(N,a);
    int m=1,dif=0;
    for (i = 0; i<N; i++) {
        dif += m*a[i];
        m = -m;
    }
    printf("%d\n",dif);
}
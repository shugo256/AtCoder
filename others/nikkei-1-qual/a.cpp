#include <cstdio>
#include <algorithm>

int main() {
    int N, A, B;
    scanf("%d %d %d",&N,&A,&B);
    
    printf("%d %d\n",std::min(A,B),std::max(A+B-N,0));
    return 0;
}
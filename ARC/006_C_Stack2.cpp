#include <iostream>
#include <algorithm>

using namespace std;

//

int main() {
    int bottom,max,stacks=0;
    size_t N,i,j,max_i,is=0;
    scanf("%zd",&N);
    int w[N], sorted[N];
    for (i=0; i<N; i++) {
        scanf("%d",&w[i]);
        sorted[i] = w[i];
    }
    sort(sorted,sorted+N,greater<int>());
    while(is < N) {
        stacks++;
        bottom = sorted[is]; //今から作る山の一番下。
        while(sorted[++is] == 0 && is < N);
        for (i=0; w[i]!=bottom; i++);
        w[i] = 0;
        while (is < N && i < N) {
            max = 0;
            for (j=i+1; j<N; j++) {
                if(w[j] == 0) continue;
                if (w[j] == sorted[is]) {
                    while(sorted[++is] == 0 && is < N);
                    w[j] = 0;
                    i=j; //->41行目
                    break;
                } else if (w[j] > max) {
                    max = w[j];
                    max_i = j;
                }    
            }
            if (j >= N && max == 0) break;
            if (i == j) continue;
            i = max_i;
            sorted[max_i] = 0;
            w[i] = 0;
        }
    }
    printf("%d\n",stacks);
    return 0;
}
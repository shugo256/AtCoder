#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

//REうえーーーい　と思いきや単なるミステイク　クリア！！

int main() {
    int bottom,max,stacks=0;
    size_t N,i,j,max_i;
    scanf("%zd",&N);
    deque<int> w(N), sorted(N);
    for (i=0; i<N; i++) {
        scanf("%d",&w[i]);
        sorted[i] = w[i];
    }
    sort(sorted.begin(),sorted.end(),greater<int>());
    while(N > 0) {
        stacks++;
        bottom = sorted.front(); sorted.pop_front(); //今から作る山の一番下。
        for (i=0; w[i]!=bottom; i++);
        w.erase(w.begin()+(long)i);
        N--;
        while (N > 0 && i < N) {
            max = 0;
            for (j=i; j<N; j++) {
                if (w[j] == sorted.front()) {
                    sorted.pop_front();
                    w.erase(w.begin()+(long)j);
                    N--;
                    i=j; //->43行目
                    break;
                } else if (w[j] > max) {
                    max = w[j];
                    max_i = j;
                }    
            }
            if (j >= N && max == 0) break;
            if (i == j) continue;
            i = max_i;
            sorted.erase( find(sorted.begin(),sorted.end(),max) );
            w.erase(w.begin()+(long)i);
            N--;
        }
    }
    printf("%d\n",stacks);
    return 0;
}
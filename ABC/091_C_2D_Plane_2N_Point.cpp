#include <cstdio>
#include <algorithm>
#include <utility>

#define NO -1

using namespace std;

int main() {
    int N, i, j;
    scanf("%d",&N);
    pair<int,int> red[N], blue[N];
    for (i=0; i<N; i++) scanf("%d %d",&red[i].first,&red[i].second);
    for (i=0; i<N; i++) scanf("%d %d",&blue[i].first,&blue[i].second);
    sort(red,red+N);
    sort(blue,blue+N);
    int count=0, max=NO, max_j;
    for (i=0; i<N; i++) {
        for (j=0; red[j].first < blue[i].first && j<N; j++) {
            if (red[j].first != NO && red[j].second < blue[i].second && red[j].second > max) {
                max = red[j].second;
                max_j = j;
            }
        }
        if (max != NO) {
            max = NO;
            red[max_j].first = NO;
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
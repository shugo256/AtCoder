#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

//TLE!!!!!!!!!!!!!!!!!!!!!!!!!
int dfs(int i, int num, int sum, int D, int G, int p[], int c[]) {
    if (sum >= G) {
        return num;
    } else if (i == D) {
        return 1000;
    } else {
        int min=dfs(i+1, num+p[i], sum+100*(i+1)*p[i]+c[i], D, G, p, c);
        int num_j, sum_j;
        for (int j=0; j<=p[i]; j++) {
            if (num + j >= min) break;
            if (j < p[i])
                sum_j = sum+100*(i+1)*j;
            else 
                sum_j = sum+100*(i+1)*p[i]+c[i];
            num_j = dfs(i+1, num+j, sum_j, D, G, p, c);
            if (num_j < min) {
                min = num_j;
            }
            if (sum_j >= G) break;
        }
        return min;
    }
}

int main() {
    int D, G;
    scanf("%d %d",&D,&G);
    int p[D],c[D];
    for (int i=0; i<D; i++) {
        scanf("%d %d",&p[i],&c[i]);
    }
    printf("%d\n",dfs(0,0,0,D,G,p,c));
}
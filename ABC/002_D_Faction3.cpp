#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

//改良したにも関わらず10ms... 殺すぞ Fraction2の方が早い

size_t N,M;

int dfs(size_t i, int num, vector<vector<bool>> relation, bool member[]) {
    if (i == N) {
        return num;
    } else {
        member[i] = false;
        int a = dfs(i+1,num,relation,member), b=0;
        size_t j;
        for (j=0; j<=i; j++) {
            if (member[j] && !relation[i][j]) {//jがメンバーで、jとiが知り合いじゃないなら
                break;
            }
            if (j == i) { //最後まできたら
                member[i] = true;
                b = dfs(i+1,num+1,relation,member);
            }
        }
        return max(a,b);
    }
}

int main() {
    scanf("%zu %zu",&N,&M);
    size_t xi,yi,i;
    bool member[N];
    vector<vector<bool>> relation(N,vector<bool>(N));
    for (i=0; i<M; i++) {
        scanf("%zu %zu",&xi,&yi);
        relation[xi-1][yi-1] = true;
        relation[yi-1][xi-1] = true;
    }
    printf("%d\n",dfs(0,0,relation,member));
}
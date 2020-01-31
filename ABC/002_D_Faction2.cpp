#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

//改良したにも関わらず5ms... 殺すぞ
size_t N,M;

int dfs(size_t i, int num, vector<vector<int>> relation, bool member[]) {
    if (i == N) {
        return num;
    } else {
        member[i] = false;
        int a = dfs(i+1,num,relation,member), b=0;
        size_t j;
        bool irel[i];
        for (j=0;j<i;j++) irel[j] = false;
        for (j=0; j<relation[i].size(); j++) {
            if (relation[i][j] < (int)i)
                irel[relation[i][j]] = true;
        }
        for (j=0; j<=i; j++) {
            if (member[j] && !irel[j]) {//jがメンバーで、jとiが知り合いじゃないなら
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
    scanf("%zd %zd",&N,&M);
    int xi,yi;
    size_t i;
    bool member[N];
    vector<vector<int>> relation(N);
    for (i=0; i<M; i++) {
        scanf("%d %d",&xi,&yi);
        relation[(size_t)xi-1].push_back(yi-1);
        relation[(size_t)yi-1].push_back(xi-1);
    }
    printf("%d\n",dfs(0,0,relation,member));
}
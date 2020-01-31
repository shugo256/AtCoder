#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

//一発クリアだが、6msだったので、改善の余地あり

int N,M;

int dfs(int i, int num, vector<vector<int>> relation, bool member[]) {
    if (i == N) {
        return num;
    } else {
        member[i] = false;
        int a = dfs(i+1,num,relation,member), b=0;
        for (int j=0; j<=i; j++) {
            if (member[(size_t)j] && relation[(size_t)j].end() == find(relation[(size_t)j].begin(),relation[(size_t)j].end(),i)) {//relation[j]にiがいないなら
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
    scanf("%d %d",&N,&M);
    int xi,yi;
    bool member[N];
    vector<vector<int>> relation((size_t)N);
    for (int i=0; i<M; i++) {
        scanf("%d %d",&xi,&yi);
        relation[(size_t)xi-1].push_back(yi-1);
        relation[(size_t)yi-1].push_back(xi-1);
    }
    printf("%d\n",dfs(0,0,relation,member));
}
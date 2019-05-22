#include <cstdio>
#include <vector>

struct UnionFind {
    std::vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    const int n;
    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        n = N;
        for(int i = 0; i < N; i++) par[i] = i;
    }
};


int main() {
    int a = 0, b = 2;

    printf("%d\n",a^b);
}
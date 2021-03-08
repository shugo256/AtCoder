#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <atcoder/maxflow>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int count_around(int i, int j, int n, int val, std::vector<std::vector<int>> &c) {
    int ans = 0;
    for (int x=std::max(i-1, 0); x<=std::min(i+1, n-1); x++) {
        for (int y=std::max(j-1, 0); y<=std::min(j+1, n-1); y++) {
            if (x != i && y != j) continue;
            if (x == i && y == j) continue;
            if (c[x][y] == val) ans++;
        }
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector c(n, std::vector(n, 0));
    int max =  n * (n - 1) * 2;
    for (int i=0; i<n; i++) {
        std::string s; std::cin >> s;
        for (int j=0; j<n; j++) {
            if (s[j] == 'B') 
                c[i][j] = 1;
            else if (s[j] == 'W') 
                c[i][j] = 2;
            if (c[i][j] > 0){
                max -= count_around(i, j, n, c[i][j], c);
            }
        }
    }
    atcoder::mf_graph<int> graph(n * n + 2);
    const int start = n * n;
    const int goal = start + 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (c[i][j] > 0) continue;
            int in = 1, out = 2;
            if ((i + j) % 2) std::swap(in, out);
            graph.add_edge(start, i * n + j, count_around(i, j, n, in, c));
            graph.add_edge(i * n + j, goal, count_around(i, j, n, out, c));
            if (i > 0 && c[i-1][j] == 0) {
                graph.add_edge((i-1) * n + j, i * n + j, 1);
                graph.add_edge(i * n + j, (i-1) * n + j, 1);
            }
            if (j > 0 && c[i][j-1] == 0) {
                graph.add_edge(i * n + (j-1), i * n + j, 1);
                graph.add_edge(i * n + j, i * n + (j-1), 1);
            }
        }
    }
    std::cout << max - graph.flow(start, goal) << '\n';
    return 0;
}
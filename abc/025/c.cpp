#include <cstdio>
#include <algorithm>

#define INF 10000

using namespace std;

int b[2][3], c[3][2], board[3][3] = {{0}};

int dfs(int n) {
    if (n == 9) {
        int score = 0;
        for (int i=0; i<2; i++) {
            for (int j=0; j<3; j++) {
                if (board[i][j] == board[i+1][j]) score += b[i][j];
                else score -= b[i][j];
            }
        }
        for (int i=0; i<3; i++) {
            for (int j=0; j<2; j++) {
                if (board[i][j] == board[i][j+1]) score += c[i][j];
                else score -= c[i][j];
            }
        }
        return score;
    }
    else {
        int a = n%2 ? -1 : 1, best = -a*INF;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (board[i][j] != 0) continue;
                board[i][j] = a;
                best = a * max(a*dfs(n+1), a*best);
                board[i][j] = 0;
            }
        }
        return best;
    }
}

int main() {
    int sum=0;
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            scanf("%d", &b[i][j]);
            sum += b[i][j];
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<2; j++) {
            scanf("%d", &c[i][j]);
            sum += c[i][j];
        }
    }
    int score = dfs(0);
    printf("%d\n%d\n", (sum+score)/2, (sum-score)/2);
    return 0;
}
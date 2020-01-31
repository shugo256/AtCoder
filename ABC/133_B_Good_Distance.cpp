#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int n, d;
int x[10][10];
bool good(int i, int j) {
    int sum = 0;
    for (int k=0; k<d; k++) {
        int dif = x[i][k] - x[j][k];
        sum += dif * dif;
    }
    int root = (int)sqrt(sum);
    cerr << root << ' ' << sum << '\n';
    return sum == root * root;
}

int main() {
    cin >> n >> d;
    for (int i=0; i<n; i++) {
        for (int j=0; j<d; j++) {
            cin >> x[i][j];
        }
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (good(i, j)) cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}

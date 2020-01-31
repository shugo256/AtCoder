#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define long long long

using namespace std;

#define MAX_N 600

int a[MAX_N][MAX_N];

void set_levels(int s, int e) {
    if (e - s < 3) return;
    int now = a[s][s],
        m = (s + e) / 2;
    for (int i=s; i<m; i++)
        for (int j=s; j<m; j++)
            a[i][j] = now+1;
    for (int i=m; i<e; i++)
        for (int j=m; j<e; j++)
            a[i][j] = now+1;
    set_levels(s, m);
    set_levels(m, e);
}


int main() {
    int n;
    cin >> n;
    fill(a[0], a[n], 1);
    set_levels(0, n);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            cout << a[i][j] << (j == n-1 ? '\n' : ' ');
        }
    }
    return 0;
}
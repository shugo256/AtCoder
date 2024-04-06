#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int,int> P;

int main() {
    int n;
    cin >> n;
    P a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a+n);
    int cnt = 0;
    for (int i=0; i<n; i++)
        if (a[i].second%2 != i%2) 
            cnt++;
    cout << cnt / 2 << '\n';
    return 0;
}
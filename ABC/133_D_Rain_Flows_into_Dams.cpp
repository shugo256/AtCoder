#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    int n;
    cin >> n;
    long a[n];
    long sum = 0, others=0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
        if (i%2) others += a[i];
    }
    long prev = sum - others*2;
    for (int i = 0; i < n - 1; i++) {
        cout << prev << ' ';
        prev = a[i] * 2 - prev;
    }
    cout << prev << '\n';
    return 0;
}

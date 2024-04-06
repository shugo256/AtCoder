#include <iostream>
#include <algorithm>

#define MAX_N 200010

using namespace std;

int main() {
    int n;
    cin >> n;
    int appear[MAX_N]={0}, longest=0;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        appear[p] = appear[p-1] + 1;
        longest = max(appear[p], longest);
    }
    cout << n - longest << '\n';
    return 0;
}
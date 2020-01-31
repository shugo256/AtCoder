#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define MAX 250000
#define ROOT 500

// 平方分割ver

int data[MAX] = {0},
    bucket[ROOT] = {0};

int main() {
    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            data[x] = 1;
            bucket[x / ROOT]++;
        }
        else {
            int b=0, d=0;
            for ( ; x > bucket[b]; b++)
                x -= bucket[b];
            for ( ; x > data[d + b * ROOT]; d++)
                x -= data[d + b * ROOT];
            data[d + b * ROOT] = 0;
            bucket[b]--;
            cout << d + b * ROOT << '\n';
        }
        //cerr << bucket[0] << '\n';
    }
    return 0;
}
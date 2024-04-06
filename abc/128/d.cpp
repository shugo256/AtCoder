#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k1;
    cin >> n >> k1;
    int v[n], best = -100000000;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int k = 0; k <= k1; k++) {
        for (int i = 0; i <= k / 2; i++) {  // iは戻す宝石の数
            if (k - i > n) continue;
            for (int j = 0; j <= k - i; j++) {
                int front = 0, back = n - 1;
                priority_queue<int> pq;
                for (int l = 0; l < j; l++) {// jはfrontからとる宝石の数
                    pq.push(v[front]);
                    front++;
                }
                for (int l = 0; l < k - i - j; l++){
                    pq.push(v[back]);
                    back--;
                }
                int sum = 0;
                for (int l = 0; l < k - 2 * i; l++) {
                    //cerr << pq.top() << '\n';
                    sum += pq.top();
                    pq.pop();
                }
                best = max(best, sum);
                // cerr << i << ' ' << j << ' ' <<  sum << '\n';
            }
            
        }
    }
    cout << best << '\n';
    return 0;
}

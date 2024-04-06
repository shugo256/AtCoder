#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int main() {
    long n, k;
    cin >> n >> k;
    long a[n], amari[n], total=0;
    for (auto &ai:a) {
        cin >> ai;
        total += ai;
    }
    vector<long> insu;
    long root = sqrt(total);
    for (long i=1; i<=root; i++) {
        if (total % i) continue;
        insu.push_back(i);
        insu.push_back(total/i);
    }
    sort(insu.begin(), insu.end(), greater<long>());
    for (auto in:insu) {
        long sum = 0;
        for (int i=0; i<n; i++) {
            amari[i] = a[i] % in;
            sum += amari[i];
        }
        if (sum % in) continue;
        sort(amari, amari+n, greater<long>());
        long cnt = 0;
        for (int i=0; i<sum/in; i++)
            cnt += in - amari[i];
        if (cnt <= k) {
            cout << in << endl;
            return 0;
        }
    }
    return 0;
}
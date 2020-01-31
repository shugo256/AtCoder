#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long n;
    cin >> n;
    long a[n], sum=0;
    for (auto &ai:a) {
        cin >> ai;
        sum += ai;
    }
    long stare = n * (n+1) / 2;
    if (sum % stare) {
        cout << "NO" << '\n';
        return 0;
    }
    long layer = sum / stare,
         prev  = a[n-1];
    for (auto ai:a) {
        long step = prev - ai + layer;
        if (step < 0 || step % n) {
            cout << "NO" << '\n';
            return 0;
        }
        prev = ai;
    }
    cout << "YES" << '\n';
    return 0;
}
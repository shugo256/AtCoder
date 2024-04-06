#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>


using namespace std;

int main() {
    int n;
    cin >> n;
    int w[n], sum=0;
    for (auto &wi:w) {
        cin >> wi;
        sum += wi;
    }
    int s1=0, s2=sum, dif = sum;
    for (int i=0; i<n; i++) {
        s1 += w[i];
        s2 -= w[i];
        dif = min(dif, abs(s1-s2));
        //cerr << s1 << ' ' <<  s2 << '\n';
    }
    cout << dif << '\n';
    return 0;
}

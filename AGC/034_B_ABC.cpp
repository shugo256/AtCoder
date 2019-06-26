#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    string s;
    cin >> s;
    long a=0, cnt=0;
    bool b=false;
    for (auto si:s) {
        if (si == 'A') {
            a++;
            if (b) {
                a = 1;
            }
            b = false;
        } else if (a > 0 && si == 'B') {
            if (b) {
                a = 0;
            } else b = true;
        } else if (a > 0 && si == 'C') {
            if (b) {
                cnt += a;
                b = false;
            } else {
                a = 0;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}

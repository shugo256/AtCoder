#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

#define _IN_ << ' ' <<

using namespace std;

int main() {
    int n, a, b, c, d;
    string s;
    cin >> n >> s >> a >> b >> c >> d;
    if (count(s.begin(), s.end(), 'o') != a + b + c) {
        cout << "No\n";
        return 0;
    }
    bool prev = (s[0] == 'o');
    int buf = 1, both = 0, oxsum=0, xosum=0;
    vector<int> oxs, xos;
    s += *(s.end()-1);
    for (auto c:s) {
        bool now = (c == 'o');
        if (prev == now) {
            if (buf == 1) continue;
            if (buf%2)
                both += buf/2;
            else {
                if (now) {
                    xos.push_back(buf/2);
                    xosum += buf/2;
                } else {
                    oxs.push_back(buf/2);
                    oxsum += buf/2;
                }
            }
            buf = 1;
        } else
            buf++;
        prev = now;
    }
    int left;
    if ((left = oxsum-a) >= 0) {
        a = 0;
        b -= xosum+both;
        sort(oxs.begin(), oxs.end(), greater<int>());
        auto it = oxs.begin();
        while (b > 0 && left > 0) {
            int l = min(*it, left);
            b -= l-1;
            left -= l;
            it++;
        }
    } else if ((left = xosum - b) >= 0) {
        b = 0;
        a -= oxsum+both;
        sort(xos.begin(), xos.end(), greater<int>());
        auto it = xos.begin();
        while (a > 0 && left > 0) {
            int l = min(*it, left);
            a -= l - 1;
            left -= l;
            it++;
        }
    } else {
        both -= a - oxsum;
        a = 0;
        b -= xosum + both;
    }
    cout << (a <= 0 && b <= 0 ? "Yes" : "No") << "\n";
    return 0;
}
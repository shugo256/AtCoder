#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long h, w, k;
    cin >> h >> w >> k;
    long tate[h], yoko[w];
    fill(tate, tate+h, w);
    fill(yoko, yoko+w, h);
    for (int i=0; i<k; i++) {
        long r, c;
        cin >> r >> c;
        r--; c--;
        tate[r]--;
        yoko[c]--;
    }
    long koma=(h*w-k)/2, mi, mj;
    for (int i=0; i<h; i++) {
        if (koma >= tate[i]) koma -= tate[i];
        else {
            mi = i;
            break;
        }
    }
    koma = (h*w-k) / 2;
    for (int i=0; i<w; i++) {
        if (koma >= yoko[i]) koma -= yoko[i];
        else {
            mj = i;
            break;
        }
    }
    long sum=0;
    for (int i=0; i<h; i++) sum += abs(mi - i) * tate[i];
    for (int i=0; i<w; i++) sum += abs(mj - i) * yoko[i];
    //cerr << mi << ' ' << mj << endl;
    cout << sum << '\n';
    return 0;
}
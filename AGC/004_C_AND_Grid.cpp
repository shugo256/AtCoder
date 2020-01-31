#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;


int main() {
    int h, w;
    cin >> h >> w;
    vector<string> red(h, string(w, '.')), blue(h, string(w, '.'));
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            char c; cin >> c;
            if (c == '#')
                red[i][j] = blue[i][j] = '#';
            else if ((j < w-1 && i % 2 == 0) || j == 0)
                red[i][j] = '#';
            else 
                blue[i][j] = '#';
        }
    }
    for (auto r:red) cout << r << endl;
    cout << endl;
    for (auto b:blue) cout << b << endl;
    return 0;
}
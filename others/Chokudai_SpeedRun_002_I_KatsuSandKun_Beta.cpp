#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int,int> P;

int main() {
    int n;
    cin >> n;
    P foods[n], saikyo = {0, 1};
    int j = 1, saikyoid = 0;
    for (auto &f:foods) {
        cin >> f.first >> f.second;
        int champ = (saikyo.first + f.second - 1) / f.second,
            chall = (f.first + saikyo.second - 1) / saikyo.second;
        if (champ < chall) {
            saikyo = f;
            saikyoid = j;
        }
        j++;
    }
    j = 0;
    for (auto f : foods) {
        j++;
        if (j == saikyoid) continue;
        int champ = (saikyo.first + f.second - 1) / f.second,
            chall = (f.first + saikyo.second - 1) / saikyo.second;
        // cerr << champ << ' ' << chall << '\n';
        if (champ <= chall) {
            saikyoid = -1;
            break;
        }
    }
    cout << saikyoid << '\n';
    return 0;
}
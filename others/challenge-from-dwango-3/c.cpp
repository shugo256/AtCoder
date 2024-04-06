#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], total[5] = {0}, pass[5] = {0};
    for (auto &ai:a) {
        cin >> ai;
        total[ai]++;
    }
    int i=0, cnt=0;
    while (i < n) {
        switch (a[i]) {
            case 1:
                total[1]--;
                if (total[3] >= 1) {
                    pass[3]++;
                    total[3]--;
                    break;
                } else if (total[1] >= 1 && total[2] >= 1) {
                    pass[1]++;
                    pass[2]++;
                    total[1]--;
                    total[2]--;
                    break;
                } else if (total[1] >= 3) {
                    pass[1] += 3;
                    total[1] -= 3;
                    break;
                }
            case 2:
                if (a[i] == 2) total[2]--;
                if (total[2] >= 1) {
                    pass[2]++;
                    total[2]--;
                    break;
                } else if (total[1] >= 2) {
                    pass[1] += 2;
                    total[1] -= 2;
                    break;
                }
            case 3:
                if (a[i] == 3) total[3]--;
                if (total[1] >= 1) {
                    pass[1]++;
                    total[1]--;
                }
                break;
            case 4:
                total[4]--;
                break;
        }
        i++;
        while (i < n && pass[a[i]] > 0) {
            pass[a[i]]--;
            i++;
        }
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
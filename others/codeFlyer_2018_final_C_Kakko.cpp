#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    long h = 0, sum = 0;
    long heights[100010] = {0};
    heights[0] = 1;
    for (auto c:s) {
        switch (c) {
            case '(': {
                h++;
                heights[h] = 1;
                break;
            }
            case ')': {
                if (h > 0) {
                    h--;
                    sum += heights[h];
                    heights[h]++;
                } else
                    heights[0] = 1;
            }
        }
    }
    cout << sum << '\n';
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    cin >> s;
    char prev='\0';
    bool two = true, err = false;
    int cnt=0;
    for (auto c:s) {
        if (err) {
            cnt++;
            two = true;
            err = false;
        }
        else if (two || c != prev) {
            cnt++;
            two = false;
        }
        else {
            err = true;
        }
        prev = c;
    }
    cout << cnt << '\n';
    return 0;
}
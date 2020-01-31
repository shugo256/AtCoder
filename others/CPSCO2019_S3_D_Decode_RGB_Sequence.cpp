#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    char prev='\0';
    if (s[0] != 'R' || s[n-1] != 'B') {
        cout << "No" << '\n';
        return 0;
    }
    for (auto c:s) {
        if ((c == 'G' && prev == 'G') || (c == 'B' && prev == 'R')) {
            cout << "No" << '\n';
            return 0;
        }
        prev = c;
    }
    cout << "Yes" << '\n';
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int a = (s[0] - '0') * 10 + (s[1] - '0'),
        b = (s[2] - '0') * 10 + (s[3] - '0');
    if (0 < a && a <= 12 && 0 < b && b <= 12) cout << "AMBIGUOUS" << '\n';
    else if (0 < a && a <= 12) cout << "MMYY" << '\n';
    else if (0 < b && b <= 12) cout << "YYMM" << '\n';
    else cout << "NA" << '\n';
    return 0;
}

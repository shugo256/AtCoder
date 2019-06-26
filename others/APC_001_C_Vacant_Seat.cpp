#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "hello world!", prev;
    int a = 0, b = n, c = n/2, prevc=0;
    cout << a << endl;
    cin >> prev;
    s = prev;
    while (s != "Vacant") {
        cout << c << endl;
        cin >> s;
        if ((prev == s) xor (a%2 == c%2)) {
            b = a;
            a = c;
        } else
            a = c;
        prevc = c;
        c = (a+b) / 2;
        prev = s;
    }
    return 0;
}
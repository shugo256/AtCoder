#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    size_t len = s.length(), i=0;
    while (len-i >= 5) {
        if (len-i >= 7 && s.substr(i,7) == "dreamer" && (len-i < 10 || s.substr(i+7,3) != "ase")) {
            i += 7;
        } else if (len-i >= 6 && s.substr(i,6) == "eraser" && (len-i < 9 || s.substr(i+6,3) != "ase")) {
            i += 6;
        } else if (s.substr(i,5) == "dream" || s.substr(i,5) == "erase") {
            i += 5;
        } else {
            break;
        }
    }
    if (len == i) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
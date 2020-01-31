#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    int cnt=0;
    string s; cin >> s;
    for (auto c:s) 
        if (c == 'x')cnt++;
    cout << (cnt < 8 ? "YES" : "NO") << '\n';
    return 0;
}

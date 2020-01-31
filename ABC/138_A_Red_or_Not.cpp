#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int a;
    string s;
    cin >> a >> s;
    cout << (a >= 3200 ? s : "red") << '\n';
    return 0;
}
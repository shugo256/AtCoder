#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(b + c - a, 0) << '\n';
    return 0;
}
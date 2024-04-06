#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << max({a+b, a-b, a*b}) << '\n';
    return 0;
}
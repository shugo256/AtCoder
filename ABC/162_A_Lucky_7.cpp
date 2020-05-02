#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string n;
    cin >> n;
    cout << (n[0] == '7' || n[1] == '7' || n[2] == '7' ? "Yes" : "No") << '\n';
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    char a;
    cin >> a;
    cout << ('a' <= a && 'z' >= a ? 'a' : 'A') << '\n';
    return 0;
}
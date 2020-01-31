#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    cout << (n-1) / (2*d+1) + 1 << '\n';
    return 0;
}
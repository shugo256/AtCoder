#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cout << (k > 1 ? n - k : 0) << '\n';
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        long a, b;
        cin >> a >> b;
        cout << a * b << '\n';
    }
    return 0;
}

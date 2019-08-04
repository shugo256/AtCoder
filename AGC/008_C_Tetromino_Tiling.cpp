#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long I, O, T, J, L, S, Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;
    long ijl = 0;
    if ((I%2 + J%2 + L%2)%3 > 0) {
        if (I * J * L == 0) ijl = (I % 2 + J % 2 + L % 2) % 3;
        else ijl = 1;
    }
    cout << I + O + J + L - ijl << '\n';
    return 0;
}
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int a = 3, b = 1, c = 2, d;
    cout << (d = max(a, b), max(c, d)) << endl;
}
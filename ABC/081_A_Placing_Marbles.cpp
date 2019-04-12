#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int s, n=0;
    scanf("%d",&s);
    for (int i=100; i >= 1; i /= 10) {
        if (s / i == 1) {
            n += 1;
        }
        s = s%i;
    }
    cout << n << "\n";
}
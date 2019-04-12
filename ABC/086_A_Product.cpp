#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    string s;
    if ((a * b) % 2 == 0) {
        s = "Even";
    } else {
        s = "Odd";
    }
    cout << s << "\n";
}
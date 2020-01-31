#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int k, x;
    cin >> k >> x;
    for (int i=x-k+1; i<x+k; i++)
        cout << i << (i < x+k-1 ? ' ' : '\n');
    return 0;
}
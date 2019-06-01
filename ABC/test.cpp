#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    multiset<long> alist;
    alist.insert(1);
    auto first = alist.begin();
    alist.insert(0);
    cout << (first == alist.begin()) << '\n';
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    size_t len = s.size();
    cout << ((len % 2) xor (s[0] == s[len-1]) ? "First" : "Second") << '\n';
    return 0;
}
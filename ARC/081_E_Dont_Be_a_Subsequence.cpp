#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

int main() {
    string a;
    cin >> a;
    string cands[26];
    for (int i=0; i<26; i++)
        cands[i] = (char)('a' + i);
    
    int argmin = 0, _min;
    for (auto c:a) {
        cands[c-'a'] = cands[argmin] + c;
        _min = 2000000;
        for (int i=0; i<26; i++) {
            if (cands[i].size() < _min || (cands[i].size() == _min && cands[i] < cands[argmin])) {
                _min = cands[i].size();
                argmin = i;
            }
        }
    }
    cout << cands[argmin] << '\n';
    return 0;
}
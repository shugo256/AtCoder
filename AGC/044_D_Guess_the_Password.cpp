#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <numeric>

using ll = long long;

using namespace std;

string merge_two(string &s, string &t, int len) {
    string ans = s;
    auto itr = ans.begin();
    for (auto &ti:t) {
        for (itr = ans.insert(itr, ti) + 1; true; itr++) {
            cout << "? " << ans << endl;
            int resp; cin >> resp;
            if (len - resp == ans.size()) {
                break;
            }
            iter_swap(itr - 1, itr);
        }
    }
    return ans;
}

int main() {
    string chars(62, ' ');
    iota(chars.begin(), chars.begin() + 26, 'a');
    iota(chars.begin() + 26, chars.begin() + 52, 'A');
    iota(chars.begin() + 52, chars.end(), '0');
    int sum = 0;
    vector<string> parts;
    for (auto &c:chars) {
        cout << "? " << string(128, c) << endl;
        int len;
        cin >> len;
        len = 128 - len;
        sum += len;
        parts.push_back(string(len, c));
    }
    int n = parts.size();
    while (parts.size() > 1) {
        vector<string> buff;
        for (int i=0; i+1<n; i+=2) {
            buff.push_back(merge_two(parts[i], parts[i+1], sum));
        }
        if (n & 1) buff.push_back(parts.back());
        parts.swap(buff);
        n = parts.size();
    }
    cout << "! " << parts[0] << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;



int main() {
    string s, t;
    cin >> s >> t;
    long slen = s.size();
    long next[slen+1][26],
         buf[26];
    fill(buf, buf+26, -1);
    fill(next[slen], next[slen+1], -1);
    for (long i=slen-1; i>=0; i--) {
        buf[s[i]-'a'] = i+1;
        for (long j=0; j<26; j++) next[i][j] = buf[j];
    }
    long cnt=0, id=0;
    for (auto c:t) {
        if (next[0][c-'a'] < 0) {
            cout << "-1\n";
            return 0;
        }
        if (next[id][c-'a'] < 0) {
            cnt += slen;
            id = next[0][c-'a'];
        }
        else id = next[id][c-'a'];
    }
    cout << cnt + id << endl;
}
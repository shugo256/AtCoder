#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

using P = pair<int, int>;
#define fi first
#define se second


P check_lr(string &s) {
    int n = s.size();
    P ans;
    int left = 0, right = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') left++;
        if (s[i] == ')' && right < left) right++;
    }
    ans.se = left - right;
    left = 0, right = 0;
    for (int i=n-1; i>=0; i--) {
        if (s[i] == ')') right++;
        if (s[i] == '(' && left < right) left++;
    }
    ans.fi = right - left;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<P> lrs;
    P left_edge = {0, 0}, right_edge = {0, 0};
    int dif = 0, complete = 0;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        P lr = check_lr(s);
        lrs.push_back(lr);
    }
    sort(lrs.begin(), lrs.end(), [](P a, P b) {
        if (a.fi - a.se >= 0 && b.fi - b.se < 0) return false;
        else if (a.fi - a.se < 0 && b.fi - b.se >= 0) return true;
        else if (a.fi - a.se < 0 && b.fi - b.se < 0) {
            return a.fi < b.fi;
        } else {
            return a.se > b.se;
        }
    });
    int match = 0;
    for (auto &lri:lrs) {
        if  (match < lri.fi) {
            cout << "No" << '\n';
            return 0;
        }
        match -= lri.fi;
        match += lri.se;
    }
    cout << (match == 0 ? "Yes" : "No") << '\n';
    return 0;
}
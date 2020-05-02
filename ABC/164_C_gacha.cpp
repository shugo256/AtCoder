#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using ll = long long;

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> st;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }
    cout << st.size() << '\n';
    return 0;
}
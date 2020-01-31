#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

#define isOp(c)  (c == '+' || c == '-' || c == '*' || c == '/')

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (auto c:s) {
        if (isOp(c))
            st.push(c);
        else
            cout << (c == ',' ? st.top() : c);
        if (c == ')') st.pop();
    }
    cout << endl;
    return 0;
}
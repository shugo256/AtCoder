#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s; cin >> s;
    int cnt = 0, fore = 0;
    for (auto &c:s) {
        switch(c) {
            case 'a':
                if (cnt < a + b) {
                    cout << "Yes" << '\n';
                    cnt++;
                    break;
                }
            case 'b':
                if (fore < b && cnt < a + b) {
                    cout << "Yes" << '\n';
                    fore++;
                    cnt++;
                    break;
                }
            default:
                cout << "No" << '\n';
        }
    }
    return 0;
}
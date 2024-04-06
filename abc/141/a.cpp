#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using ll = long long;

using namespace std;

int main() {
    string s;
    cin >> s;
    map<string, string> m;
    m["Sunny"] = "Cloudy";
    m["Cloudy"] = "Rainy";
    m["Rainy"] = "Sunny";
    cout << m[s] << '\n';
    return 0;
}
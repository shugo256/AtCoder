#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)

using ll = long long;

int main() {
    int n;
    std::cin >> n;
    std::set<int> st;
    for (int i=0; i<200002; i++) st.insert(i);
    for (int i=0, pi; i<n; i++) {
        std::cin >> pi;
        st.erase(pi);
        std::cout << *st.begin() << '\n';
    }
    return 0;
}
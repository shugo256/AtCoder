#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    map<const string, int> m;
    int N, M;
    string s;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        cin >> s;
        m[s.substr()]++;
    }
    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        cin >> s;
        m[s.substr()]--;
    }
    int best=0;
    for (auto ite = m.begin(); ite != m.end(); ite++)
        best = max(best, ite->second);
    printf("%d\n", best);
    return 0;
}
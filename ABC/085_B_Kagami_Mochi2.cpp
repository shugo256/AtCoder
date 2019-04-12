#include <cstdio>
#include <set>

//setで秒殺したver

using namespace std;

int main() {
    int N, d;
    scanf("%d", &N);
    set<int> s;
    for (int i=0; i<N; i++) {
        scanf("%d", &d);
        s.insert(d);
    }
    printf("%ld\n", s.size());
    return 0;
}
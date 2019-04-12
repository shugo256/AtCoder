#include <cstdio>

using namespace std;

int main() {
    int T, N;
    scanf("%d", &T);
    for (int i=1; i<=T; i++) {
        scanf("%d\n", &N);
        bool first = (getchar() == 'E'), prev = false, done = false;
        int j, count = 0, dir = first ? 'E' : 'S', opp = first ? 'S' : 'E';
        for (j=0; j<2*(N-2); j++) {
            int c = getchar();
            if (done) continue;
            if (c == opp) {
                if (prev) done = true;
                else prev = true;
                count++;
            } else prev = false;
        }
        count--;
        bool last = (getchar() == 'E');
        printf("Case #%d: ", i);
        if (first == last) {
            for (j=0; j<count; j++) printf("%c", opp);
            for (j=0; j<N-1; j++) printf("%c", dir);
            for (j=count; j<N-1; j++) printf("%c", opp);
        } else {
            for (j=0; j<N-1; j++) printf("%c", opp);
            for (j=0; j<N-1; j++) printf("%c", dir);
        }
        printf("\n");
    }
    return 0;
}
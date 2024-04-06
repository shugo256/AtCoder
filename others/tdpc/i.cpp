#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    bool i = false;
    int c, icount=0, wcount=0, sum=0;
    while ((c = getchar()) == 'w');
    while (c == 'i' || c == 'w') {
        if (!i && c == 'w') {
            sum += min(icount/2, wcount-1);
            icount = 0; wcount = 0;
            while ((c = getchar()) == 'w');
        } else {
            i = (c == 'i');
            if (i) {
                icount++;
                int set = min(icount/2, wcount);
                icount -= 2 * set; wcount -= set;
                sum += set;
            } else wcount++;
            c = getchar();
        }
    }
    printf("%d\n", sum);
    return 0;
}
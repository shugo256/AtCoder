#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    char b;
    scanf("%c", &b);
    switch (b) {
        case 'A':
            printf("T\n"); break;
        case 'C':
            printf("G\n"); break;
        case 'G':
            printf("C\n"); break;
        case 'T':
            printf("A\n"); break;
    }
    return 0;
}
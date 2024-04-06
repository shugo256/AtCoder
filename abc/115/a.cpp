#include <cstdio>

int main() {
    int D;
    scanf("%d",&D);
    switch(D) {
        case 25:
            printf("Christmas\n");
            break;
        case 24:
            printf("Christmas Eve\n");
            break;
        case 23:
            printf("Christmas Eve Eve\n");
            break;
        case 22:
            printf("Christmas Eve Eve Eve\n");
            break;
    }
    return 0;
}
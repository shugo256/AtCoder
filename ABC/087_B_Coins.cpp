#include <cstdio>

int main() {
    int A,B,C,X,i,j,n=0;
    scanf("%d\n%d\n%d\n%d",&A,&B,&C,&X);
    int Xa,Xb,Xc;
    Xa = X/500;
    for (i=0; i <= A && i <= Xa; i++) { //まず500円玉の枚数決める
        Xb = (X - 500*i) / 100;
        for (j=0; j <= B && j <= Xb; j++) {
            Xc = (X - 500*i - 100*j) / 50;
            if (C >= Xc) {
                n += 1;
            }
        }
    }
    printf("%d\n",n);
}
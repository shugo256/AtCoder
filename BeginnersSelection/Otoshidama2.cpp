#include <cstdio>

//改良版 (ガチプロのをパクった)

int main() {
    int N,Y;
    scanf("%d %d",&N,&Y);
    int x,y,z,yen;
    yen = Y/1000;
    x = yen/10;
    y = (yen%10)/5;
    z = (yen%10)%5;
    N -= x+y+z; //Nは最小でx+y+z
    while (N > 0 && x >= 0) {
        if (N >= 9 && x >= 1) {
        //10000円札->1000円札    
            x -= 1;
            z += 10;
            N -= 9;
        } else if (N >= 4 && y >= 1) {
        //5000円札->1000円札
            y -= 1; 
            z += 5;
            N -= 4;
        } else {      
        //10000円札->5000円札
            x -= 1;
            y += 2;
            N -= 1;
        }
    }
    if (N == 0 && x >= 0)
        printf("%d %d %d\n",x,y,z);
    else
        printf("-1 -1 -1\n");
}
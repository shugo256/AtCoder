#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

//改良版 俺天才

int main() {
    char s[11];
    scanf("%s",s);
    int len = (int)strlen(s);
    long long result=0, sum=0;
    for (int cut1=0; cut1 < len; cut1++) {
        sum = 0;
        for (int cut2=cut1+1; cut2 <= len; cut2++) {
            sum = 10*sum + (s[cut2-1]-'0');
            result += sum * pow(2,max(len-1-cut2,0)+max(cut1-1,0));
        }
    }
    printf("%lld\n",result);
    return 0;
}
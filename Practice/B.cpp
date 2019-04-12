//N=5 の時マージソートはMAX8回ひつようなので、Q=7でたまにミスる
#include <cstdio>
#include <string>
using namespace std;


string merge(string a, string b) {
    char ans;
    if (a.length() == 0) {
        return b;
    } else if (b.length() == 0) {
        return a;
    } else {
        printf("? %c %c\n", a[0],b[0]);
        fflush(stdout);
        scanf(" %c", &ans);
        if (ans == '<') {
            return a[0] + merge(a.substr(1),b);
        } else {
            return b[0] + merge(b.substr(1),a);
        }
    }
}

string mergesort(string s) {
    size_t l = s.length();
    if (s.length() <= 1) {
        return s;
    } else {
        return merge(mergesort(s.substr(0,l/2)), mergesort(s.substr(l/2)));
    }
}

int main() {
    int N, Q, i;
    scanf("%d %d", &N, &Q);
    string s;
    for (i=0; i<N; i++) s += (char)('A' + i);
    printf("! %s\n", mergesort(s).c_str());
    return 0;
}